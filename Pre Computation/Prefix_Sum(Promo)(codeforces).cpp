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
    //p[n]=[1,2,3,4,5]
    for(int i=0; i<n; i++)
    {
        pf[i+1]=pf[i]+p[i];
    }
    //pf[1]=pf[0]-->(0)+p[0]-->1
    //pf[1]=1
    //pf[2]=pf[1]-->1+p[1]-->2
    //pf[2]=3
    //pf[3]=pf[2]-->3+p[2]-->3
    //pf[3]=6
    //so on pf[n+1]=[0,1,3,6,10,15] 
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<pf[n-(x-y)]-pf[n-x]<<endl;
        //pf[5-(3-2)]-pf[5-3]
        //pf[4]-pf[2]=6-3-->3
    }
    return 0;
}
