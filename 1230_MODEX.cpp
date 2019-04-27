/*
Author : Aman Sharma
email  : iamamansharma@live.com
solution: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3671
*/
#include<iostream>

using namespace std;

#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define ull unsigned long long
#define forn(i, a, b) for(ll i=a; i<b; ++i)

ll binpow_mod(ll a, ll b, ll m){
	ll result = 1;
	a = a%m;
	while(b){
		if(b&1)
			result = result * a % m;
		a = a * a % m;
		b = b>>1;
	}
	return result;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		ll a, b, m;
		cin>>a>>b>>m;
		cout<<binpow_mod(a, b, m)<<endl;
	}
	cin>>t;
	return 0;
}