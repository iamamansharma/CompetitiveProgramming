/*
A Linear Diophantine Equation (in two variables) is an equation of the general form:

ax+by=c

where a
, b, c are given integers, and x, y are unknown integers.



A degenerate case that need to be taken care of is when a=b=0. 
It is easy to see that we either have no solutions or infinitely many solutions.
*/


/*
Finding a Solution:


To find one solution of the Diophantine equation with 2 unknowns, 
you can use the extended Euclidean algorithm. First, assume that a and b 
are non-negative. When we apply extended Euclidean algorithm for a and b, 
we can find their greatest common divisor g and 2 numbers xg and yg

such that:

a.xg+b.yg=g

If c
is divisible by g=gcd(a,b)

, then the given Diophantine equation has a solution, otherwise it does not have any solution. The proof is straight-forward: a linear combination of two numbers is divisible by their common divisor.

Now supposed that c
is divisible by g

, then we have:

a⋅xg⋅cg+b⋅yg⋅cg=c

Therefore one of the solutions of the Diophantine equation is:

x0=xg⋅cg,
y0=yg⋅cg.

The above idea still works when a
or b or both of them are negative. We only need to change the sign of x0 and y0 when 
necessary.
*/

#include<iostream>

using namespace std;


int gcd(int a, int b, int &x, int &y){
	if(a==0){
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = gcd(b%a, a, x1, y1);
	x = y1 - (b/a) * x1;
	y = x1;
	return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g){
	g = gcd(abs(a), abs(b), x0, y0);
	if(c%g)
		return false;
	x0 = x0 * c / g;
	y0 = y0 * c / g;
	if(a<0)x0 = -x0;
	if(b<0)y0 = -y0;
	return true;
}

int main(){
	int a, b, c, x0, y0, g;
	g=0;
	cin>>a>>b>>c;
	if(find_any_solution(a, b, c, x0, y0, g))
		cout<<x0<<' '<<y0<<endl;
	else
		cout<<"No solution"<<endl;
}
