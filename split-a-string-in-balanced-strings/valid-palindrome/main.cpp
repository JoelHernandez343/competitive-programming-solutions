#include <iostream>
#include <string>
#include <vector>

bool is_alphanumeric(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
}

char to_lower(char c) {
    if ((c >= 'A' && c <= 'Z')) {
        return c + 'a' - 'A';
    }

    return c;
}

bool is_palindrome(std::string s) {
    auto beginning = 0;
    auto ending = s.length() - 1;
    auto length = s.length();

    while (true) {
        while (!is_alphanumeric(s[beginning]) && beginning < length) {
            beginning++;
        }

        if (beginning == length) {
            return true;
        }

        while (!is_alphanumeric(s[ending]) && ending >= 0) {
            ending--;
        }

        if (ending < 0) {
            return false;
        }

        auto bc = to_lower(s[beginning]);
        auto ec = to_lower(s[ending]);

        if (bc != ec) {
            return false;
        }

        if (beginning + 1 > ending - 1) {
            break;
        }

        beginning++;
        ending--;
    };

    return true;
}

int main(void) {
    std::string s;

    while (std::getline(std::cin, s)) {
        auto result = is_palindrome(s);
        std::cout << "RESULT:" << result << std::endl;
    }

    return 0;
}