#include <iostream>
#include <string>
#include <sstream>

int main(){
    std::string str;
    std::cout << "Input string: ";
    std::getline(std::cin, str);
    int countWord = 0;
    // for(int i = 0; i < str.size(); i++){
    //     if((str[i + 1] == '\0' || str[i + 1] == ' ') && str[i] != ' '){
    //         countWord++;
    //     }
    // }
    std::string tmp;
    std::istringstream iss2(str);
    while (getline(iss2, tmp, ' ')){
        countWord++;
    }
    std::cout << "There is " << countWord << " in your string" << std::endl;
    return 0;
}