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
 

print(limit_from_scratch([2, 4, 9, 1, 3, 7, 6, 5], min_val=2, max_val=6))
print(simple_limit([2, 4, 9, 1, 3, 7, 6, 5], min_val=2, max_val=6))
print(advance_limit([2, 4, 9, 1, 3, 7, 6, 5], min_val=2, max_val=6))
