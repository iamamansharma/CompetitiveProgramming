def gcd(a, b):
	if b==0:
		return a
	return gcd(b, a%b)

for _ in range(int(input())):
	a, b = map(int, input().split(' '))
	hcf = gcd(a, b)
	print(hcf, a*b//hcf)