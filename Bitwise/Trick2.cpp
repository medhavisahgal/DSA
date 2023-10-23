//check if the number in 2's power
#include<iostream>
using namespace std;
bool power2s(int x){
  return x && !(x&x-1);
}
//this function also manages the edge case of 0
int main(){
  int x;
  cin>>x;
  bool ans=power2s(x);
  if(ans){
    cout<<"Yes "<<x<<" is a power of 2"<<endl;
  }
  else{
    cout<<"No it is not a power of 2"<<endl;
  }
  return 0;
}
