#include <iostream>

int main(){
    int k = 0;
    int h = 0;
    int m = 0;
    std::cin >> k;
    h = k / 3600;
    k %= 3600;
    m = k / 60;
    std::cout << "It is " << h << " hours and " << m << " minutes.";
}