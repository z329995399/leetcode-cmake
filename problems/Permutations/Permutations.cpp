#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> result;
    std::vector<int> path;

    void backtracking (std::vector<int>& nums, std::vector<bool>& used) {
        if (path.size() == nums.size()) {
            std::cout << "res: [ ";
            for (size_t i = 0; i < path.size(); i++) {
                std::cout << path[i] << " ";
            }
            std::cout << "]" << std::endl;

            result.push_back(path);
            return;
        }

        for (size_t i = 0; i < nums.size(); i++) {
            if (used[i]) {
                continue;
            }

            path.push_back(nums[i]);
            used[i] = true;
            std::cout << "used: " << i << " " << nums[i] << std::endl;
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }

    }

    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        result.clear();
        path.clear();
        std::vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
};

std::vector<std::vector<int>> permute(std::vector<int>& nums) {
    Solution s;
    return s.permute(nums);
}

int main() {
    std::vector<int> nums = {1, 2, 3};

    std::vector<std::vector<int>> result = permute(nums);

    std::cout << "Permutations of the array:" << std::endl;
    for (const auto& perm : result) {
        std::cout << "[ ";
        for (int num : perm) {
            std::cout << num << " ";
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}
