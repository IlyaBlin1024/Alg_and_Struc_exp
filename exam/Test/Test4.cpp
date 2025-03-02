#include <iostream>
#include <vector>

int main(){
    int n = 0;
    std::cin >> n;
    std::vector <int> sum;
    for(int i = 0; i < n; i++){
        int a = 0;
        std::cin >> a;
        sum.push_back(a);
    }
    std::vector<int> news;
    std::vector <bool> check(n, true);
    int begin = check[0];
    for(int i = 0; i < sum.size(); i++){
        if(news.size() == sum.size() / 2){
            break;
        }
        if(check[i]){
            
        }
    }
    for(int i = 0; i < news.size(); i++){
        std::cout << news[i] << std::endl;
    }
    return 0;
}