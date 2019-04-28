/*
Author : Aman Sharma
email  : iamamansharma@live.com
solution: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=310
*/
#include<iostream>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define forn(i, a, b) for(ll i=a; i<b; ++i)

ll solution(ll b, ll p, ll m){
	ll result = 1;
	b = b%m;
	while(p){
		if(p&1)
			result = result * b % m;
		b = b * b % m;
		p = p>>1;
	}
	return result;
}



int main(int argc, char const *argv[])
{
	fast;
	ll b, p, m;
	while(scanf("%lld %lld %lld", &b, &p, &m) == 3){
		cout<<solution(b, p, m)<<endl;
	}
	return 0;
}