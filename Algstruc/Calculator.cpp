#include <iostream>
#include <vector>
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

class operators{
public:
    struct Calculations{
        char value;
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

    void push(char smth){
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
        if (isEmpty())
            throw "Stack is empty";
        else if(end->previous == NULL){
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
        if (isEmpty())
            throw "Stack is empty";
        else if(end->previous == NULL){
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
        if (isEmpty())
            printf("Stack is empty");
        else {
            struct Calculations* ptr = end;
            while (ptr != NULL) {
                size++;
                ptr = ptr->previous;
            }
        }
        return size;
    }

    void Calculating(nums &input_nums, operators &oper, const std::string sample){
        for(int i = 0; i < sample.length(); i++){
            if(sample[i] != '(' && sample[i] != '+' && sample[i] != '*' && (sample[i] < '0' || 
               sample[i] > '9') && sample[i] != ')' && sample[i] != '-' && sample[i] != ' '){
                throw "Invalid input!";
            }
            if(sample[i] >= '0' && sample[i] <= '9'){
                numbers input;
                std::string number_str;
                for(int j = 0; sample[i] >= '0' && sample[i] <= '9'; ++j){
                    number_str += sample[i];
                    i++;
                }
                input.input_number = std::stoi(number_str);
                if(!input.get_number())
                    throw "Number of bytes are limited!";
                input_nums.push(input);
            }
            if(sample[i] == '(' || sample[i] == '+' || sample[i] == '*'){
                oper.push(sample[i]);
            }
            if(sample[i] == '-'){
                bool check = true;
                for(int j = 0; sample[i - j] != '('; j++){
                    if(i - j == 0){
                        break;
                    }
                    if(sample[i - j] >= '0' && sample[i - j] <= '9' || sample[i - j] == ')'){
                        check = false;
                        break;
                    }
                }
                if(input_nums.end == NULL || check){
                    numbers input;
                    std::string number_str;
                    std::string minus_one;
                    for(int j = 0; sample[i + j] != '('; ++j){
                        if(sample[i + j + 1] == '('){
                            minus_one = "-1";
                        }else if(sample[i + j + 1] >= '0' && sample[i + j + 1] <= '9' || sample[i + j + 1] == '+' ||
                                 sample[i + j + 1] == '*' || sample[i + j + 1] == '-'){
                            break;
                        } 
                    }
                    for(int j = 0; sample[i] >= '0' && sample[i] <= '9' || j == 0 && sample[i] == '-' || sample[i] == ' '; j++){
                        if(sample[i] >= '0' && sample[i] <= '9' || sample[i] == '-' && j == 0)
                            number_str += sample[i];
                            i++;
                    }
                    i--;
                    if(minus_one.size() == 0){
                        input.input_number = std::stoi(number_str);
                        if(!input.get_number())
                            throw "Number of bytes are limited!";
                        input_nums.push(input);
                    }else{
                        input.input_number = std::stoi(minus_one);
                        input.get_number();
                        input_nums.push(input);
                        oper.push('*');
                    }
                }else{
                    oper.push(sample[i]);
                }
            }
            if(sample[i] == ')'){
                int oper_count = 0;
                if(oper.end == NULL)
                    throw "This equation is wrong!";
                oper.move = oper.end;
                bool check = false;
                int k = oper.stacksize();
                for(; k > 0; k--){
                    if(oper.move->value == '('){
                        check = true;
                        break;
                    }else if(oper.move->value == '+' || oper.move->value == '-' || oper.move->value == '*'){
                        oper_count++;
                    }
                    oper.move = oper.move->previous;
                }
                for(; k > 0; k--){
                    if(oper.move->value == '+' || oper.move->value == '-' || oper.move->value == '*'){
                        oper_count++;
                    }
                    oper.move = oper.move->previous;
                }
                if(!check || oper_count == input_nums.stacksize() || oper_count != input_nums.stacksize() - 1)
                    throw "This equation is wrong!";
                input_nums.move = input_nums.end;
                oper.move = oper.end;
                while(oper.move->value != '('){
                    if(oper.move->value == '*'){
                        numbers result;
                        if(!result.do_multiply(input_nums.move->value, input_nums.move->previous->value))
                            throw "The number of bytes are limited!";
                        std::vector <numbers> save;
                        std::vector <char> save_oper;
                        while(input_nums.end != input_nums.move){
                            save.push_back(input_nums.end->value);
                            input_nums.pop();
                        }
                        input_nums.pop();
                        input_nums.pop();
                        input_nums.push(result);
                        input_nums.move = input_nums.end;
                        while(oper.end != oper.move){
                            save_oper.push_back(oper.end->value);
                            oper.pop();
                        }
                        oper.pop();
                        oper.move = oper.end;
                        for(int j = 0; j < save_oper.size(); j++){
                            oper.push(save_oper[save_oper.size() - 1 - j]);
                        }
                        for(int j = 0; j < save.size(); j++){
                            input_nums.push(save[save.size() - 1 - j]);
                        }
                    }
                    if(oper.end->value != '*'){
                        if(input_nums.move != NULL || input_nums.move->previous != NULL){
                            input_nums.move = input_nums.move->previous;
                        }
                        if(oper.move->value != '(' && (oper.move != NULL || oper.move->previous != NULL)){
                            oper.move = oper.move->previous;
                        }
                    }
                }
                while(oper.end->value != '('){
                    std::vector <char> save_oper;
                    std::vector <numbers> save_num;
                    for(int j = 0; oper.end->previous->value != '('; j++){
                        save_num.push_back(input_nums.end->value);
                        save_oper.push_back(oper.end->value);
                        oper.pop();
                        input_nums.pop();
                    }
                    if(oper.end->value == '+'){
                        numbers result;
                        if(!result.do_plus(input_nums.end->value, input_nums.end->previous->value))
                            throw "The number of bytes are limited!";
                        input_nums.pop();
                        input_nums.pop();
                        input_nums.push(result);
                        oper.pop();
                    }else if(oper.end->value == '-'){
                        numbers result;
                        if(!result.do_minus(input_nums.end->previous->value, input_nums.end->value))
                            throw "The number of bytes are limited!";
                        input_nums.pop();
                        input_nums.pop();
                        input_nums.push(result);
                        oper.pop();
                    }
                    for(int j = 0; j < save_num.size(); j++){
                        input_nums.push(save_num[save_num.size() - 1 - j]);
                    }
                    for(int j = 0; j < save_oper.size(); j++){
                        oper.push(save_oper[save_oper.size() - 1 - j]);
                    }
                }
                if(oper.end->value == '('){
                    oper.pop();
                }
            }
        }
        int oper_count_1 = 0;
        oper.move = oper.end;
        for(int j = oper.stacksize(); j > 0; j--){
            if(oper.move->value == '+' || oper.move->value == '-' || oper.move->value == '*'){
                oper_count_1++;
            }
            oper.move = oper.move->previous;
        }
        if(oper_count_1 == input_nums.stacksize() || oper_count_1 != input_nums.stacksize() - 1)
            throw "This equation is wrong!";
        input_nums.move = input_nums.end;
        oper.move = oper.end;
        while(oper.move != NULL){
            if(oper.move->value == '*'){
                numbers result;
                if(!result.do_multiply(input_nums.move->value, input_nums.move->previous->value))
                    throw "The number of bytes are limited!";
                std::vector <numbers> save;
                std::vector <char> save_oper;
                while(input_nums.end != input_nums.move){
                    save.push_back(input_nums.end->value);
                    input_nums.pop();
                }
                input_nums.pop();
                input_nums.pop();
                input_nums.push(result);
                input_nums.move = input_nums.end;
                while(oper.end != oper.move){
                    save_oper.push_back(oper.end->value);
                    oper.pop();
                }
                oper.pop();
                oper.move = oper.end;
                bool check_in = false;
                if(oper.move == NULL){
                    check_in = true;
                }
                for(int j = 0; j < save_oper.size(); j++){
                    oper.push(save_oper[save_oper.size() - 1 - j]);
                }
                for(int j = 0; j < save.size(); j++){
                    input_nums.push(save[save.size() - 1 - j]);
                }
                if(check_in == true){
                    break;
                }
            }
            if(input_nums.move != NULL || input_nums.move->previous != NULL){
                input_nums.move = input_nums.move->previous;
            }
            if(!oper.isEmpty() || oper.move != NULL || oper.move->previous != NULL)
                oper.move = oper.move->previous;
            }
        while(oper.end != NULL){
            std::vector <char> save_oper;
            std::vector <numbers> save_num;
            for(int j = 0; oper.end->previous != NULL; j++){
                save_num.push_back(input_nums.end->value);
                save_oper.push_back(oper.end->value);
                oper.pop();
                input_nums.pop();
            }
            if(oper.end->value == '+'){
                numbers result;
                if(!result.do_plus(input_nums.end->value, input_nums.end->previous->value))
                    throw "The number of bytes are limited!";
                input_nums.pop();
                input_nums.pop();
                input_nums.push(result);
                oper.pop();
            }else if(oper.end->value == '-'){
                numbers result;
                if(!result.do_minus(input_nums.end->previous->value, input_nums.end->value))
                    throw "The number of bytes are limited!";
                input_nums.pop();
                input_nums.pop();
                input_nums.push(result);
                oper.pop();
            }
            for(int j = 0; j < save_num.size(); j++){
                input_nums.push(save_num[save_num.size() - 1 - j]);
            }
            for(int j = 0; j < save_oper.size(); j++){
                oper.push(save_oper[save_oper.size() - 1 - j]);
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
            std::string sample;
            nums input_nums;
            operators oper;
            std::cout << "Input sample(using these operations: +, -, *, (, )): ";
            std::getline(std::cin, sample);
            input_nums.Calculating(input_nums, oper, sample);
            if(oper.isEmpty()){
                input_nums.printResult();
            }
        }
    }catch(const char *input_error){
        std::cerr << input_error << std::endl;
    }
    return 0;
}