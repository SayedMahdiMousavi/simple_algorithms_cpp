from typing import List

def top_one(array: List) -> List:
    repetition = dict()
    result = list()
    
    for i in array:
        if i in repetition:
            repetition[i] += 1
        else:
            repetition[i] = 1
            
    max_value = max(repetition.values())
    
    result = [key for key in repetition if repetition[key]==max_value]
    return result, repetition


array = list(map(int, input("Enter elemnts array: ").split(",")))
result, repetition_dict = top_one(array)
print(f"Number of Repetition: {repetition_dict}\nResult: {result}")
