#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int check_minmax(vector<int> array){

    if(array.size() == 0){
        return 0;
    }

    int min_val=NULL, max_val=NULL;
    std::cout << "Enter Min Value: ";
    std::cin >> min_val;
    std::cout << std::endl;

    std::cout << "Enter Max Value: ";
    std::cin >> max_val;
    std::cout << std::endl;

    // std::cout << "Min Value: " << min_val << " - " << "Max Value: " << max_val << std::endl;
    return min_val, max_val;

}

int main(){

    vector<int> array = {2, 4, 9, -1, 3, 7, -6, 5};
    vector<int> result;

    int min_val, max_val = check_minmax(array);
    std::cout << "Min Value: " << min_val << " - " << "Max Value: " << max_val << std::endl;    

    if(min_val == NULL){
        auto min_check = std::min_element(array.begin(), array.end());
        min_val = *min_check;
    }

    if(max_val == NULL){
        auto max_check = std::max_element(array.begin(), array.end());
        max_val = *max_check;   
    }

    for(int item: array){
        if(item >= min_val & item <= max_val)
            result.push_back(item);
    }

    for(int i: result)
        cout << i << " ";
    
    return 0;
}
