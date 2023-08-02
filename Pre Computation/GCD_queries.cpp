#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
      //3 3
        int a[n];
        int forward[n+1];
      //forward[4]
        int backward[n+1];
      //backword[4]
        forward[0]=backward[n+1]=0;
      //forward[0]=0 backward[4]=0
        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
        }
      //a[n]=[0,2,6,9]
        for(int i=1;i<=n;i++){
            forward[i]=__gcd(forward[i-1],a[i]);
          //forward[1]=gcd(0,2)=2
          //forward[2]=gcd(2,6)=2
          //forward[3]=gc(2,9)=2
        }
      //forward[4]=[0,2,2,2]
        for(int i=n;i>=1;i--){
            backward[i]=__gcd(backward[i+1],a[i]);
          //backward[3]=gcd(0,9)=9
          //backward[2]=gcd(9,6)=3
          //backward[1]=gcd(3,2)=1
        }
      //backward[n+1]=[0,1,3,9]
        while(q--)
        {
            int l,r;
          //1 1
          //2 2
          //2 3
            cin>>l>>r;
           cout<<__gcd(forward[l-1],backward[r+1])<<endl;
          //gcd(forward[0],backward[2])=gcd(0,3)=3
          //gcd(forward[1],backward[3])=gcd(2,9)=1
          //gcd(forward[1],backward[4])=gcd(2,0)=2
        }
    }
    return 0;
}
