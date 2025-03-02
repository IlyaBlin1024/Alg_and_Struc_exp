#include <iostream>

int sumValue(int price1, int num1, int price2, int num2, int price3, int num3){
    int sum = price1 * num1 + price2 * num2 + price3 * num3;
    return sum;
}

int main(){
    std:: cout << "Put your prices: ";
    int price1 = 0;
    int price2 = 0;
    int price3 = 0;
    std::cin >> price1 >> price2 >> price3;
    std::cout << "Put numbers of products respectively: ";
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;
    std::cin >> num1 >> num2 >> num3;
    std::cout << "\nYour total price: " << sumValue(price1, num1, price2, num2, price3, num3);
    return 0;
}