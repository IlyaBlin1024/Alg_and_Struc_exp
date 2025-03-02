#include <iostream>

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void swap_ptr(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){
    int a = 0;
    int b = 0;
    std::cout << "Input a: ";
    std::cin >> a;
    std::cout << "Input b: ";
    std::cin >> b;
    swap(a, b);
    swap_ptr(&a, &b);
    std::cout << "Number a = " << a << ", number b = " << b;
}