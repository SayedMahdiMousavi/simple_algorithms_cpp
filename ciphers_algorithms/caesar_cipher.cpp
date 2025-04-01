#include <iostream>
#include <string>

using namespace std;

std::string encrypt(std::string value, int key){
    string alpha = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string result;
    int index, new_index;
    for(int i=0; i<value.size(); i++){

        for(int j=0; j<alpha.size(); j++){
            if(value[i]==alpha[j]){
                new_index = ((int)alpha[j] + key) % alpha.size();
                result += alpha[new_index];
            }
        }
    }
    return result;
}

int main(){
    std::cout << "Test Code" << std::endl;
    
    std::string text = "Hello Python";
    std::string result;
    int key = 5;

    result = encrypt(text, key);
    std::cout << result << std::endl;
    return 0;
}