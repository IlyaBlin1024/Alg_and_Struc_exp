#include <iostream>
#include <cmath>
#include <bitset>

const int constanta = 8;

class numbers{
public:
    std::bitset<constanta> number;
    int input_number = 0;
public:
    int check_reverse_limit = 0;
    std::bitset<constanta> do_reverse(std::bitset<constanta> number){
        for (int i = 0; i < constanta; i++){
            if (number[i] == 1){
                number[i] = 0;
            }else{
                number[i] = 1;
            }
        }
        int more_bit = 1;
        for (int i = 0; i < constanta; i++){
            if (number[i] + more_bit == 2){
                number[i] = 0;
                more_bit = 1;
            }else if (number[i] + more_bit == 1){
                number[i] = 1;
                more_bit = 0;
                break;
            }
        }
        return number;
    }

    int do_num(std::bitset<constanta> operation_result){
        int result = 0;
        if (operation_result[constanta - 1] == 0){
            for (int i = 0; i < constanta; i++){
                result += operation_result[i] * pow(2, i);
            }
        }else{
            operation_result = do_reverse(operation_result);
            for (int i = 0; i < constanta; i++){
                result += operation_result[i] * pow(2, i);
            }
            result *= -1;
        }
        return result;
    }

    bool do_bin(int input_number, std::bitset<constanta> &number){
        int num_to_bits = 0;
        int bits_limit = 0;
        if (input_number < 0){
            number[constanta - 1] = 1;
            num_to_bits = std::abs(input_number + 1);
        }else{
            number[constanta - 1] = 0;
            num_to_bits = input_number;
        }
        while (bits_limit < constanta){
            if (num_to_bits / 2 != 0){
                number[bits_limit] = num_to_bits % 2;
                num_to_bits /= 2;
                bits_limit++;
            }else{
                number[bits_limit] = num_to_bits % 2;
                bits_limit++;
                break;
            }
        }
        if (bits_limit == constanta){
            return false;
        }
        else{
            if (input_number < 0){
                for (int i = 0; i < constanta - 1; i++){
                    if (number[i] == 0){
                        number[i] = 1;
                    }else{
                        number[i] = 0;
                    }
                }
            }
            return true;
        }
    }

    bool get_number(){
        if (do_bin(input_number, number)){
            return true;
        }else{
            return false;
        }
    }

    bool do_plus(numbers num_1_in, numbers num_2_in){
        int more_bit = 0;
        std::bitset<constanta> sum;
        for (int i = 0; i < constanta; i++){
            if (num_1_in.number[i] + num_2_in.number[i] + more_bit == 3){
                sum[i] = 1;
                more_bit = 1;
            }else if (num_1_in.number[i] + num_2_in.number[i] + more_bit == 2){
                sum[i] = 0;
                more_bit = 1;
            }else if (num_1_in.number[i] + num_2_in.number[i] + more_bit == 1){
                sum[i] = 1;
                more_bit = 0;
            }else if (num_1_in.number[i] + num_2_in.number[i] + more_bit == 0){
                sum[i] = 0;
                more_bit = 0;
            }
        }

        if (check_reverse_limit == 1){
            more_bit = 1;
            for (int i = 0; i < constanta; i++){
                if (sum[i] + more_bit == 2){
                    sum[i] = 0;
                    more_bit = 1;
                }else if (sum[i] + more_bit == 1){
                    sum[i] = 1;
                    more_bit = 0;
                }else if (sum[i] + more_bit == 0){
                    sum[i] = 0;
                    more_bit = 0;
                }
            }
        }
        if (num_1_in.number[constanta - 1] == 1 && num_2_in.number[constanta - 1] == 1 && sum[constanta - 1] == 0 ||
            num_1_in.number[constanta - 1] == 0 && num_2_in.number[constanta - 1] == 0 && sum[constanta - 1] == 1){
            return false;
        }
        input_number = do_num(sum);
        number = sum;
        return true;
    }

    bool do_minus(numbers num_1_in, numbers num_2_in){
        if (do_reverse(num_2_in.number) == num_2_in.number){
            check_reverse_limit = 1;
            for (int i = 0; i < constanta; i++){
                if (num_2_in.number[i] == 0){
                    num_2_in.number[i] = 1;
                }else{
                    num_2_in.number[i] = 0;
                }
            }
        }else{
            num_2_in.number = do_reverse(num_2_in.number);
        }
        if (do_plus(num_1_in, num_2_in)){
            return true;
        }else{
            return false;
        }
    }

    bool do_multiply(numbers num_1_in, numbers num_2_in){
        std::bitset<constanta> mult;
        std::bitset<constanta> mult_num_1;
        std::bitset<constanta> mult_num_2;
        int count_num_1 = 0;
        int count_num_2 = 0;
        for(int i = 0; i < constanta; i++){
            if(num_1_in.number[i] == 1){
                count_num_1++;
                break;
            }
        }
        for(int i = 0; i < constanta; i++){
            if(num_2_in.number[i] == 1){
                count_num_2++;
                break;
            }
        }
        if (num_1_in.number[constanta - 1] == 1){
            mult_num_1 = do_reverse(num_1_in.number);
        }else{
            mult_num_1 = num_1_in.number;
        }
        if (num_2_in.number[constanta - 1] == 1){
            mult_num_2 = do_reverse(num_2_in.number);
        }else{
            mult_num_2 = num_2_in.number;
        }
        int more_bit = 0;
        for (int i = 0; i < constanta; i++){
            if (mult_num_2[i] == 1){
                for (int j = 0; j < constanta; j++){
                    if (i + j > constanta - 1 && more_bit + mult_num_1[j] * mult_num_2[i] + mult[i + j] > 0){
                        return false;
                    }
                    if (more_bit + mult_num_1[j] * mult_num_2[i] + mult[i + j] == 3){
                        mult[i + j] = 1;
                        more_bit = 1;
                    }
                    else if (more_bit + mult_num_1[j] * mult_num_2[i] + mult[i + j] == 2){
                        mult[i + j] = 0;
                        more_bit = 1;
                    }else if (more_bit + mult_num_1[j] * mult_num_2[i] + mult[i + j] == 1){
                        mult[i + j] = 1;
                        more_bit = 0;
                    }else if (more_bit + mult_num_1[j] * mult_num_2[i] + mult[i + j] == 0){
                        mult[i + j] = 0;
                        more_bit = 0;
                    }
                }
            }
        }
        if (num_1_in.number[constanta - 1] == 1 && num_2_in.number[constanta - 1] == 0 || 
            num_1_in.number[constanta - 1] == 0 && num_2_in.number[constanta - 1] == 1){
            mult = do_reverse(mult);
        }
        if(count_num_1 == 1 && count_num_2 == 1){
            if (num_1_in.number[constanta - 1] == 1 && num_2_in.number[constanta - 1] == 1 && mult[constanta - 1] == 1 ||
                num_1_in.number[constanta - 1] == 0 && num_2_in.number[constanta - 1] == 0 && mult[constanta - 1] == 1 ||
                num_1_in.number[constanta - 1] == 1 && num_2_in.number[constanta - 1] == 0 && mult[constanta - 1] == 0 ||
                num_1_in.number[constanta - 1] == 0 && num_2_in.number[constanta - 1] == 1 && mult[constanta - 1] == 0){
                return false;
            }
        }
        number = mult;
        input_number = do_num(number);
        return true;
    }
};

class nums{
public:
    struct Calculations{
        numbers value;
        struct Calculations* previous;
    };
    struct Calculations* end = NULL;
    struct Calculations* move = NULL;
public:
    bool isEmpty(){
        if(end == NULL)
            return true;
        return false;
    }

    void push(numbers smth){
        struct Calculations* ptr;
        ptr = new Calculations();
        ptr->value = smth;
        if (isEmpty()){
            ptr->previous = NULL;
            end = ptr;
        }else{
            ptr->previous = end;
            end = ptr;
        }
    }

    void pop(){
        struct Calculations* ptr;
        ptr = end;
        if(end->previous == NULL){
            end = NULL;
            delete ptr;
        }else{
            end = ptr->previous;
            delete ptr;
        }
    }

    int stacksize()
    {
        int size = 0;
        if (!isEmpty()){
            struct Calculations* ptr = end;
            while (ptr != NULL) {
                size++;
                ptr = ptr->previous;
            }
        }
        return size;
    }

    void Calculating(std::string sample, nums &input_nums){
        for(int i = 0; i < sample.size(); i++){
            if(sample[i] >= '0' && sample[i] <= '9'){
                numbers input;
                std::string number_str;
                for(; sample[i] >= '0' && sample[i] <= '9'; i++){
                    if(sample[i] >= '0' && sample[i] <= '9'){
                        number_str += sample[i];
                    }
                    if(sample[i + 1] != ' ' && (sample[i + 1] < '0' || sample[i + 1] > '9')){
                        throw "Invalid input!";
                    }
                }
                input.input_number = std::stoi(number_str);
                if(!input.get_number())
                    throw "Number of bytes are limited!";
                input_nums.push(input);
            }else if(sample[i] == '+' || sample[i] == '-' || sample[i] == '*' || sample[i] == ' '){
                numbers result;
                bool check = true;
                if(sample[i] == '-' && sample[i + 1] >= '0' && sample[i + 1] <= '9'){
                    std::string number_str = "-";
                    i++;
                    for(; sample[i] >= '0' && sample[i] <= '9'; i++){
                        if(sample[i] >= '0' && sample[i] <= '9'){
                            number_str += sample[i];
                        }else if(sample[i + 1] == ' '){
                            break;
                        }else{
                            throw "Invalid input!";
                        }
                    }
                    result.input_number = std::stoi(number_str);
                    if(!result.get_number())
                        throw "Number of bytes are limited!";
                    input_nums.push(result);
                }else if(check){
                    if(input_nums.stacksize() <= 1){
                        throw "Invalid input!";
                    }
                    if(sample[i] == '+'){
                        if(!result.do_plus(input_nums.end->value, input_nums.end->previous->value)){
                            throw "The number of bytes are limited!";
                        }
                    }else if(sample[i] == '*'){
                        if(!result.do_multiply(input_nums.end->value, input_nums.end->previous->value)){
                            throw "The number of bytes are limited!";
                        }
                    }else if(sample[i] == '-'){
                        if(sample[i] == '-' && !result.do_minus(input_nums.end->value, input_nums.end->previous->value)){
                            throw "The number of bytes are limited!";
                        }
                    }
                    if(sample[i] != ' '){
                        input_nums.pop();
                        input_nums.pop();
                        input_nums.push(result);
                    }
                }else if(check){
                    throw "Invalid sample!";
                }
            }else{
                throw "Invalid input!";
            }
        }
    }

    void printResult(){
        struct Calculations* ptr = end; 
        std::cout << "Number: " << ptr->value.input_number << std::endl;
        std::cout << "Binnary number: " << ptr->value.number << std::endl;
    }
};

int main(){
    try{
        while(true){
            std::cout << std::endl;
            std::string sample;
            nums input_nums;
            std::cout << "Input sample: ";
            std::getline(std::cin, sample);
            input_nums.Calculating(sample, input_nums);
            if(input_nums.stacksize() == 1){
                input_nums.printResult();
            }else if(input_nums.stacksize() == 0){
                throw "Input something!";
            }else{
                throw "Not enough operations!";
            }
        }
    }catch(const char *input_error){
        std::cerr << input_error << std::endl;
    }
}