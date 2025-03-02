#include <iostream>

int random(int min, int max){
    int number = min + rand() % (max - min + 1);
    return number;
}

void arrayFill(int** numbers){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            numbers[i][j] = random(10, 50);
        }
    }
}

void printArray(int** numbers){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            std::cout << numbers[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main(){
    srand(time(NULL));
    int **numbers = new int*[10];
    for(int i = 0; i < 10; i++){
        numbers[i] = new int[10];
    }
    arrayFill(numbers);
    printArray(numbers);
    for(int i = 0; i < 10; i++){
        delete[] numbers[i];
    }
    delete[] numbers;
}