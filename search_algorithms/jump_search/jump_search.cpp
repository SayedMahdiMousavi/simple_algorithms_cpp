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
    int element;
    int shift;
    int i = 0;

    cout << "Eneter Value: ";
    cin >> element;

    cout << "Eneter number of jump: ";
    cin >> shift;
    cout << " " << endl;
    
    if (array.empty()){
        cerr << "Array is Empty";
        return 0;
    }

    while (array[i] <= element)
    {
        if (array[i] == element){
            cout << "Find Element - index is: " << i << endl;
            return i;
        }
        
        if (array[i] < element){
            if ((i+shift) < array.size()){
                i += shift;
            }
            else{
                i += 1;
            }
        }

    }
    
    if (array[i] > element){
        for(i; i < array.size(); i--){
            if (array[i] == element){
                cout << "Find Element - index is: " << i << endl;
                return i;
            }
        }
        cout << "Not Found Element" << endl;
    }

    return 0;
}