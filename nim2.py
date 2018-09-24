rock=[7,9,3]
import random

def check(r1):
    return r1[0]^r1[1]^r1[2]
def states_generate(rock):
    r=[3,2,1]
    st=[]
    for c in r:

        for x in range(3):
            v = list(rock)
            if(c<rock[x]) or c==rock[x]:
               v[x]-=c
               st.append(v)
    print(st)
    return st

def removingStrawshuman(rock):
    c=int(input("Enter column :"))
    n=int(input("Enter number of rock to remove:"))
    while c>3 or c<1 or n>rock[c-1] or n<1:

        print("Invalid!")
        c = int(input("Enter column :"))
        n = int(input("Enter number of rock to remove:"))
    rock[c-1]-=n
    return rock


def removingStrawsComputer(rock):

    st=states_generate(rock)
    win_st=[]
    for x in st:

        if(check(x)==0):
            win_st=x
            print("check works!")
            break
    if win_st==[]:
        print("check does not work!")
        b=random.randint(0,len(st)-1)
        win_st=st[b]
    print(win_st)
    return win_st

def show(rock):
    for c in rock:
        print("#"*c)



i=1
op=int(input("enter option: 1)com vs com, 2) human vs com, 3)human vs human"))
if op==1:
   while rock !=[0,0,0]:

         rock=removingStrawsComputer(rock)

         if rock == [0,0,0]:
            if i%2 ==1:
                print("COM1 win!")
            else:
                print("COM2 wins!")

         i += 1

if op==2:
   while rock !=[0,0,0]:
       if i%2 ==1:
            rock=removingStrawshuman(rock)
       else:
            rock = removingStrawsComputer(rock)

       if rock == [0,0,0]:
            if i%2 ==1:
                print("human wins!")
            else:
                print("COM wins!")

       i += 1

if op==3:
   while rock !=[0,0,0]:
       if i%2 ==1:
            print("human1:")
            rock=removingStrawshuman(rock)
            print(rock)
            show(rock)
       else:
            print("human2")
            rock = removingStrawshuman(rock)
            print(rock)
            show(rock)

       if rock == [0,0,0]:
            if i%2 ==1:
                print("human1 wins!")
            else:
                print("human2 wins!")

       i += 1
