#include <iostream>
#include <map>

int main(){
    std::string name;
    std::string value;
    std::string num = 0;
    std::multimap<std::string, std::string> values;
    while(std::cin >> name >> value >> num){
        values.insert(std::pair<std::string, std::string>(name, value);
    }
    std::string name_1;
    for(auto i = values.begin(); i != values.end();){
        if(name_1 != i->first){
            name_1 = i->first;
            std::cout << name << ":" << std::endl;
        }
        std::cout << i->second.first << " " << i->second.second;
    }
}