#include<bits/stdc++.h>
using namespace std;

struct Style {
    long long stamina;
    long long distance;
    double efficiency;
};

bool can_swim(double time, long long D, long long C, const vector<Style>& styles) {
    double total_distance = 0;
    double total_stamina = 0;
    for (const auto& style : styles) {
        double t = min(time, (C - total_stamina) / style.stamina);
        total_distance += t * style.distance;
        total_stamina += t * style.stamina;
        if (total_distance >= D) return true;
    }
    return total_distance >= D;
}

int main() {
    int N, Q;
    cin >> N;

    vector<Style> styles(N);
    for (int i = 0; i < N; ++i) {
        cin >> styles[i].stamina >> styles[i].distance;
        styles[i].efficiency = static_cast<double>(styles[i].distance) / styles[i].stamina;
    }

    cin >> Q;
    vector<pair<long long, long long>> queries(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> queries[i].second >> queries[i].first; // C, D
    }

    sort(styles.begin(), styles.end(), [](const Style& a, const Style& b) {
        return a.efficiency > b.efficiency;
    });

    constexpr double EPS = 1e-9;
    constexpr double INF = 1e18;

    for (const auto& [D, C] : queries) {
        double low = 0.0, high = INF;
        while (high - low > EPS) {
            double mid = (low + high) / 2.0;
            if (can_swim(mid, D, C, styles)) {
                high = mid;
            } else {
                low = mid + EPS;
            }
        }
        if (high >= INF) {
            cout << -1 << '\n';
        } else {
            cout.precision(18);
            cout << fixed << high << '\n';
        }
    }

    return 0;
}
