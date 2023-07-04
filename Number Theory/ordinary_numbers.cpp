#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,ans=0;
        cin>>n;
        for(int i=1; i<=9; i++)
        {
            long long int j=i;
            while(j<=n)
            {
                ans++;
                j=j*10+i;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
