# Problem #6: AAB-BAA

# Written by Ke Xue

# Score: 10/100

t = int(input())

for _ in range(t):
    a, b = map(str, input().split())
    c = a.count("A")
    d = b.count("A")
    e = a.count("B")
    f = b.count("B")
    if a[::-1] == b and a[0] == "A" and b[0] == "B":
        if e % 2 == 0:
            print(c*(e//2))
        elif e % 2 == 1:
            if c % 2 == 0:
                print(c*(e//2) + (c//2))
            else:
                print(-1)
    elif e == 1 and f == 1:
        x = a.index("B")
        y = b.index("B")
        if (x-y) % 2 == 0:
            print(int(abs(x-y)/2))
        else:
            print(-1)
    else:
        print(-1)
