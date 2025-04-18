#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include <optional>

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

int main(){
    vector<int> array = get_value();
    map<int, int> repetition;
    vector<int> result;
    int max_value =0;

    for(auto i: array){
        if(repetition.find(i) != repetition.end())
            repetition[i] += 1;
        else
            repetition.insert({i, 1});
    }
    
    for(auto i: repetition){
        if (max_value <= i.second){
            max_value = i.second;
        }
    }
    cout << "Max Value Number of Repetition: " << max_value << endl;

    for(auto i: repetition){
        if(i.second == max_value){
            result.push_back(i.first);
            cout << "Result:[" << i.first << ": " << i.second << "]"<< endl;
        }
    }

    return 0;
}
