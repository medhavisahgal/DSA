#include<bits/stdc++.h>
using namespace std;
int main()
{
    //In this you just have to find smaller and swap 
    int n=5;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        bool flag=false;
        for(int j=0;j<n-1;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                flag=true;
            }
        }
        if(!flag){
            break;
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    //-----------Time Complexity----------------
    //               O(n^2)
    //-----------Space Complexity---------------
    //               O(1) 
}
