#include <iostream>
#include <vector>

int removeElement(std::vector<int>& nums, int val) {
    int index = 0;
    for (size_t i = 0; i < nums.size(); i++) {
        if (val != nums[i]) {
            nums[index] = nums[i];
            index++;
        }
    }

    return index;
}

int main() {
    std::vector<int> nums = {3, 2, 2, 3};
    int val = 3;

    int new_length = removeElement(nums, val);

    std::cout << "New length of array after removing " << val << ": " << new_length << std::endl;
    std::cout << "Array after removal: ";
    for (int i = 0; i < new_length; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
