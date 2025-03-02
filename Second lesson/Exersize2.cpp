#include <iostream>

int main(){
    std::cout << "Numbers that equal 5: ";
    for(int i = 2; i <= 100; i++){
        if(i % 5 == 0){
            std::cout << i << " ";
        }
    } 
}