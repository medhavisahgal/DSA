// the greatest common divisor (GCD) of two or more integers, which are not all zero, is the largest positive integer that divides each of the integers(divides the two number exactly)
#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}
int main()
{
	int a,b;
  cin>>a>>b;
	cout <<"The GCD of the two numbers is "<<gcd(a, b);
}
//recursive apporach 
//uses the concept of long division that we learnt in our school
