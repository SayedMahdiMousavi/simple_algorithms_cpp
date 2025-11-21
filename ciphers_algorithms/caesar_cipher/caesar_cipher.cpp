#include <iostream>
#include <string>

using namespace std;


std::string encrypt(std::string value, int step){
    string alpha, result;
    int new_index, pos;

    for (char c{' '}; c <= '~'; ++c)
        alpha += c;

    int length = alpha.size();

    for(auto ch: value){
        pos = alpha.find(ch);
        new_index = (pos + step) % length;

        if(new_index < 0){
            new_index += length;
        }
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