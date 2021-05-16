import sys

t, n= input().split(" ")
t = int(t)
n = int(n)
while t>0:
    t -= 1
    for i in range(n-1):
        print("M ", i+1, " ", n)
        sys.stdout.flush()
        r = input()
        if int(r) != i+1:
            print("S ", i+1, " ", r)
            sys.stdout.flush()
            k = input()
    print("D")
    sys.stdout.flush()
    a = input()

exit()
