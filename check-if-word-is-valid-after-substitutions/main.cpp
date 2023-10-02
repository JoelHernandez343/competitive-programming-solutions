// Joel Hernández
// https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/description/

#include <iostream>
#include <stack>
#include <string>

bool is_valid(std::string s) {
    std::stack<char> balance;

    for (auto i = 0; s[i]; ++i) {
        if (s[i] == 'a') {
            balance.push('a');
            continue;
        }

        if (balance.empty()) {
            return false;
        }

        if (s[i] == 'b') {
            if (balance.top() != 'a') {
                return false;
            }

            balance.pop();
            balance.push('b');
        } else {
            if (balance.top() != 'b') {
                return false;
            }

            balance.pop();
        }
    }

    return balance.empty();
}

int main(void) {
    std::string s;

    while (std::getline(std::cin, s)) {
        std::cout << is_valid(s) << std::endl;
    }

    return 0;
}