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
    int element;
    
    cout << "Enter Value: ";
    cin >> element;

    while (low <= high)
    {
        int mid = (high + low) / 2;

        if(array[mid] == element){
            cout << "Find Element: " << mid << endl;
            return mid;
        }

        if(element > array[mid])
            low = mid + 1;
        else
            high = mid - 1;

    }
    return 0;
}
