#include<bits/stdc++.h>
using namespace std;
void bubblesort(int a[],int n)
{
    if(n==1)
    {
        return;
    }
    for(int j=0; j<n-1; j++)
    {
        if (a[j] > a[j + 1])
        {
            int temp = a[j + 1];
            a[j + 1] = a[j];
            a[j] = temp;
        }
    }
    bubblesort(a,n-1);
}
int main()
{
    int a[6]= {9,5,3,1,2,4};
    int n=6;
    bubblesort(a,n);
    for(int i=0; i<6; i++)
    {
        cout<<a[i]<<" ";
    }
}
