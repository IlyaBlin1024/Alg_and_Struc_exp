#include <iostream>
#include <cmath>

int main(){
    long long a = 0;
    std::cin >> a;
    long long coef[6];
    for(int i = 0; i < 6; i++){
        std::cin >> coef[i];
    }
    int i = 0;
    while(true){
        if(a == coef[0] + i * coef[1] + std::pow(i, 2) * coef[2] + std::pow(i, 3) * coef[3] + std::pow(i, 4) * coef[4] + std::pow(i, 5) * coef[5]){
            break;
        }
        i++;
        if(i > 99 || a < coef[0] + i * coef[1] + std::pow(i, 2) * coef[2] + std::pow(i, 3) * coef[3] + std::pow(i, 4) * coef[4] + std::pow(i, 5) * coef[5]){
            i = -1;
            break;
        }
    }
    std::cout << i;
}