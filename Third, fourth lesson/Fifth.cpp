#include <iostream>

int plus(int *num1, int *num2){
    return *num1 + *num2;
}

int minus(int *num1, int *num2){
    return *num1 - *num2;
}

int mult(int *num1, int *num2){
    return *num1 * *num2;
}

int dev(int *num1, int *num2){
    return *num1 / *num2;
}

int result(int (*operation)(int*, int*), int num1, int num2, char oper){
    int res = 0;
    res = operation(&num1, &num2);
    return res;
}

int main(){
    char oper = 0;
    int num1 = 0;
    int num2 = 0;
    while(oper != '_'){
        std::cout << "Input numbers values: ";
        std::cin >> num1 >> num2;
        std::cout << "Input operation: ";
        std::cin >> oper;
        if(oper == '+' || oper == '-' || oper == '*' || oper == '/' || oper == '_'){
            switch(oper){
                case '+':
                    std::cout << "Result: " << result((*plus), num1, num2, oper);
                    break;
                case '-':
                    std::cout << "Result: " << result((*minus), num1, num2, oper);
                    break;
                case '*':
                    std::cout << "Result: " << result((*mult), num1, num2, oper);
                    break;
                case '/':
                    std::cout << "Result: " << result((*dev), num1, num2, oper);
                    break;
                case '_':
                    break;
            }
            std::cout << std::endl;
        }else{
            std::cerr << "\nError! Invalid value input. Try again.\n";
        }
    }
    std::cout << "The end of calculations. See you later!\n";
}