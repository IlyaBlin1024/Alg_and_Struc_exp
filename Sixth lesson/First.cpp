#include <iostream>
#include <vector>
#include <list>

double mid(const std::list <double> &num){
    double sum = 0;
    for(std::list<double>::const_iterator i = num.begin(); i != num.end(); i++){ //или подставьте auto вместо std::list<double>::const_iterator
        sum += *i;
    }
    return sum / num.size();
}

int main(){
    std::list <double> num;
    for(int i = 0; i < 10; i++){
        std::cout << "Input number: ";
        int a = 0;
        std::cin >> a;
        num.push_back(a);
    }
    num.push_back(mid(num));
    for(std::list<double>::iterator i = num.begin(); i != num.end(); i++){
        std::cout << *i << " ";
    }
    return 0;
}