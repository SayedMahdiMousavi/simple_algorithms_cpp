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

int main(){
    vector<int> array = get_value();
    int low = 0;
    int high = array.size() - 1;
    int target;
    
    cout << "Enter target: ";
    cin >> target;

    if(array.empty()){
        cerr << "xxx array is empty xxx" << endl;
        return 0; 
    }

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if(target > array[mid])
            low = mid + 1;
        else
            high = mid;

    }
    if(target == array[low]){
        cout << "find target, index is: " << low << endl;
    }
    else{
        cout << "Not found target !!! " << endl;
    }
    return 0;
}
