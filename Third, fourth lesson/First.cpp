#include <iostream>

int main(){
    int *ptr = new int;
    *ptr = 100;
    int *ptr2 = ptr;
    *ptr2 = 200;
    std::cout << ptr << " , " << *ptr << std::endl;
    std::cout << ptr2 << " , " << *ptr2 << std::endl;
    *ptr = 300;
    std::cout << ptr << " , " << *ptr << std::endl;
    std::cout << ptr2 << " , " << *ptr2 << std::endl;
    delete ptr;
}