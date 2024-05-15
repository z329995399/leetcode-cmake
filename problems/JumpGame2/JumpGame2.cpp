#include <iostream>
#include <vector>

int jump(std::vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return 0;

    std::cout << std::endl;

    int jumps = 0;
    int current_jump_end = 0; // the end index of the current jump
    int farthest = 0; // the farthest index that can be reached with the current number of jumps

    for (int i = 0; i < n - 1; ++i) {
        // Update the farthest index that can be reached with the current number of jumps
        farthest = std::max(farthest, i + nums[i]);
        std::cout << "i: " << i << " farthest: " << farthest << std::endl;

        // If we have reached the end of the current jump, we need to jump to the farthest index
        if (i == current_jump_end) {
            jumps++;
            current_jump_end = farthest; // update the end index of the current jump
            std::cout << "i: " << i << " jumps: " << jumps << " current_jump_end: " << current_jump_end << std::endl;
        }
    }

    return jumps;
}

int main() {
    // std::vector<int> nums = {2, 3, 1, 1, 4};
    std::vector<int> nums = {3,2,1,0,4};

    std::cout << "Minimum number of jumps required: " << jump(nums) << std::endl;

    return 0;
}
