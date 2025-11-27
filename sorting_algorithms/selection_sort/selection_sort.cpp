#include <iostream>
#include <vector>
#include <sstream>
#include <bits/stdc++.h> // for max_element

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


int find_min(vector<int> array){
    int min_item = array[0];
    int index_item = 0;

    for(int i=1; i<array.size(); i++){
        if(min_item > array[i]){
            min_item = array[i];
            index_item = i;
        }        
    }
    return index_item;
}


int main(){
    vector<int> new_array;
    vector<int> array = get_value();

    for(int i: array){
        int min_index = find_min(array);
        int new_item = array.at(min_index);
        new_array.push_back(new_item);
        array.erase(array.begin() + min_index);
    }

    for(auto x: new_array){
        cout << x << " ";
    }

    return 0;

}