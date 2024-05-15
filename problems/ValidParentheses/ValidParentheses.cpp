#include <iostream>
#include <stack>
#include <string>

bool isValid(std::string s) {
    std::stack<char> tmp;

    for (size_t i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            tmp.push(c);
        } else {
            if (tmp.empty()) {
                return false;
            }

            std::cout << "pop: " << tmp.top() << std::endl;

            if (c == ')' && tmp.top() != '(') {
                return false;
            }
            if (c == ']' && tmp.top() != '[') {
                return false;
            }
            if (c == '}' && tmp.top() != '{') {
                return false;
            }

            tmp.pop();
        }
    }

    return tmp.empty();
}

int main() {
    std::string s = "()(]{}";
    std::cout << "Is the string " << s << " valid parentheses? " << (isValid(s) ? "Yes" : "No") << std::endl;
    return 0;
}
