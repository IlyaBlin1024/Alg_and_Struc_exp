#include <iostream>
#include <string>

int main(){
    std::string str;
    std::cin >> str;
    bool change = false;
    for(int i = 0; i < str.size()/2 && str.size() != 1; i++){
        if(str[i] != 'a'){
            change = true;
            str[i] = 'a';
            break;
        }
    }
    if(!change){
        str[str.size() - 1] = 'b';
    }
    if(str.size() == 1){
       str.clear(); 
    }
    std::cout << str;
}