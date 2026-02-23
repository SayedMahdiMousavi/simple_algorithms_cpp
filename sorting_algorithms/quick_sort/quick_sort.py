def quick_sort(array: list):
    if len(array) <= 1:
        return array
    else:
        pivot = array[0]
        less, great = [], []
        
        for i in range(1, len(array)):
            if array[i] <= pivot:
                less.append(array[i])
            else:
                great.append(array[i])
        
        return quick_sort(less) + [pivot] + quick_sort(great)
    
    
array = list(map(int, input("Enter elemnts array: ").split(",")))
print(quick_sort(array))
