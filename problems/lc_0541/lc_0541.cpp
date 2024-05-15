#include "headers.h"

class Solution {
 public:
  std::string reverseStr(std::string s, int k) {
    for (size_t i = 0; i < s.size(); i += 2 * k) {
      if (i + k <= s.size()) {
        std::reverse(s.begin() + i, s.begin() + i + k);
      } else {
        std::reverse(s.begin() + i, s.end());
      }
    }

    return s;
  }
};
TEST(lc_0541, lc_0541) {
  Solution s;
  std::string str = "abcdefg";
  std::string reversed_str = s.reverseStr(str, 2);
  std::cout << reversed_str << std::endl;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
