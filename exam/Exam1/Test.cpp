#include <iostream>

int main(){
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    int matrix[n][m];
    int count_minus = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cin >> matrix[i][j];
            if(matrix[i][j] < 0){
                count_minus++;
            }
        }
    }
    std::cout << count_minus;
}