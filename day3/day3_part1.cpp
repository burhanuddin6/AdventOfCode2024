#include <iostream>
#include <regex>
#include "input.h"
#include <vector>

int main(void){
    std::vector<std::string> input = inputFromFile("day3/input.txt");
    std::regex mulregex("mul\\(\\d+,\\d+\\)");
    std::smatch matches;
    long sum = 0;
    std::regex num_regex("\\d+");
    for (std::string str: input){
        std::sregex_iterator currentMatch(str.begin(), str.end(), mulregex);
        std::sregex_iterator end; // End iterator
        while (currentMatch != end) {
            std::string matchedStr = (*currentMatch).str(); // Get the match result
            std::sregex_iterator numMatch(matchedStr.begin(), matchedStr.end(), num_regex);
            long prod = 1;
            while (numMatch != end) {
                prod *= std::stoi((*numMatch).str());
                ++numMatch;
            }
            sum += prod;
            ++currentMatch;
        }
    }
    std::cout << sum << std::endl;
    return 0;
}