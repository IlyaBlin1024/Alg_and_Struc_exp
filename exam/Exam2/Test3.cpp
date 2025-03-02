#include <iostream>
#include <string>

int main(){
    std::string a;
    std::string b;
    std::cin >> a;
    std::cin >> b;
    if(a.size() != b.size()){
        std::cout << "NO";
        return 0;
    }else{
        for(int i = 0; i < a.size(); i++){
            if(b.find_first_of(a[i]) != std::string::npos){
                b[b.find_first_of(a[i])] = '*';
            }else{
                std::cout << "NO";
                return 0;
            }
        }
        std::cout << "YES";
        return 0;
    }
}