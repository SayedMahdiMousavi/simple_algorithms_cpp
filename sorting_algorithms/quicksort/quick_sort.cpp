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


vector<int> quick_sort(vector<int> array){
    if(array.size() <= 1){
        return array;
    }

    vector<int> less, great, result;
    int pivot = array[0];

     for (int i=1; i<array.size(); i++) {
        if (array[i] <= pivot)
            less.push_back(array[i]);
        else
            great.push_back(array[i]);
    }

    less = quick_sort(less);
    great = quick_sort(great);
    less.push_back(pivot);
    
    copy(great.begin(), great.end(), back_inserter(less));
    
    return less; 
}


int main(){

    vector<int> array = get_value();
    vector<int> result = quick_sort(array);

    for(auto x: result){
        cout << x << " " ;
    }
    return 0;
}