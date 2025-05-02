from typing import List


def jump_search(array: List, element: int, shift: int) -> int:
    i = 0
    while array[i] <= element: 
        if array[i] == element:
            print(f"Find Element - index: {i}")
            break
        
        if array[i] < element:   
            if len(array) > (i+shift):
                i += shift
            else:
                i += 1
        
    if array[i] > element:
        for item in array[i-1::-1]:
            if item == element:
                print(f"Find Element - index is: {array.index(item)}")
                break


array = list(map(int, input("Enter elemnts array: ").split(",")))
val = int(input("Enter element: "))
shift = int(input("Enter number of jump: "))

jump_search(array, val, shift)
