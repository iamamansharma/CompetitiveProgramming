/*
if a, b are non-negative 
When one of the numbers is zero, while the other is non-zero, 
their greatest common divisor, by definition, is the second number. 
When both numbers are zero, their greatest common divisor is 
undefined (it can be any arbitrarily large number), but we can 
define it to be zero. Which gives us a simple rule: if one of 
the numbers is zero, the greatest common divisor is the other number.

time complexity : O(log(min(a, b)))
*/

#include<iostream>
#include<algorithm>

using namespace std;

int gcd(int a, int b){
	if(b==0)
		return a;
	return gcd(b, a%b);
}
// int gcd(a, b){ return b?gcd(b, a%b): a;}


int gcd_non_recursion(int a, int b){
	while(b){
		a = a%b;
		swap(a, b);
	}
	return a;
}



int main()
{
	int a, b;
	cin>>a>>b;
	cout<<gcd(a, b)<<endl;
	cout<<gcd_non_recursion(a, b)<<endl;
	return 0;
}