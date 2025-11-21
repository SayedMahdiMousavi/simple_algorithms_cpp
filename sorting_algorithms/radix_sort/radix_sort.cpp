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

int max_vaL(vector<int> array){
    int max_item = array[0];
    for(int item: array){
        if(max_item < item){
            max_item = item;
        }        
    }
    return max_item;
}

int main(){
    vector<int> array = get_value();
    int position = 1;
    int iteration = 0;

    if(array.empty()){
        cerr << "xxx array is empty xxx" << endl;
        return 0; 
    }

    // int max_number = max_vaL(array);
    int max_number = * std::max_element(array.begin(), array.end());

    // while (position <= max_number){
    //     int *a[10] = { NULL };
    //     for(int num: array){
    //         int digit_number = num; / position % 10;
            
    //     }
    // }

    return 0;
}