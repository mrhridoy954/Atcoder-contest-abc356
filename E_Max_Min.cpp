#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> A(n);
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }

  long long total_sum = 0;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      // Find max(A[i], A[j]) and min(A[i], A[j])
      int max_element = max(A[i], A[j]);
      int min_element = min(A[i], A[j]);

      // Calculate floor(max_element * min_element) efficiently
      total_sum += (long long)min_element * (max_element / min_element);

      // Add the remainder if max_element is not divisible by min_element
      if (max_element % min_element != 0) {
        total_sum += min_element;
      }
    }
  }

  cout << total_sum << endl;

  return 0;
}
