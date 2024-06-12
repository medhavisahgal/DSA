#include<bits/stdc++.h>
using namespace std;
int partition(vector<int> &a,int low,int high)
{
    int pivot=a[low];
    int i=low;
    int j=high;
    while(i<j)
    {
        while(a[i]<=pivot&&i<=high-1)
        {
            i++;
        }
        while(a[j]>pivot&&j>=low+1)
        {
            j--;
        }
        if(i<j)swap(a[i],a[j]);
    }
    swap(a[low],a[j]);
    return j;
}
void qs(vector<int> &a,int low,int high)
{
    if(low<high)
    {
        int pi=partition(a,low,high);
        qs(a,low,pi-1);
        qs(a,pi+1,high);
    }
}
int main()
{
    vector<int>a= {4,6,2,7,9,1,3};
    int n=a.size();
    cout<<"Before Sorting"<<endl;
    for(int i=0; i<n; i++)cout<<a[i]<<" ";
    cout<<endl;
    qs(a,0,n-1);
    cout<<"After Sorting"<<endl;
    for(int i=0; i<n; i++)cout<<a[i]<<" ";
}
