#include <iostream>
#include <string>
#include <set>

int main(){
    std::set <std::string> str;
    std::string a;
    while(std::getline(std::cin, a)){
        int beg = 0;
        for(size_t i = 0; i < str.size(); i++){
            if(a[i] == ' '){
                beg = i + 1;
            }
            if(a[i] == '/'){
                str.insert(a.substr(beg, i + 1 - beg));
            }
        }
    }

    std::cout << std::endl;

    for(std::set <std::string>::iterator i = str.begin(); i != str.end(); i++){
        std::cout << *i << std::endl;
    }
    return 0 ;
}