#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s,t;
        cin>>s>>t;
        int n=s.length(),m=t.length();
        int l=(n*m)/__gcd(n,m);
        string s1="",s2="";
        for(int i=0;i<l/n;i++){
            s1+=s;
        }
        for(int i=0;i<l/m;i++){
            s2+=t;
        }
        if(s1==s2){
            cout<<s1<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
return 0;}
