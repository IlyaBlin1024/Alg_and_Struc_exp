#include <iostream>

int main(){
    int *mas = new int[12] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    for(int b = 0; b < 12; b++){
        if(b % 2 == 0){
            int a = mas[b];
            mas[b] = mas[b+1];
            mas[b+1] = a;
        }
    }
    for(int b = 0; b < 12; b++){
        std::cout << mas[b] << " ";
    }
    delete[] mas;
}