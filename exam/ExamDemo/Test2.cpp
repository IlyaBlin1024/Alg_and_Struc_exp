#include <iostream>
#include <string>
#include <cmath>

int main(){
    std::string sample;
    std::getline(std::cin, sample);
    char begin = 0;
    char end = 0;
    float one = 0;
    float two = 1;
    float three = 0;
    float four = 1;
    int j = 0;
    int count = 0;
    for(int i = 0; i < sample.size(); i++){
        if(sample[i] == '[' || sample[i] == '('){
            begin = sample[i];
        }
        if(sample[i] == '-' || sample[i] >= '0' && sample[i] <= '9'){
            std::string number_str;
            for(; sample[i] >= '0' && sample[i] <= '9' || sample[i] == '-';){
                number_str += sample[i];
                i++;
            }
            if(j == 0){
                one = std::stoi(number_str);
                j++;
            }else if(j == 1){
                two = std::stoi(number_str);
            }else if(j == 2){
                three = std::stoi(number_str);
                j++;
            }else if(j == 3){
                four = std::stoi(number_str);
            } 
        }
        if(sample[i] == ','){
            j++;
            count++;
        }
        if(sample[i] == ']' || sample[i] == ')'){
            end = sample[i];
        }
    }
    if(count == 0){
        three = one;
    }
    int a = std::ceil(one / two);
    int b = std::floor(three / four);
    int answer = 0;
    if(count == 0){
        if(begin == '[' && end == ']' && std::round(one) == one){
            answer++;
        }
    }else{
        answer = b - a + 1;
        if(begin == '('){
            answer -= 1;
        }
        if(end == ')'){
            answer -= 1;
        }
    }
	std::cout << answer;
}