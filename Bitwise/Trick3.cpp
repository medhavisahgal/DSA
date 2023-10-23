//check if the kth bit is set or not from right to left (LSB)
//x=4 and no=1-> (4)=(0100)&(0010)->0 Not Set 
//x=4 and no=2 ->(4)=(0100)&(0100)->1 Set Bit
#include<iostream>
using namespace std;
bool bitcheck(int x,int no){
  return x & (1<<no);
}
int main(){
  int x,no;
  cin>>x;
  cout<<"which bit you want to check(zero based indexing )"<<"\n";
  cin>>no;
  bool ans=bitcheck(x,no);
  if(ans){
    cout<<"Set bit"<<endl;
  }
  else{
    cout<<"Not Set"<<endl;
  }
  return 0;
}
