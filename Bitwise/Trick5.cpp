//set the kth bit
//x=4 and k=0
//eg 4(0100)|(0001)->(0101)5
#include<iostream>
using namespace std;
int main(){
  int x,k;
  cin>>x;
  cout<<"Choose bit you want to select (Zero based indexing )"<<endl;
  cin>>k;
  int ans=x|(1<<k);
  cout<<ans<<endl;
  return 0;
}
