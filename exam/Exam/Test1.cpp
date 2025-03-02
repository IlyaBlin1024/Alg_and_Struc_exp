#include <iostream>

int main(){
	int n = 0;
    std::cin >> n;
    int mount[n];
    int max = 0;
    for(int i = 0; i < n; i++){
        std::cin >> mount[i];
        if(mount[i] > max){
            max = i + 1;
        }
    }
    std::cout << max;
    return 0;
}