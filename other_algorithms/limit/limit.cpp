#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <optional>

using namespace std;

optional<int> parse_input(const string& input) {
    // Pressing the Enter key without entering a value
    if (input.empty()) {
        return nullopt;
    }

    stringstream ss(input);
    int number;
    ss >> number;

    // insert invalid value
    if (ss.fail() || !ss.eof()) {
        return nullopt; 
    }

    return number;
}

tuple<int, int> check_minmax(const vector<int>& array, optional<int> min_val_opt, optional<int> max_val_opt) {
    int actual_min = *min_element(array.begin(), array.end());
    int actual_max = *max_element(array.begin(), array.end());
    
    int min_val = min_val_opt.value_or(actual_min);
    int max_val = max_val_opt.value_or(actual_max);

    if (min_val > max_val) {
        swap(min_val, max_val);
    }

    return {min_val, max_val};
}


int main(int argc, char** argv){
    std::string input_str;
    vector<int> array;
    vector<int> result;

    
    std::cout << "Enter the array elements (separate elements with commas): ";
    getline(std::cin, input_str);
    stringstream ss(input_str);
    std::string temp;
    char delimiter = ',';
    while (getline(ss,temp, delimiter))
    {
        array.push_back(std::stoi(temp));
    }

    if(array.empty()){
        std::cerr << "Array is empty." << std::endl;
        return 0;
    }

    optional<int> min_val, max_val;

    std::cout << "Enter Min Value: ";
    getline(std::cin, input_str);
    min_val = parse_input(input_str);

    std::cout << "Enter Max Value: ";
    getline(std::cin, input_str);
    max_val = parse_input(input_str);

    auto [filtered_min, filtered_max] = check_minmax(array, min_val, max_val);
    std::cout << "Min Value: " << filtered_min << " - " << "Max Value: " << filtered_max << std::endl;    

    for(int item: array){
        if(item >= filtered_min && item <= filtered_max)
            result.push_back(item);
    }

    for(int i: result)
        cout << i << " ";
    
    return 0;
}
