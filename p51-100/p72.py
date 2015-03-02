def euler(n):
	ans=n
	i=2
	while i*i <=n:
		if n%i==0:
			ans=ans*(i-1)/i
			while n%i==0:
				n/=i
		i+=1
	if n<>1:
		ans=ans*(n-1)/n
	return ans

print sum([euler(x) for x in xrange(2,1000001)])
#303963552391L
