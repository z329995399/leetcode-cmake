#include <iostream>
#include <string>
#include <vector>

// Compute the prefix function for the given pattern (needle)
std::vector<int> computePrefix(const std::string& pattern) {
    int m = pattern.size();
    std::vector<int> prefix(m, 0);
    int k = 0;
    for (int i = 1; i < m; ++i) {
        while (k > 0 && pattern[k] != pattern[i]) {
            k = prefix[k - 1];
        }
        if (pattern[k] == pattern[i]) {
            k++;
        }
        prefix[i] = k;
    }
    return prefix;
}

int strStr(std::string haystack, std::string needle) {
    int m = haystack.size(), n = needle.size();
    if (n == 0) return 0;

    // Compute the prefix function for the needle
    std::vector<int> prefix = computePrefix(needle);

    int q = 0; // Number of characters matched
    for (int i = 0; i < m; ++i) {
        while (q > 0 && needle[q] != haystack[i]) {
            q = prefix[q - 1]; // Update the number of characters matched using prefix function
        }
        if (needle[q] == haystack[i]) {
            q++;
        }
        if (q == n) {
            return i - n + 1; // Match found
        }
    }
    return -1; // No match found
}

int main() {
    std::string haystack = "hello";
    std::string needle = "ll";

    int index = strStr(haystack, needle);

    std::cout << "Index of needle in haystack: " << index << std::endl;

    return 0;
}
