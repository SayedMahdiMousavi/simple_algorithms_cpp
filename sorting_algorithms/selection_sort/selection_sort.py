from typing import List

def find_min(array: List):
    min_item = array[0]
    index_item = 0
    
    for i in range(1, len(array)):
        if min_item > array[i]:
            min_item = array[i]
            index_item = i
    return index_item


def selection_sort(array: List):
    new_array = []
    for _ in range(len(array)):
        min_index = find_min(array)
        new_array.append(array.pop(min_index))
    return new_array
        

array = list(map(int, input("Enter elemnts array: ").split(",")))
print(selection_sort(array))
