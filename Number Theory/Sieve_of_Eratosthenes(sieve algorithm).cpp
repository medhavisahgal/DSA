#include<bits/stdc++.h>
using namespace std;
//starting assumption 1->N all are prime
int main()
{
    int N;
    cin>>N;
    vector<bool>isPrime(N+1,true);
    //we don't consider 0 and 1
    isPrime[0]=isPrime[1]=false;
    for(int i=2; i*i<=N; i++)
    {
        if(isPrime[i]==true)
        {
            //j=2*2=4;j<=N ;j+=2 (4,6,8....)
            for(int j=2*i; j<=N; j+=i)
            {
                isPrime[j]=false;
            }
        }
    }
    for(int i=2; i<=N; i++)
    {
        if(isPrime[i]==true)
        {
            cout<<i<<" ";
        }
    }
    return 0;
}
//time complexity O(Nlog(log(N)))
//proved using higher mathematics(taylor series..)
