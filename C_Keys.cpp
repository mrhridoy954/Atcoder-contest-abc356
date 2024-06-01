#include<bits/stdc++.h>
using namespace std;

bool isValidCombination(int combination, int N, int K,
 const vector<vector<int>>& tests, const vector<char>& results)
  {
    for (int i = 0; i < tests.size(); ++i) 
    {
        int count = 0;
        for (int key : tests[i])
         {
            if (combination & (1 << (key - 1))) { 
                count++;
            }
        }
        if ((results[i] == 'o' && count < K) || (results[i] == 'x' && count >= K))
         {
            return false;
        }
    }
    return true;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> tests(M);
    vector<char> results(M);

    for (int i = 0; i < M; ++i) {
        int C;
        cin >> C;
        tests[i].resize(C);
        for (int j = 0; j < C; ++j) {
            cin >> tests[i][j];
        }
        cin >> results[i];
    }

    int validCombinations = 0;
    
    for (int combination = 0; combination < (1 << N); ++combination)
    
     {
        if (isValidCombination(combination, N, K, tests, results)) 
        
        {
            validCombinations++;
        }
    }

    cout << validCombinations << endl;

    return 0;
}
