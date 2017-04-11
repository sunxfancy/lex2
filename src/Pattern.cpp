//
// Created by 孙笑凡 on 11/04/2017.
//

#include "Pattern.h"

Pattern::Pattern(
        const std::string &name,
        const std::string &regex,
        const std::string &goto_target)
    : name(name),
      regex(regex),
      goto_target(goto_target)
{

}

Pattern::Pattern() {}

Pattern::Pattern(const std::string &name, const std::string &regex) : name(name), regex(regex) {}
