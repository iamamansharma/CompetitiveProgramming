/*
Author: Aman Sharma
email : iamamansharma@live.com
*/

/*
Binary exponentiation (also known as exponentiation by squaring) is a trick
which allows to calculate an using only O(logn) multiplications (instead of O(n)
multiplications required by the naive approach).
*/

/*
Algorithm

Raising a to the power of n is expressed naively as multiplication by a done n−1 times: 
an=a⋅a⋅…⋅a. However, this approach is not practical for large a or n.

a^(b+c)=a^b⋅a^c and a^(2b)=a^b⋅a^b=(a^b)^2.

The idea of binary exponentiation is, that we split the work using the binary 
representation of the exponent.

Let's write 'n' in base 2, for example: 
3^13 = 3^(1101) = 3^8 . 3^4 . 3^1

(13)dec = (1101)bin

'n' has exactly log2(n) + 1 digits in base 2.
so, we only need to perform O(log(n)) multiplications, if we know 
the powers a^1, a^2, a^4, a^8, .., a^(log(n)).

So we only need to know a fast way to compute those. Luckily this is very easy, 
since an element in the sequence is just the square of the previous element.

3^1 = 3 
3^2 = (3^1)^2 = 3^2 = 9 
3^4 = (3^2)^2 = 9^2 = 81 
3^8 = (3^4)^2 = 81^2 = 6561

so to get final answer 3^13 , we only need ot multiply three of them
(skipping 3^2 as bit is not set):
3^13 = 6561 . 81 . 3 = 1594323

The final complexity of this algorithm is O(logn): we have to compute logn 
powers of a, and then have to do at most logn multiplications to get the final answer from them.

*/

#include<iostream>

using namespace std;

#define ll long long
#define endl '\n'

// recursive formula
ll binpow(ll a, ll b){
	if(!b) // if n==0 then a^0 is 1
		return 1;
	ll res = binpow(a, b/2);
	if(b&1)
		return res*res*a; // for odd value of n -> a^((n-1)/2)^2 . a
	return res*res; // for even value of n -> a^(n/2)^2
}


ll binpow_without_recursion(ll a, ll b){ // faster than previous
	ll res = 1;
	while(b){
		if(b&1)
			res = res*a;
		a *= a;
		b >>= 1;
	}
	return res;
}


/* Applications :
1. Effective computation of large exponents modulo a number
Problem: Compute (x^n)mod(m). This is a very common operation. For instance it 
is used in computing the modular multiplicative inverse.

Solution: Since we know that the module operator doesn't interfere with multiplications 
(a⋅b≡(a mod m)⋅(b mod m)(mod m)), we can directly use the same code, and just replace 
every multiplication with a modular multiplication
Note: If m is a prime number we can speed up a bit this algorithm by calculating x^(n mod(m−1)) 
instead of xn. This follows directly from Fermat's little theorem.
*/

ll bin_pow_mod(ll a, ll b, ll m){
	a %= m;
	ll res = 1;
	while(b){
		if(b&1)
			res = res*a%m;
		a = a*a%m;
		b = b>>1;
	}
	return res;
}

int main(int argc, char const *argv[])
{
	ll a, b;
	cin>>a>>b;
	ll m;
	cin>>m;
	cout<<binpow(a, b)<<endl;
	cout<<binpow_without_recursion(a, b)<<endl;
	cout<<bin_pow_mod(a, b, m)<<endl;
	return 0;
}