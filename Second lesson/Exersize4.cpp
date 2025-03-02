#include <iostream>

int main(){
    int count = 0;
    for(int i = 100000; i <= 999999; i++){
        int first = i / 100000;
        int second = i % 100000 / 10000;
        int third = i % 100000 % 10000 / 1000;
        int fourth = i % 100000 % 10000 % 1000 / 100;
        int fifth = i % 100000 % 10000 % 1000 % 100 / 10;
        int sixth = i % 100000 % 10000 % 1000 % 100 % 10;
        if(first + second + third == fourth + fifth + sixth){
            count++;
        }
    }
    float var = (float) count / 1000000.f;
    std::cout << "Amount of lucky numbers: " << count << std::endl;
    std::cout << "Probability is: " << var << std::endl;
}