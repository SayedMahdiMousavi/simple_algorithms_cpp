#include <iostream>
#include <string>

using namespace std;

std::string encrypt(std::string value, int key){
    string alpha, result;
    int new_index;

    for (char c{' '}; c <= '~'; ++c)
        alpha += c;

    for(auto ch: value){
        new_index = (alpha.find(ch) + key) % alpha.size();
        result += alpha[new_index];
    }

    return result;
}


std::string decrypt(std::string value, int key){
    key *= -1;
    return encrypt(value, key);
}


int main(){
    std::string message;
    int key;

    std::cout << "Enter Message: ";
    std::getline (std::cin, message);
    std::cout << " " << std::endl;

    std::cout << "Enter key: ";
    std::cin >> key;
    std::cout << " " << std::endl;

    std::string encrypt_result = encrypt(message, key);
    std::cout << "Encrypt Message: " << encrypt_result << std::endl;

    std::string decrypt_result = decrypt(encrypt_result, key);
    std::cout << "Decrypt Message: " << decrypt_result << std::endl;


    return 0;
}