/**
* @Author: Sun Xiaofan <sxf>
* @Date:   2016-11-14
* @Email:  sunxfancy@gmail.com
* @Last modified by:   sxf
* @Last modified time: 2016-11-14
* @License: MIT License
*/

#ifdef __APPLE__
#define GTEST_HAS_POSIX_RE 0
#endif

#include <gtest/gtest.h>
#include "Lex.h"

using namespace std;

#define AUTOMATON_TEST(name) TEST(AutomatonTest_##name, name)

AUTOMATON_TEST (Construction)
{
    LexInterface* lex = CreateLex();
    lex->ReadConfig("../../../test/test.cfg");
}
