//check if the number is even or odd
//They are much faster then normal operations
//eg (3)=(0011)&(0001)==(0001)=True
#include<iostream>
using namespace std;
int main(){
  int a;
  cin>>a;
  // if(a%2==0){
  //   court<<"Even"<<endl;
  // }
  // else{
  //   cout<<"odd"<<endl;
  // }
  //-----Instead Do this ---
  if(a&1){
    cout<<"ODD"<<endl;
  }
  else{
    cout<<"EVEN"<<endl;
  }
  return 0;
}
