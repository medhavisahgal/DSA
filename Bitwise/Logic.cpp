#include<isotream>
using namespace std;
int main(){
    int a=4;
    int b=2;
    cout<<"a&b:"<<(a&b)<<"\n";
    cout<<"a|b:"<<(a|b)<<"\n";
    cout<<"a^b:"<<(a^b)<<"\n";
    cout<<"~b:"<<(~b)<<"\n";
    cout<<"a<<b:"<<(a<<b)<<"\n";
    cout<<"a>>b:"<<(a>>b)<<"\n";
    //1)(4)=(0100)&(2)=(0010)=0
    //2)(4)|(2)=6
    //3)(4)^(2)=6//XOR
    //4)(~b)=not(111..101)(MSB=1 that means (-ve)->1s(0000...10)->2s(00000...0011)=-3//NOT
    //5)Left shift << (4)(0000...100)->(000...1000)eg(4<<2)==(00000...10000)
    //6)Right shift >>(4)(0000..100)->(000...100)eg(4<<2)==(0000...0001) 
    return 0;
}
