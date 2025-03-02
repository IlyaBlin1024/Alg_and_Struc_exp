#include <iostream>
#include <string>

int main(){
    std::string number;
    std::cin >> number;
    int count = 0;
    for(int i = 0; i < number.size(); i++){
        count += number[i] - '0';
        if(i + 1 == number.size() && count > 9){
            number = std::to_string(count);
            count = 0;
            i = -1;
        }
    }
    std::cout << count;
}