import sys

t, a, b= input().split(" ")
t = int(t)
a = int(a)
b = int(b)
while t>0:
    t -= 1
    x = 0
    for i in range(-5, 6):
        if x!=0:
            break
        for j in range(-5, 6):
            print(i," ",j)
            sys.stdout.flush()
            r = input()
            if r=="CENTER":
                x=1
                break
exit()