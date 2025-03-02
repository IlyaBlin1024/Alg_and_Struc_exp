#include <iostream>
#include <string>

int main(){
    std::string str;
    std::cin >> str;
    while(true){
        if(str[0] == str[str.size() - 1] && str.size() - 1 != 0 && str.size() != 0){
            int i = 0;
            for(; str[i] == str[0] && str.size() > 1 && i < str.size(); i++){}
            int j = 0;
            for(; str[str.size() - 1 - j] == str[str.size() - 1] && str.size() > 1 && i < str.size(); j++){}
            str = str.substr(i, str.size() - i - j);
        }else{
            break;
        }
    }
    std::cout << str.size();
}