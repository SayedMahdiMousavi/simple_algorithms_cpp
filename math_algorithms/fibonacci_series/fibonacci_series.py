def fibonacci_series(num: int):
    t, t_1 = 1, 1
    print(t, '\t', t_1, end='\t')
    for i in range(1, num-1):
        x = t + t_1
        t_1 = t
        t = x
        print(x, end='\t')


num = int(input("Enter Number: "))

fibonacci_series(num)
