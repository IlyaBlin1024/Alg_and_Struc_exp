#include <iostream>
#include <vector>

int main(){
    int n = 0;
    std::cin >> n;
    std::vector<int> nums;
    for(int i = 0; i < n; i++){
        int a = 0;
        std::cin >> a;
        nums.push_back(a);
    }
    int count_max = 0;
    int max_num = 0;
    int max_num_pos = 0;
    int i = 0;
    while(nums.size() != 0){
        if(nums.size() == 0){
            break;
        }
        if(nums[i] > max_num){
            max_num = nums[i];
            max_num_pos = i;
        }
        if(i + 1 == nums.size()){
            i = -1;
            if(max_num_pos + 1 != nums.size()){
                nums.erase(nums.begin() + max_num_pos + 1);
            }
            if(max_num_pos != 0){
                nums.erase(nums.begin() + max_num_pos - 1);
            }
            count_max += nums[max_num_pos];
            nums.erase(nums.begin() + max_num_pos);
            max_num = 0;
        }
        i++;
    }
    std::cout << count_max;
}