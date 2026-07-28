from typing import List


# simple method
def zigzag(array_1: List, array_2: List) -> List:
    array = []
    if len(array_2) == 0:
        return array_1

    len_1 = len(array_1)
    len_2 = len(array_2)
    
    if len_1 >= len_2:
        for i in range(len_1):
            if i == len_2:
                array.extend(array_1[i:])
                break
            array.append(array_1[i])
            array.append(array_2[i])
    else:
        for i in range(len_2):
            if i == len_1:
                array.extend(array_2[i:])
                break
            array.append(array_1[i])
            array.append(array_2[i])
    
    return array
            

# Best method
class ZigZag:
    def __init__(self, array_1: List, array_2: List):
        self.queue = [array_1, array_2]
    
    def next(self):
        value = self.queue.pop(0)
        item = value.pop(0)
        
        if value:
            self.queue.append(value)
        return item
    
    def has_next(self):
        if self.queue:
            return True
        return False

 
array1 = list(map(int, input("Enter elemnts array_1: ").split(",")))
array2 = list(map(int, input("Enter elemnts array_2: ").split(",")))
result = zigzag(array1, array2)
print(f"Result: {result}")

zz_obj = ZigZag(array1, array2)
while zz_obj.has_next():
    print(zz_obj.next(), end=',')
    