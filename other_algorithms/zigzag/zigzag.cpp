#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


vector<int> get_value(){
    std::string input_str;
    vector<int> element;
    
    getline(std::cin, input_str);
    stringstream ss(input_str);
    std::string temp;
    char delimiter = ',';
    while (getline(ss,temp, delimiter))
    {
        element.push_back(std::stoi(temp));
    }

    return element;
}


int main(){
    std::cout << "Enter elemnts array_1(separate elements with commas): ";
    vector<int> array_1 = get_value();
    
    std::cout << "Enter elemnts array_2(separate elements with commas): ";
    vector<int> array_2 = get_value();
    vector<int> result;

    int len_1 = array_1.size();
    int len_2 = array_2.size();
    if(len_1 >= len_2){
        for (int i = 0; i < len_1; i++) {
            
            if(i == len_2){
                std::vector<int> slice_vector = std::vector<int>(array_1.begin() + i, array_1.end());

                // c++23
                result.append_range(slice_vector);
                break;
            }
    
            result.push_back(array_1[i]);
            result.push_back(array_2[i]);
        }
    }
    else
    {
        for (int i = 0; i < len_2; i++) {
            
            if(i == len_1){
                std::vector<int> slice_vector = std::vector<int>(array_2.begin() + i, array_2.end());

                // c++23
                result.append_range(slice_vector);
                break;
            }
    
            result.push_back(array_1[i]);
            result.push_back(array_2[i]);
        }
    }
    

    for (auto i : result) {
        cout << i << " ";
    }
    

    return 0;
}
