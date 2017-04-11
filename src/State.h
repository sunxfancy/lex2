//
// Created by 孙笑凡 on 11/04/2017.
//

#ifndef LEX_STATE_H
#define LEX_STATE_H

#include <string>
#include <vector>
#include "Pattern.h"
class State {
public:
    std::vector<std::string> namelist;
    std::vector<Pattern*> patterns;

    State();

    State(const std::vector<std::string, std::allocator<std::string>> &namelist,
          const std::vector<Pattern *, std::allocator<Pattern *>> &patterns);
};


#endif //LEX_STATE_H
