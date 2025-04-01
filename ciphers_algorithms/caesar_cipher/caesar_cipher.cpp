#include <iostream>
#include <string>

using namespace std;


std::string encrypt(std::string value, int step){
    string alpha, result;
    int new_index;

    for (char c{' '}; c <= '~'; ++c)
        alpha += c;

    for(auto ch: value){
        new_index = (alpha.find(ch) + step) % alpha.size();
        result += alpha[new_index];
    }

    return result;
}


std::string decrypt(std::string value, int step){
    step *= -1;
    return encrypt(value, step);
}


int main(){
    std::string message;
    int step;

    std::cout << "Enter Message: ";
    std::getline (std::cin, message);
    std::cout << " " << std::endl;

    std::cout << "Enter step: ";
    std::cin >> step;
    std::cout << " " << std::endl;

    std::string encrypt_result = encrypt(message, step);
    std::cout << "Encrypt Message: " << encrypt_result << std::endl;

    std::string decrypt_result = decrypt(encrypt_result, step);
    std::cout << "Decrypt Message: " << decrypt_result << std::endl;

    return 0;
}