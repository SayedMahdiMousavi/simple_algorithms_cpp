def binary_search(array, element):
    low = 0
    high = len(array) - 1
    
    while low <= high:
        mid = (high + low) // 2
        if array[mid] == element:
            return mid

        if array[mid] < element:
            low = mid + 1
        else:
            high = mid - 1
    return None


array = list(map(int, input("Enter elemnts array: ").split(",")))
val = int(input("Enter element: "))

print(binary_search(array, val))
