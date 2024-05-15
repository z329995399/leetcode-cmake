#include <iostream>
#include <unordered_map>

bool isIsomorphic(std::string s, std::string t) {
    if (s.length() != t.length())
    {
        return false;
    }

    std::unordered_map<char, char> map1;
    std::unordered_map<char, char> map2;

    for (int i = 0; i < (int)s.length(); i++)
    {
        if (map1.find(s[i]) == map1.end())
        {
            map1[s[i]] = t[i];
        }

        if (map2.find(t[i]) == map2.end())
        {
            map2[t[i]] = s[i];
        }

        if (map1[s[i]] != t[i] || map2[t[i]] != s[i])
        {
            return false;
        }

    }

    return true;
}

int main() {
    std::string s = "egg";
    std::string t = "add";
    std::cout << std::boolalpha << "字符串 '" << s << "' 和 '" << t << "' 是否同构: " << isIsomorphic(s, t) << std::endl;

    s = "foo";
    t = "bar";
    std::cout << std::boolalpha << "字符串 '" << s << "' 和 '" << t << "' 是否同构: " << isIsomorphic(s, t) << std::endl;

    return 0;
}
