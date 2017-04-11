//
// Created by 孙笑凡 on 11/04/2017.
//

#ifndef LEX_PATTERN_H
#define LEX_PATTERN_H

#include <string>

class Pattern {
public:

    std::string name;
    std::string regex;
    std::string goto_target;

    Pattern();

    Pattern(const std::string &name, const std::string &regex);

    Pattern(const std::string &name, const std::string &regex, const std::string &goto_target);

};


#endif //LEX_PATTERN_H
