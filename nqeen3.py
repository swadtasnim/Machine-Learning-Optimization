import random

def get_h(row):
    h=0
    for i in range(len(row)):
        for j in range(i+1,len(row)):
            if row[i]==row[j]:
                h+=1
            if abs(row[i]-row[j])==abs(i-j):
                h+=1
    return h


def get_res(row):
    moves={}
    for i in range(len(row)):
        for j in range(len(row)):
            if (row[i]==j):
                continue
            c=list(row)
            c[i]=j
            moves[(i,j)]=get_h(c)

    t=get_h(row)
    best=[]

    for k,v in moves.items():
        if v<t:
            t=v


    for k,v in moves.items():
        if v==t:
            best.append(k)
    print(best)
    if len(best)>0:

        p=random.randint(0,len(best)-1)
        r=best[p][0]
        c=best[p][1]
        row[r]=c
    return row,best



n=int(input("size"))
row=[random.randint(0,n-1) for x in range(n)]
print(row)
while get_h(row)!=0:
      print(get_h(row))
      print(row)
      row,b=get_res(row)
      print(row,b)
      print(get_h(row))

for r in range(n):
    t=[]
    for c in range(n):
        t.append(int(c==row[r]))
    print(t)


