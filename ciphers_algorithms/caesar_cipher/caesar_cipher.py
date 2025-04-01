from string import printable


def encrypt(value: str, step: int) -> str:
    alpha = printable
    result = ""

    for ch in value:
        new_index = (alpha.index(ch) + step) % len(alpha)
        result += alpha[new_index]

    return result


def decrypt(value: str, step: int) -> str:
    step *= -1
    return encrypt(value, step)


def brute_force(value: str):
    alpha = printable
    step = 1
    brute_force_data = {}

    while step <= len(alpha):
        result = decrypt(value, step)
        brute_force_data[step] = result
        step += 1

    return brute_force_data


text = input("Enter Message: ")
step = int(input("Enter Step: "))

encrypt_text = encrypt(text, step)
print(encrypt_text)

decrypt_text = decrypt(encrypt_text, step)
print(decrypt_text)

brute_force_results = brute_force(encrypt_text)
print(brute_force_results)
