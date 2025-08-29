#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<int> get_value(){
    std::string input_str;
    vector<int> element;
    
    std::cout << "Enter elemnts array(separate elements with commas): ";
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