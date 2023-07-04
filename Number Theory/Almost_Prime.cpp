#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, c = 0;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        int num=i;
        set<int> s2;
        for (int j = 2; j * j <= num; j++)
        {
            while (num % j == 0)
            {
                s2.insert(j);
                num /= j;
            }
        }
        if (num > 1)
        {
            s2.insert(num);
        }
        if (s2.size()==2)
        {
            c++;
        }
    }
    cout << c << endl;
    return 0;
}
