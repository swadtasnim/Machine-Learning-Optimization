def vlow(x):
    if x<10 or x>20:
        return 0
    elif 10<=x<=20:
        print("very low",1- (abs(10-float(x))/10))
        return 1- (abs(10-float(x))/10)

def low(x):
    if x<10 or x>30:
        return 0
    elif 10<=x<=30:
        print("low ",1- (abs(20-float(x))/10))
        return 1- (abs(20-float(x))/10)

def high(x):
    if x<20 or x>40:
        return 0
    elif 20<=x<=40:
        return 1- (abs(30-float(x))/10)

def vhigh(x):
    if x<30 or x>40:
        return 0
    elif 30<=x<=40:
        return 1- (abs(40-float(x))/10)


def dry(x):
    if x<15 or x>38.33:
        return 0
    elif 15<=x<=38.33:
        return 1- (abs(15-float(x))/23.33)

def comfort(x):
    if x<15 or x>61.66:
        return 0
    elif 15<=x<=61.66:
        return 1- (abs(38.33-float(x))/23.33)

def humid(x):
    if x<38.33 or x>85:
        return 0
    elif 38.33<=x<=85:
        print("humid",1- (abs(61.66-float(x))/23.33))
        return 1- (abs(61.66-float(x))/23.33)

def sticky(x):
    if x<61.66 or x>85:
        return 0
    elif 61.66<=x<=85:
        print("sticky,",1- (abs(85-float(x))/23.33))
        return 1- (abs(85-float(x))/23.33)


def main():
    t=float(input("Enter Temparature: "))
    h=float(input("Enter Humidity: "))

    o1= max(min(vlow(t),dry(h)),min(vlow(t),comfort(h)),min(vlow(t),humid(h)),min(low(t),dry(h)),min(low(t),comfort(h)))
    f1=max(min((high(t)),humid(h)),min(high(t),sticky(h)),min(vhigh(t),comfort(h)),min(vhigh(t),humid(h)),min(vhigh(t),sticky(h)))
    l1=max(min(vlow(t),sticky(h)),min(low(t),humid(h)),min(high(t),dry(h)))
    m1=max(min(low(t),sticky(h)),min(high(t),comfort(h)),min(vhigh(t),dry(h)))
    print(o1,f1,l1,m1)
    res=max(o1,f1,l1,m1)
    if o1==res:
        print("OFF")
    elif f1==res:
        print("FAST")
    elif l1==res:
        print("LOW")
    elif m1==res:
        print("MEDIUM")



main()