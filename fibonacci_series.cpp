#include <iostream>

using namespace std;

int main(){
    int t = 1, t_1 = 1;
    int num, x;

    cout << " Enter Number: ";
    cin >> num;
    cout << endl;
    cout << t << "\t" << t_1  << "\t";
    for(int i=1; i<=num-2; i++){
        x = t + t_1;
        cout << x << "\t";
        t_1 = t;
        t = x;
    }
    return 0;
}