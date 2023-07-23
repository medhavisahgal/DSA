#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,q;
    cin>>n>>q;
    long long int p[n],pf[n+1];
    for(int i=0; i<n; i++)
    {
        cin>>p[i];
    }
    sort(p,p+n);
    for(int i=0; i<n; i++)
    {
        pf[i+1]=pf[i]+p[i];
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<pf[n-(x-y)]-pf[n-x]<<endl;
    }
    return 0;
}
