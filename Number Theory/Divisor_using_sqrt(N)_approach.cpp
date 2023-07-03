#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, ct = 0, sum = 0;
    cin >> n;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cout << i <<" "<< n/i <<endl;
            ct++;
            sum += i;

            if (n / i != i)
            {
                sum += n / i;
                ct++;
            }
        }
    }
    cout << "No. of divisors: " << ct << endl;
    cout << "Sum of divisors: " << sum << endl;
    return 0;
}
//time complexity=O(sqrt(N))
//not that fast for bigger numbers
