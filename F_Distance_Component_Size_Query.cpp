#include<bits/stdc++.h>
using namespace std;

class UnionFind {
public:
    unordered_map<long long, long long> parent;
    unordered_map<long long, int> size;

    long long find(long long x) {
        if (parent.find(x) == parent.end()) {
            parent[x] = x;
            size[x] = 1;
        }
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(long long x, long long y) {
        long long rootX = find(x);
        long long rootY = find(y);

        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }

    int componentSize(long long x) {
        return size[find(x)];
    }
};

int main() {
    int Q;
    long long K;
    cin >> Q >> K;

    UnionFind uf;
    unordered_set<long long> S;

    for (int i = 0; i < Q; ++i) {
        int type;
        long long x;
        cin >> type >> x;

        if (type == 1) {
            if (S.find(x) != S.end()) {
                S.erase(x);
                for (long long neighbor = x - K; neighbor <= x + K; ++neighbor) {
                    if (neighbor != x && S.find(neighbor) != S.end()) {
                        uf.unite(x, neighbor);
                    }
                }
            } else {
                S.insert(x);
                // Union x with its neighbors
                for (long long neighbor = x - K; neighbor <= x + K; ++neighbor) {
                    if (neighbor != x && S.find(neighbor) != S.end()) {
                        uf.unite(x, neighbor);
                    }
                }
            }
        } else if (type == 2) {
            cout << uf.componentSize(x) << endl;
        }
    }

    return 0;
}
