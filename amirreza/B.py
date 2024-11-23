n = int(input())
t1, t2 = map(int, input().split())
t3, t4 = map(int, input().split())


if t1 < t3 < t2 and t2 < t4:
    print(4)
elif t1 < t3 < t2 and t2 >= t4:
    print(3)
elif t1 < t3 < t2 and (t4 == t2 or t4 == t1):
    print(3)
elif t1 < t2 < t3:
    print(3)
