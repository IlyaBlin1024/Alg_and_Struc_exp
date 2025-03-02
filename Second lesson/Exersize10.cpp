#include <iostream>
#include <cmath>

int main(){
    std::string number;
    std::cout << "\nInput your number: ";
    std::cin >> number;
    int middle = number.length() / 2;
    int count = 0;
    for(int i = 0; i <= (number.length() - 1) / 2; i++){
        if (number[i] - '0' == number[number.length() - 1 - i] - '0'){
            count++;
        }
    }
    if(count == middle){
        std::cout << "Yes!" << std::endl;
    }else{
        std::cout << "No!" << std::endl;
    }
}