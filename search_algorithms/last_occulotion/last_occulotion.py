def last_occulotion(array: list, target: int):
    if(len(array) == 0):
        print("xxx array is empty xxx")
        return None
    low = 0
    high = len(array) - 1
    
    while(low <= high):
        mid = low + (high - low) // 2
        
        if (array[mid] == target and mid == len(array) - 1) or ((array[mid] == target) and (array[mid+1] > target)):
            print(f'find last index is: {mid}')
            return mid

        elif (array[mid] <= target):
            low = mid + 1
        else:
            high = mid - 1


array = list(map(int, input("Enter elemnts array: ").split(",")))
target = int(input("Enter target: "))

print(last_occulotion(array, target))
