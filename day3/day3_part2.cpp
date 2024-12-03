#include <iostream>
#include <regex>
#include "input.h"
#include <vector>

int main(void){
    std::vector<std::string> input = inputFromFile("day3/input2.txt");
    std::regex mulregex("mul\\(\\d+,\\d+\\)");
    std::smatch matches;
    long sum = 0;
    std::regex num_regex("\\d+");
    std::regex do_regex("do\\(\\)");
    std::regex dont_regex("don\'t\\(\\)");
    
    std::string result;
    for (const auto& str : input) {
        result += str; // Concatenate strings
    }
    std::sregex_iterator match_iter(result.begin(), result.end(), mulregex);
    std::sregex_iterator do_match_iter(result.begin(), result.end(), do_regex);
    std::sregex_iterator dont_match_iter(result.begin(), result.end(), dont_regex);
    std::sregex_iterator end; // End iterator
    while (match_iter != end) {

        std::smatch match = (*match_iter); 
        
        std::sregex_iterator temp(do_match_iter);
        ++temp;
        while ((*temp).position() < match.position() && temp != end)
        {   
            ++temp;
            ++do_match_iter;
        }

        temp = dont_match_iter;
        ++temp;
        while ((*temp).position() < match.position() && temp != end)
        {
            ++temp;
            ++dont_match_iter;
        }

        std::smatch do_match = (*do_match_iter);
        std::smatch dont_match = (*dont_match_iter);
        std::cout << do_match.position() << " " << dont_match.position() << " " << match.position() << std::endl;
        
        if ((do_match.position() > dont_match.position()) || (match.position() < dont_match.position())){
            std::cout << "did" << std::endl;
            std::string matchedStr = match.str();
            std::sregex_iterator numMatch(matchedStr.begin(), matchedStr.end(), num_regex);
            long prod = 1;
            while (numMatch != end) {
                prod *= std::stoi((*numMatch).str());
                ++numMatch;
            }
            sum += prod;
        }
        ++match_iter;
    }
    std::cout << sum << std::endl;
    return 0;
}