def dfs(ret,part,step):
    global found
    if found: return
    if not checknum(ret[step-1]) :return
    if step == 6:
        if check(ret):
            print ret
            print sum(ret)
            found = True
        return
    for j in range(10,100):
        if step == 5 and j != ret[0]/100:
            continue
        x = part * 100 + j
        if not x in ret :
            ret.append(x)
            dfs(ret,j,step+1)
            ret.pop()

f =[lambda n:n*(n+1)/2,lambda n:n*n, lambda n:n*(3*n-1)/2,lambda n:n*(2*n-1),lambda n:n*(5*n-3)/2,lambda n:n*(3*n-2)]

#检查一个数能否写成f(f_idx)的形式
def checkone(n,f_idx):
    low = 1
    high = 200
    while low <= high:
        mid = (low+high)/2
        t = f[f_idx](mid)
        if t == n:
            return True
        elif t > n:
            high = mid - 1
        else :
            low = mid + 1
    return False

def checknum(n):
    for i in range(6):
        if checkone(n,i):
            return True
    return False

def is_all(lst,step):
    if step == 6:
        if not (False in polygonal):
            return True
    for i in lst[step]:
        if polygonal[i] == False:
            polygonal[i] = True
            if is_all(lst,step+1):return True
            polygonal[i] = False
    return False

def check(seq):
    global polygonal
    polygonal = [False]*6
    lst = []
    for i in range(6):
        tmp = []
        for j in range(6):
            if checkone(seq[i],j): tmp.append(j)
        lst.append(tmp)
    return is_all(lst,0)

polygonal = [False]*6
found = False
for i in range(1010,10000):
    if i%100>=10:
        dfs([i],i%100,1)
