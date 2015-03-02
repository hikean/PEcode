def cal(n):
	num=n
	ans=int(num**0.5)
	for x in range(100):
		num*=100
		tmp=ans*10
		while tmp*tmp <= num:
			tmp+=1
		ans=tmp-1
	st=str(ans)
	st=st[len(st)-100::]
	return sum([int(x) for x in st])
print sum([cal(x) for x in range(100)])
