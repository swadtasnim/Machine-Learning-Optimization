a=0
b=0
i=4
j=3
def sol_1(a,b,i,j):
    print("Solution 1!!!!")
    if(a<i):
        a=i
        print("a= ",a," b= ",b," according to Rule-1")
    if(a+b>=i and a>0):
        a=a-(j-b)
        b=j
        print("a= ",a," b= ",b," according to Rule-8")
    if(b>0):
        b=b-j
        print("a= ",a," b= ",b," according to Rule-6")
    if(a+b<=i and a>0):
        b=a+b
        a=a-a
        print("a= ",a," b= ",b," according to Rule-10")
    if(a<j):
        a=i
        print("a= ",a," b= ",b," according to Rule-1")
    if (a + b >= j and a > 0):
        a = a - (j-b)
        b = j
        print("a= ", a, " b= ", b, " according to Rule-8")
    if(a==2):
        print("a= ",a, " Successful!!!")


import matplotlib.pyplot as plt
import matplotlib.animation as animation


fig=plt.figure()
ax1=fig.add_subplot(1,1,1)

def animate():
    global a
    global b
    x=[1,2]
    y=[a,b]
    ax1.clear()
    ax1.bar(x,y)

    sol_1(a,b,i,j)

    plt.pause(5)
    x=[1,2]
    y=[a,b]
    ax1.clear()
    ax1.bar(x,y)
    plt.pause(5)
    exit()

ani=animation.FunAnimation(fig,animate,interval=5000)
plt.xlim(1,3)
plt.show()

