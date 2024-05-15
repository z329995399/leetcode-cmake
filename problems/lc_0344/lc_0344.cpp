#include "headers.h"

class Solution {
 public:
  void reverseString(char* c, int count) {
    // int count = sizeof(c) / sizeof(c[0]);
    std::cout << "count: " << count << std::endl;
    for (int i = 0, j = count - 1; i < count / 2; i++, j--) {
      char tmp = c[i];
      c[i] = c[j];
      c[j] = tmp;
    }
  }

  void printString(char* c, int count) {
    // int count = sizeof(c) / sizeof(c[0]);
    for (int i = 0; i < count; i++) {
      std::cout << c[i] << " ";
    }
    std::cout << std::endl;
  }
};
TEST(lc_0344, lc_0344) {
  Solution s;
  std::string str = "Hello World";

  char char_array[str.size()];
  std::strcpy(char_array, str.c_str());

  s.reverseString(char_array, str.size());
  s.printString(char_array, str.size());
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
