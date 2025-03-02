#include <iostream>

int main(){
    const float human {1};
    const float *const ptr = &human;
    std::cout << "Human: " << human << "\nHis adress: " << ptr;

    typedef long int length;
    length man = 125;
    length woman = 100;
    std::cout << "\n\nA man length: " << man << "\nA woman length: " << woman;

    double num = 25.4;
    double *dPtr = &num;
    std::cout << "\n\nNumber adress: " << dPtr;

    short int num1 = 7;
    short int *siPtr = &num1;
    std::cout << "\n\nNumber adress: " << siPtr;

    typedef const float *const fPtr;
    fPtr num3 = &human;
    std::cout << "\n\nConst: " << num3;

    typedef const char *chPtr;
    const char bloodG = 'A';
    chPtr bG = &bloodG;
    std::cout << "\n\nBlood group adress: " << bG;

    double weight = 70.5;
    double *const wPtr = &weight;
    std::cout << "\n\nWeight: " << wPtr;

    typedef unsigned int *const number;
    unsigned int num4 = 60;
    number nPtr = &num4;
    std::cout << "\n\nNumber: " << nPtr;
}