t = int(input())
tc = t
while t>0:
    t -= 1
    n = int(input())
    a = list(map(int, input().split()))
    ans = 0
    for i in range(n-1):
        if a[i] < a[i+1]:
            continue
        a[i] += 1
        ax = str(a[i])
        ay = str(a[i+1])
        case_ = -1
        for j in range(len(ay)):
            if ax[j] > ay[j]:
                case_ = 1
                break
            if ay[j] > ax[j]:
                case_ = 0
                break
        leny = len(ay)
        if case_ == -1:
            for j in range(len(ax)-leny):
                ay += ax[leny + j]
                ans += 1
        elif case_ == 0:
            for j in range(len(ax)-leny):
                ay = ay + "0"
                ans += 1
        else:
            for j in range(len(ax)-leny+1):
                ay = ay + "0"
                ans += 1
        a[i+1] = int(ay)
    print("Case #", tc-t, ": ", ans, sep='')