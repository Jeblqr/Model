#include <iostream>
using namespace std;
long long qp(long long a, long long b, long long k) {
  long long ans = 1;
  while (b) {
    if (b & 1)
      ans = ans * a % k;
    a = a * a % k;
    b >>= 1;
  }
  return ans;
}
long long qp(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1)
      ans = ans * a;
    a = a * a;
    b >>= 1;
  }
  return ans;
}
int main() {
  long long a, b, k;
  cin >> a >> b >> k;
  cout << qp(a, b) << endl << qp(a, b, k) << endl;
  return 0;
}
