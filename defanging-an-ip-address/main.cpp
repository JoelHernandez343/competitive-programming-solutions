// Joel Hernández @ 2023
// https://leetcode.com/problems/defanging-an-ip-address/description/

#include <iostream>

std::string defang_ip(std::string address) {
    std::string response = "";

    for (auto i = 0; address[i]; ++i) {
        if (address[i] == '.') {
            response += "[.]";
        } else {
            response += address[i];
        }
    }

    return response;
}

std::string defang_ip_low_mem(std::string address) {
    char response[255];
    int j = 0;

    for (auto i = 0; i < address[i]; ++i) {
        if (address[i] == '.') {
            response[j++] = '[';
            response[j++] = '.';
            response[j++] = ']';
        } else {
            response[j++] = address[i];
        }
    }

    response[j] = 0;
    return response;
}

int main(void) {
    std::string address;
    while (std::cout << "? " && std::getline(std::cin, address, '\n') && !address.empty()) {
        std::cout << defang_ip_low_mem(address) << std::endl;
    }

    return 0;
}