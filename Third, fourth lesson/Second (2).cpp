#include <iostream>

void mas1(double **ptr, int a){
    *ptr = new double[a];
}

void mas2(double *ptr, int a){
    double num = 0;
    for(int b = 0; b < a; b++){
        ptr[b] = num;
        num += 1;
    }
}

void mas3(double **ptr, int a){
    for(int b = 0; b < a; b++){
        std::cout << &ptr[b] << " ";
    }
    for(int b = 0; b < a; b++){
        std::cout << ptr[b] << " ";
    }
}

void mas4(double *ptr, int a){
    delete[] ptr;
}

int main(){
    int d = 0;
    std::cout << "Input massive length: ";
    std::cin >> d;
    double *masPtr = nullptr;
    mas1(&masPtr, d);
    mas2(masPtr, d);
    mas3(&masPtr, d);
    mas4(masPtr, d);
}