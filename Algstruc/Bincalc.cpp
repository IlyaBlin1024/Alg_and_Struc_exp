#include <iostream>
#include <cmath>
#include <bitset>

const int constanta = 8;

class numbers{
public:
    std::bitset<constanta> number_1;
    std::bitset<constanta> number_2;
    std::bitset<constanta> result_bin;
    char operation;
    int input_number_1 = 0;
    int input_number_2 = 0;
    int result_num = 0;
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
    bool get_numbers(){
        if (do_bin(input_number_1, number_1) && do_bin(input_number_2, number_2)){
            return true;
        }else{
            return false;
        }
    }

    bool do_plus(){
        int more_bit = 0;
        std::bitset<constanta> sum;
        for (int i = 0; i < constanta; i++){
            if (number_1[i] + number_2[i] + more_bit == 3){
                sum[i] = 1;
                more_bit = 1;
            }else if (number_1[i] + number_2[i] + more_bit == 2){
                sum[i] = 0;
                more_bit = 1;
            }else if (number_1[i] + number_2[i] + more_bit == 1){
                sum[i] = 1;
                more_bit = 0;
            }else if (number_1[i] + number_2[i] + more_bit == 0){
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
        if (number_1[constanta - 1] == 1 && number_2[constanta - 1] == 1 && sum[constanta - 1] == 0 ||
            number_1[constanta - 1] == 0 && number_2[constanta - 1] == 0 && sum[constanta - 1] == 1){
            return false;
        }
        result_num = do_num(sum);
        result_bin = sum;
        return true;
    }

    bool do_minus(){
        if (do_reverse(number_2) == number_2){
            check_reverse_limit = 1;
            for (int i = 0; i < constanta; i++){
                if (number_2[i] == 0){
                    number_2[i] = 1;
                }else{
                    number_2[i] = 0;
                }
            }
        }else{
            number_2 = do_reverse(number_2);
        }
        if (do_plus()){
            return true;
        }else{
            return false;
        }
    }

    bool do_multiply(){
        std::bitset<constanta> mult;
        std::bitset<constanta> mult_num_1;
        std::bitset<constanta> mult_num_2;
        int count_num_1 = 0;
        int count_num_2 = 0;
        for(int i = 0; i < constanta; i++){
            if(number_1[i] == 1){
                count_num_1++;
                break;
            }
        }
        for(int i = 0; i < constanta; i++){
            if(number_2[i] == 1){
                count_num_2++;
                break;
            }
        }
        if (number_1[constanta - 1] == 1){
            mult_num_1 = do_reverse(number_1);
        }else{
            mult_num_1 = number_1;
        }
        if (number_2[constanta - 1] == 1){
            mult_num_2 = do_reverse(number_2);
        }else{
            mult_num_2 = number_2;
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
                        more_bit = 1;
                    }else if (more_bit + mult_num_1[j] * mult_num_2[i] + mult[i + j] == 1){
                        mult[i + j] = 1;
                        more_bit = 0;
                    }else if (more_bit + mult_num_1[j] * mult_num_2[i] + mult[i + j] == 0){
                        more_bit = 0;
                    }
                }
            }
        }
        if (number_1[constanta - 1] == 1 && number_2[constanta - 1] == 0 || number_1[constanta - 1] == 0 && number_2[constanta - 1] == 1){
            mult = do_reverse(mult);
        }
        if(count_num_1 == 1 && count_num_2 == 1){
            if (number_1[constanta - 1] == 1 && number_2[constanta - 1] == 1 && mult[constanta - 1] == 1 ||
                number_1[constanta - 1] == 0 && number_2[constanta - 1] == 0 && mult[constanta - 1] == 1 ||
                number_1[constanta - 1] == 1 && number_2[constanta - 1] == 0 && mult[constanta - 1] == 0 ||
                number_1[constanta - 1] == 0 && number_2[constanta - 1] == 1 && mult[constanta - 1] == 0){
                return false;
            }
        }
        result_bin = mult;
        result_num = do_num(result_bin);
        return true;
    }
};

int main()
{
    std::cout << std::endl;
    numbers sample;
    try{
        std::cout << "Input first number: ";
        std::cin >> sample.input_number_1;
        if (std::cin.fail()){
            throw "\nError! You must input a number.";
        }
        std::cout << "Input second number: ";
        std::cin >> sample.input_number_2;
        if (std::cin.fail()){
            throw "\nError! You must input a number.";
        }
        std::cout << "\nInput operation: ";
        std::cin >> sample.operation;
        if (std::cin.fail()){
            throw "\nError! You must input an operator.";
        }else if (sample.operation != '+' && sample.operation != '-' && sample.operation != '*'){
            throw "\nError! You must input one of these operators: +, -, *.";
        }
        if (!sample.get_numbers()){
            throw "\nError! The number of bytes is limited!";
        }else{
            std::cout << "\nBinnary first number: " << sample.number_1 << std::endl;
            std::cout << "Binnary second number: " << sample.number_2 << std::endl;
        }
        if (sample.operation == '+' && !sample.do_plus() || sample.operation == '-' && !sample.do_minus() ||
            sample.operation == '*' && !sample.do_multiply()){
            throw "\nError! The number of bytes is limited!";
        }else{
            std::cout << "\nBinnary result: " << sample.result_bin << std::endl;
            std::cout << "Result: " << sample.result_num << std::endl;
        }
    }
    catch (const char *input_error){
        std::cerr << input_error << std::endl;
    }
    return 0;
}