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

    cout << "Eneter Value: ";
    cin >> element;
    cout << " " << endl;

    for(int idx=0; idx<=array.size(); idx++){
        if(array[idx] == element){
            cout << "Index Element: " << idx << endl;
        }
    }

    return 0;
}
