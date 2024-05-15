#include "headers.h"

class Solution {
 public:
  // 去除所有空格并在相邻单词之间添加空格, 快慢指针。
  void removeExtraSpaces(std::string& s) {
    size_t slow = 0;
    for (size_t i = 0; i < s.size(); i++) {
      if (s[i] != ' ') {
        if (slow != 0) {
          s[slow++] = ' ';
        }

        while (i < s.size() && s[i] != ' ') {
          s[slow++] = s[i++];
        }
      }
    }
    s.resize(slow);
  }

  void reverseStr(std::string& s, size_t start, size_t end) {
    for (size_t i = start, j = end; i < j; i++, j--) {
      swap(s[i], s[j]);
    }
  }

  void reverseWord(std::string& s) {
    int start = 0;
    for (size_t i = 0; i <= s.size(); ++i) {
      if (i == s.size() || s[i] == ' ') {
        reverseStr(s, start, i - 1);
        start = i + 1;
      }
    }
  }
};
TEST(lc_0151, lc_0151) {
  Solution s;
  std::string str = "Hello  World ";
  s.removeExtraSpaces(str);
  std::cout << str << std::endl;
  s.reverseStr(str, 0, str.size() - 1);
  std::cout << str << std::endl;
  s.reverseWord(str);
  std::cout << str << std::endl;
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
