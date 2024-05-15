#include <iostream>
#include <vector>

bool canJump(std::vector<int>& nums) {
    int cover = 0;
    if (nums.size() == 1) {
        return true;
    }

    for (int i = 0; i <= cover; i++) {
        cover = std::max(i + nums[i], cover);
        std::cout << "i:" << i << " num: " << nums[i] << " cover: " << cover << std::endl;

        if (cover >= (int)nums.size() - 1) {
            return true;
        }
    }

    return false;
}

int main() {
    // std::vector<int> nums = {2, 3, 1, 1, 4};
    std::vector<int> nums = {3,2,1,0,4};

    std::cout << "Can jump to the last index? " << (canJump(nums) ? "Yes" : "No") << std::endl;

    return 0;
}
