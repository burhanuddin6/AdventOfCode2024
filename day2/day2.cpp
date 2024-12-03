#include "input.h"
#include <iostream>


bool is_safe_func(bool asc, std::vector<int> lst, int i, int j){
    if (asc){
        if (lst[j] < lst[i] || lst[j] - lst[i] > 3 || lst[j] - lst[i] < 1){
            return false;
        }
    }
    else{
        if (lst[j] > lst[i] || lst[i] - lst[j] > 3 || lst[i] - lst[j] < 1){
            return false;
        }
    }
    return true;
}

bool is_safe_lst(std::vector<int> lst){
    bool is_safe = true;
    size_t lst_size = lst.size();
    auto increasing = true;
    if (lst_size > 1){
        if (lst[1] < lst[0]){
            increasing = false;
        }
    }
    else{
        return true;
    }
    for (size_t i = 0; i != lst_size - 1; i++){
        if (is_safe_func(increasing, lst, i, i+1) == false){
            is_safe = false;   
        }
    }
    return is_safe;
}
int main(void){
    std::vector<std::string> input = inputFromFile("input.txt");

    std::vector<std::vector<int>> a;
    a = inputVector<int>(input);
    int safe = 0;
    for (const std::vector<int>& lst: a){
        bool is_safe = true;
        size_t lst_size = lst.size();
        auto increasing = true;
        if (lst_size > 1){
            if (lst[1] < lst[0]){
                increasing = false;
            }
        }
        else{
            continue;
        }
        for (size_t i = 0; i != lst_size; i++){
            if (i < lst_size){
                if (is_safe_func(increasing, lst, i, i+1) == false){
                    is_safe = false;
                }
            }
            std::vector<int> lst_copy(lst);
            lst_copy.erase(lst_copy.begin()+i);
            if (is_safe_lst(lst_copy)){
                is_safe = true;
                break;
            }
        }
        // std::cout<< lst[0] << std::endl;
        if (is_safe){
            safe += 1;
        }
    }

    std::cout << std::endl << safe << std::endl;
    return 0;
    
}