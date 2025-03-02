#include <iostream>
#include <vector>

int main(){
    int number = 0;
    std::vector <int> bit_num;
    std::cin >> number;
    while(number != 0){
        if(number % 2 == 1){
            bit_num.push_back(1);
        }else{
            bit_num.push_back(0);
        }
        number /= 2;
    }
    int count = 0;
    while(true){
        if(bit_num[0] == 0 && bit_num.size() == 1){
            break;
        }else if(bit_num[0] == 0){
            bit_num.erase(bit_num.begin());
            count++;
        }else{
            bit_num[0] -= 1;
            count++;
        }
    }
    std::cout << count << std::endl;
    return 0;
}