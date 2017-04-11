//
// Created by 孙笑凡 on 11/04/2017.
//

#include "State.h"

State::State(const std::vector<std::string, std::allocator<std::string>> &namelist,
             const std::vector<Pattern *, std::allocator<Pattern *>> &patterns)
        : namelist(namelist), patterns(patterns)
{

}

State::State() {}
