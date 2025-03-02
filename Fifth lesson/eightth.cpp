#include <iostream>
#include <sstream>
#include <string>

int main(){
    std::string str;
    std::cout << "Input string: ";
    std::getline(std::cin, str);
    int begin = 0;
    std::string longWord;
    for(int i = 0; i < str.size(); i++){
        std::string word;
        if(str[i] == ' ' && (str[i + 1] != ' ' || str[i + 1] != '\0')){
            begin = i + 1;
        }
        if(str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0')){
            word = str.substr(begin, i - begin + 1);
            if(word.size() > longWord.size()){
                longWord = word;
            }
        }
    }
    std::cout << "\nLength " << longWord.size() << "\nWord: " << longWord << std::endl;
}