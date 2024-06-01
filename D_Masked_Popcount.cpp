#include<bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int main() {
    uint64_t N, M;
    cin >> N >> M;
    
    uint64_t result = 0;
    
    for (int bit = 0; bit < 60; ++bit) {
        uint64_t bitValue = 1ULL << bit;
        uint64_t fullSets = (N + 1) / (bitValue * 2);
        uint64_t remainder = (N + 1) % (bitValue * 2);

        uint64_t countSetBits = fullSets * bitValue + max(0ULL, remainder - bitValue);

        if (M & bitValue) {
            result = (result + countSetBits) % MOD;
        }
    }
    
    cout << result << endl;
    
    return 0;
}
