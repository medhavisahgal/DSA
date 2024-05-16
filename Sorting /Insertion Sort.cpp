#include<bits/stdc++.h>
using namespace std;
int main()
{
  //In this you have to select the element and put them at the correct position 
    int n=5;
    vector<int>a(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cout<<endl;
    for(int i=0; i<n; i++)
    {
        int j=i;
        while(j>0&&a[j-1]>a[j])
        {
            swap(a[j],a[j-1]);
            j--;
        }
    }
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    //-----------Time Complexity----------------
    //               O(n^2)
    //-----------Space Complexity----------------
    //               O(1)
}
