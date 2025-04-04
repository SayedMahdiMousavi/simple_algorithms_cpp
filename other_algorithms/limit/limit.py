from typing import List


def limit_from_scratch(arr:List, min_val:int=None, max_val:int=None):
    if len(arr) == 0:
        return None
    if min_val is None:
        min_val = min(arr)
    if max_val is None:
        max_val = max(arr)
    result = []
    for items in arr:
        if items >= min_val and items <= max_val:
            result.append(items)    
    return result     


def simple_limit(arr:List, min_val:int=None, max_val:int=None):
    if len(arr) == 0:
        return None
    if min_val is None:
        min_val = min(arr)
    if max_val is None:
        max_val = max(arr) 
    return list(filter(lambda x: (min_val <= x <= max_val), arr))


def advance_limit(arr:List, min_val:int=None, max_val:int=None):
    min_check = lambda x: True if min_val is None else (x >= min_val)
    max_check = lambda x: True if max_val is None else (x <= max_val)
    
    return [val for val in arr if min_check(val) and max_check(val)]
 

array = list(map(int, input("Enter elemnts array: ").split(",")))

min_val = input("Enter Min Value: ")
max_val = input("Enter Max Value: ")

if min_val == "" and max_val == "":
    min_val, max_val = None, None
elif min_val != "" and max_val == "":
    min_val = int(min_val)
    max_val = None
elif min_val == "" and max_val != "":
    min_val = None
    max_val = int(max_val)    
else:
    min_val = int(min_val)
    max_val = int(max_val)

print(limit_from_scratch(array, min_val, max_val))
print(simple_limit(array, min_val, max_val))
print(advance_limit(array, min_val, max_val))
