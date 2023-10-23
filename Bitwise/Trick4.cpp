//Toggle the kth bit
//x=8 and k=0 ->8(1000)^(0001)->9
#include<iostream>
using namespace std;
int main(){
  int x,k;
  cin>>x;
  cout<<"Enter the bit you want to toggle(0-based indexing right to left)  "<<endl;
  cin>>k;
  int ans=x^(1<<k);
  cout<<ans<<endl;
  return 0;
}
