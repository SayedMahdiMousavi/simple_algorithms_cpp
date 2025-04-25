def linear_search(array, element):
    for idx, value in enumerate(array):
        if value == element:
            return idx
    return None


array = list(map(int, input("Enter elemnts array: ").split(",")))
element = int(input("Enter Value: "))

print(linear_search(array, element))
