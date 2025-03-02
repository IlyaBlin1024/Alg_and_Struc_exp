#include <iostream>
using namespace std;

int mult(int x, int y){
    int res = x * y;
    return res;
}

int summ(int x, int y){
    int res = x + y;
    return res;
}

float average(int x, int y){
    float res = (x + y) / 2.f;
    return res;
}

float difference(int x, int y){
    float res = x - y;
    return res;
}

int main(){
    cout << "Input two numbers: ";
    int x = 0;
    int y = 0;
    cin >> x;
    cin >> y;
    cout << "\nMultiplication is: " << mult(x, y) << "\nSum is: " << summ(x, y) << "\nAverage is: " << average(x, y) << "\nDifference (first - second) is: " << difference(x, y) << endl;
}