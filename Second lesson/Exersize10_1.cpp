#include <iostream>

int main(){
    int num7;
    std::cout << "Input your number: ";
    std::cin >> num7;
    std::cout << "Number equals 7: ";
    for(int i = 1; i <= num7; i++){
        int answer = i;
        if(answer % 7 == 0){
            int sum = 0;
            while(answer != 0){
                sum += answer % 10;
                answer /= 10;
            }
            if (sum % 7 == 0){
                std::cout << i << " ";
            }
        }
    }
}