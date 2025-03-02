#include <iostream>
#include <vector>


int trap(std::vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int leftMax = height[left];
    int rightMax = height[right];
    int water = 0;

    while (left < right) {
        if (leftMax < rightMax) {
            left++;
            leftMax = std::max(leftMax, height[left]);
            water += leftMax - height[left];
        } else {
            right--;
            rightMax = std::max(rightMax, height[right]);
            water += rightMax - height[right];
        }
    }

    return water;        
}


int main(){
    int n = 0;
    std::cin >> n;
    std::vector <int> space;
    int answer = 0;
    for(int i = 0; i < n; i++){
        int a = 0;
        std::cin >> a;
        space.push_back(a);
    }
    std::cout << trap(space);
}