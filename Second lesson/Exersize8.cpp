#include <iostream>
#include <cmath>

int main(){
    std::string numberNat;
    std::cout << "Input your number: ";
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    int count5 = 0;
    int count6 = 0;
    int count7 = 0;
    int count8 = 0;
    int count9 = 0;
    int number = 0;
    for(int i = 0; i < numberNat.length(); i++){
        number = numberNat[i] - '0';
        if(number == 0){
            count0++;
        }else if(number == 1){
            count1++;
        }else if(number == 2){
            count2++;
        }else if(number == 3){
            count3++;
        }else if(number == 4){
            count4++;
        }else if(number == 5){
            count5++;
        }else if(number == 6){
            count6++;
        }else if(number == 7){
            count7++;
        }else if(number == 8){
            count8++;
        }else if(number == 9){
            count9++;
        }
    }
    std::cout << "\nCounter:" << std::endl;
    std::cout << "Number of 0s is:" << count0 << std::endl;
    std::cout << "Number of 1s is:" << count1 << std::endl;
    std::cout << "Number of 2s is:" << count2 << std::endl;
    std::cout << "Number of 3s is:" << count3 << std::endl;
    std::cout << "Number of 4s is:" << count4 << std::endl;
    std::cout << "Number of 5s is:" << count5 << std::endl;
    std::cout << "Number of 6s is:" << count6 << std::endl;
    std::cout << "Number of 7s is:" << count7 << std::endl;
    std::cout << "Number of 8s is:" << count8 << std::endl;
    std::cout << "Number of 9s is:" << count9 << std::endl;
}