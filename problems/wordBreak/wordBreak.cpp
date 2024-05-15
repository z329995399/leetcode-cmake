#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
    std::unordered_set<std::string> wordSet(wordDict.begin(), wordDict.end());

    std::vector<bool> dp(s.length() + 1, false);
    dp[0] = true;

    for (int i = 1; i <= (int)s.length(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            std::string tmp = s.substr(j, i - j);

            if (wordSet.find(tmp) != wordSet.end() && dp[j])
            {
                std::cout << j << " " << i << " " << tmp << std::endl;
                dp[i] = true;
                break;
            }

        }

    }

    return dp[s.length()];
}

int main() {
    std::string s = "leetcode";
    std::vector<std::string> wordDict = {"leet", "code"};
    bool result = wordBreak(s, wordDict);
    std::cout << std::boolalpha << "能否被分割: " << result << std::endl;

    return 0;
}
