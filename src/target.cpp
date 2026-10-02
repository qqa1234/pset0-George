#include <iostream>
#include <vector>

std::vector<int> targetVector(std::vector<int> nums, std::vector<int> index) {
    
    std::vector<int> target;

    for (int i = 0; i < nums.size(); i++) {
        target.insert(target.begin()+index[i],nums[i]);
    }

    return target;
}

void printVector(std::vector<int> v) {
    std::cout << "[";

    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i];

        if (i < v.size() - 1)
            std::cout << ",";

    }

    std::cout << "]" << std::endl;
}

int main() {
    std::vector<int> nums = {0, 1, 2, 3, 4};
    std::vector<int> index = {0, 1, 2, 2, 1};

    std::vector<int> result = targetVector(nums, index);

    printVector(result);

    return 0;
}