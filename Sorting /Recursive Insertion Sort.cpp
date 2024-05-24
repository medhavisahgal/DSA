#include<bits/stdc++.h>
using namespace std;
void insertionSort(int a,int st,int n){
    if(st==n)return;
    int r=st;
    while(r>0&&a[r-1]>a[r]){
        int temp=a[r-1];
        a[r-1]=a[r];
        a[r]=temp;
        r--;
    }
    insertionSort(arr,st+1,n);

}
int main(){
    int a[6]= {9,5,3,1,2,4};
    int n=6;

    insertionSort(a,0,n);
    for(int i=0; i<6; i++)
    {
        cout<<a[i]<<" ";
    }
}
