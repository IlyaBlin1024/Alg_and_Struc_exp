#include <iostream>
#include <string>
#include <vector>

int longestSubstring(std::vector<char>s, int k) 
{
    int count[26] = { 0 };
    for (int i = 0; i < s.size(); i++) { 
        count[s[i] - 'a'] += 1;
    }
    std::vector<char> d;
    for (int i = 0; i < s.size(); i++){
        if(count[s[i] - 'a'] >= k){
            d.push_back('*');
        }else{
            d.push_back('#');
        }
    }
    d.push_back('#');
    int answer = 0;
    int count_1 = 0;
    std::vector<char> count_2(26, 0);
    for (int i = 0; i < d.size(); i++) { 
        if (d[i] == '*') {
            count_2[s[i] - 'a']++;
            count_1++;
        }else if(d[i] == '#'){
            if(count_1 > answer){
                bool check = true;
                for(int j = 0; j < 26; j++){
                    if(count_2[j] < k && count_2[j] > 0){
                        check = false;
                        break;
                    }
                }
                if(check){
                    answer = count_1;
                }
            }
            count_1 = 0;
            count_2.clear();
            count_2.resize(26, 0);
        }
    }
    return answer; 
} 

int main(){
    int n = 0;
    int k = 0;
    std::cin >> n >> k;
    std::vector<char> str(n);
    for(int i = 0; i < n; i++){
        std::cin >> str[i];
    }
    std::cout << longestSubstring(str, k);
	return 0;
}