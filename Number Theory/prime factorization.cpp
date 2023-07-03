#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> prime_factor;
  //if a number is a composite number
    for (int i = 2; i <= sqrt(n) ; i++) {
        while (n % i == 0) {
            prime_factor.push_back(i);
            n /= i;
        }
    }
  //if a number is a prime number
    if (n > 1) {
        prime_factor.push_back(n);
    }
    for (int i = 0; i < prime_factor.size(); i++) {
        cout << prime_factor[i] << " ";
    }
    return 0;
}
