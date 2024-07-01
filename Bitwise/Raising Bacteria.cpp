#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int x;
    cin>>x;
    bitset<64>b(x);
    int ans=b.count();
    cout<<ans<<endl;
    return 0;
}