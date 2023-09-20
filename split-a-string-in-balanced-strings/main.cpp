// Joel Hernández @ 2023
// https://leetcode.com/problems/split-a-string-in-balanced-strings/description/

#include <iostream>

int balanced_string_split(std::string s) {
    auto r = 0;
    auto l = 0;
    auto substring_count = 0;

    for (auto i = 0; s[i]; ++i) {
        if (s[i] == 'R') {
            r++;
        } else {
            l++;
        }

        if (r == l) {
            r = l = 0;
            substring_count++;
        }
    }

    return substring_count;
}

int main(void) {
    std::string line;

    while (std::cin >> line) {
        std::cout << balanced_string_split(line) << std::endl;
    }

    return 0;
}