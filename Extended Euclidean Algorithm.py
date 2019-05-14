'''
the extended version finds a way to represent GCD in terms of 
a and b, i.e. coefficients x and y

for which:
	a⋅x+b⋅y=gcd(a,b)

(b mod a).x1 + a.y1 = g

b mod a = b - floor(b/a).a

so, g = (b - floor(b/a).a).x1 + a.y1
	
	x = y1 - floor(b/a).x1
	y = x1
'''

def extended_euclidean_algorithm(a, b):
	if a == 0:
		return (b, 0, 1) # last wali term me sirf remainder hoga
	d, x1, y1 = extended_euclidean_algorithm(b%a, a)
	x = y1 - (b//a)*x1
	y = x1
	return (d, x, y)
print(extended_euclidean_algorithm(54, 888))