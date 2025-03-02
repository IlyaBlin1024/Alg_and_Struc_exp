#include <iostream>

int main(){
    int a = 0;
    int b = 0;
    int l = 0;
    int N = 0;
    std::cin >> a >> b >> l >> N;
    int answer = l * 2 + (N - 1) * b * 2 + a * (N - 1) * 2 + a;
    std::cout << answer;
}