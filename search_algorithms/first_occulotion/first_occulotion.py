def first_occulotion(array: list, target: int):
    low = 0
    high = len(array) - 1
    
    while(low < high):
        mid = low + (high - low) // 2
        
        if len(array) == 0:
            print(" xxx array is empty xxx ")
            break
        if (array[mid] < target):
            low = mid + 1
        else:
            high = mid
    
    if (array[low] == target):
        return low
    
array = list(map(int, input("Enter elemnts array: ").split(",")))
target = int(input("Enter target: "))

print(first_occulotion(array, target))
