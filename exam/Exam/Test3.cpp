#include <iostream>

int main(){
    std::string a;
    std::string b;
    std::cin >> a;
    std::cin >> b;
    int bull = 0;
    int cow = 0;
    bool check_a[a.size()];
    bool check_b[b.size()];
    for(int i = 0; i < a.size(); i++){
        check_a[i] = true;
        check_b[i] = true;
    }
    for(int i = 0; i < a.size(); i++){
        if(a[i] == b[i]){
            bull++;
            check_a[i] = false;
            check_b[i] = false;
        }
    }
    for(int i = 0; i < a.size(); i++){
        if(check_a[i]){
            for(int j = 0; j < b.size(); j++){
                if(check_b[j] && a[i] == b[j]){
                    cow++;
                    check_a[i] = false;
                    check_b[j] = false;
                    break;
                }
            }
        }
    }
    std::cout << bull << std::endl << cow << std::endl;
    return 0;
}