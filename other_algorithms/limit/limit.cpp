// Not Completed

#include <iostream>
#include <algorithm>

using namespace std;


// int min_element(int arr[], int n)
// {
//   // if size = 0 means whole array has been traversed
//   if (n == 1)
//     return arr[0];
//   return min(arr[n-1], min_element(arr, n-1));
// }

int main(){
    int min_val=NULL, max_val=NULL;
    auto  array = {2, 4, 9, 1, 3, 7, 6, 5};
    // auto [min_val, max_val] = std::minmax_element(array.begin(), array.end());
    
    if(min_val == 0){
        auto min_val = std::min_element(array.begin(), array.end());
        std::cout << *min_val << std::endl;
    }
    if(max_val == 0){
        auto max_val = std::max_element(array.begin(), array.end());
        std::cout << *max_val << std::endl;
    }
    

    return 0;
}
