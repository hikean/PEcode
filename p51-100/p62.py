def change(n):
	tmp='1'
	for x in sorted(str(n)):
		tmp+=x
	return int(tmp)


mp={}
limit=10000
ans=0
for x in xrange(1,limit):
	tmp=change(x**3)
	if tmp in mp and mp[tmp]==4:
		#print x
		ans=x
		break
	elif tmp in mp:
		mp[tmp]+=1
	else :
		mp[tmp]=1

for x in xrange(1,10000):
	if change(x**3)==change(ans**3):
		print x,x**3
		#break
