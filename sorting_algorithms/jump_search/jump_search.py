from typing import List


def jump_search(array: List, element: int, shift=3):
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

jump_search([1, 2, 3, 5, 7, 9, 8, 10, 12, 14, 15, 16, 17, 18, 19], 19)
