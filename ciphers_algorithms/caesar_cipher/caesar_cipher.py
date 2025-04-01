from string import printable


def encrypt(value: str, key: int) -> str:
    alpha = printable
    result = ""

    for ch in value:
        new_key = (alpha.index(ch) + key) % len(alpha)
        result += alpha[new_key]

    return result


def decrypt(value: str, key: int) -> str:
    key *= -1
    return encrypt(value, key)


def brute_force(value: str):
    alpha = printable
    key = 1
    brute_force_data = {}

    while key <= len(alpha):
        result = decrypt(value, key)
        brute_force_data[key] = result
        key += 1

    return brute_force_data


text = "Hello Python"

encrypt_text = encrypt(text, 5)
print(encrypt_text)

decrypt_text = decrypt(encrypt_text, 5)
print(decrypt_text)

brute_force_results = brute_force(encrypt_text)
print(brute_force_results)
