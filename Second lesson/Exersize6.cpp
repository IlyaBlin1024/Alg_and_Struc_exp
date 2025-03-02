#include <iostream>
#include <cmath>

int main(){
    float sum = 0.f;
    float number = 0;
    std::cout << "Input your number: ";
    std::cin >> number;
    number = abs(number);
    for (int i = 1; i <= number; i++){
        sum += 1.f / (float) i;
    }
    std::cout << "\nYour sum is: " << sum << std::endl;
}