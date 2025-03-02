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
            }else{
                number[bits_limit] = num_to_bits % 2;
                break;
            }
            bits_limit++;
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
        if(num_1_in.number[constanta - 1] == 1){
            count_num_1++;
        }
        if(num_2_in.number[constanta - 1] == 1){
            count_num_2++;
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

int main(){
    std::cout << std::endl;
    char operation;
    numbers result;
    numbers num_1;
    numbers num_2;
    try{
        std::cout << "Input first number: ";
        std::cin >> num_1.input_number;
        if (std::cin.fail()){
            throw "\nError! You must input a number.";
        }
        std::cout << "Input second number: ";
        std::cin >> num_2.input_number;
        if (std::cin.fail()){
            throw "\nError! You must input a number.";
        }
        std::cout << "\nInput operation: ";
        std::cin >> operation;
        if (std::cin.fail()){
            throw "\nError! You must input an operator.";
        }else if (operation != '+' && operation != '-' && operation != '*'){
            throw "\nError! You must input one of these operators: +, -, *.";
        }
        if (!num_1.get_number() || !num_2.get_number()){
            throw "\nError! The number of bytes is limited!";
        }else{
            std::cout << "\nBinnary first number: " << num_1.number << std::endl;
            std::cout << "Binnary second number: " << num_2.number << std::endl;
        }
        if (operation == '+' && !result.do_plus(num_1, num_2) || operation == '-' && !result.do_minus(num_1, num_2) ||
            operation == '*' && !result.do_multiply(num_1, num_2)){
            throw "\nError! The number of bytes is limited!";
        }else{
            std::cout << "\nBinnary result: " << result.number << std::endl;
            std::cout << "Result: " << result.input_number << std::endl;
        }
    }catch (const char *input_error){
        std::cerr << input_error << std::endl;
    }
    return 0;
}