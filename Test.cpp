//
// Created by bravo8234 on 03/03/2022.
//

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
std::string removeWhiteSpace(const std::string& toUpdate) {
    std::string toRet;
    for(char i : toUpdate)
    {
        if(i != '\n' && i != '\t' && i != ' ')
        {
            toRet.push_back(i);
        }
    }
    return toRet;
}
TEST_CASE("good input")
{
    CHECK(removeWhiteSpace(ariel::mat(1,3,'#','-')).compare(removeWhiteSpace("#\n#\n#\n")) == 0);
    CHECK(removeWhiteSpace(ariel::mat(3,1,'#','*')).compare("###") == 0);
    CHECK(removeWhiteSpace(mat(9, 7, '@', '-')).compare(removeWhiteSpace("@@@@@@@@@\n@-------@\n@-@@@@@-@\n@-@---@-@\n@-@@@@@-@\n@-------@\n@@@@@@@@@")) == 0);
    CHECK(removeWhiteSpace(ariel::mat(9,9,'#','_')).compare(removeWhiteSpace("#########\n#_______#\n#_#####_#\n#_#___#_#\n#_#_#_#_#\n#_#___#_#\n#_#####_#\n#_______#\n#########\n")) == 0);
    CHECK(removeWhiteSpace(ariel::mat(5,5,'#','$')).compare(removeWhiteSpace("######$$$##$#$##$$$######")) == 0);
    CHECK(removeWhiteSpace(ariel::mat(7,1,'#','$')).compare(removeWhiteSpace("#######")) == 0);
    CHECK(removeWhiteSpace(ariel::mat(9,3,'*','#')).compare(removeWhiteSpace("*********\n*#######*\n*********")) == 0);
    CHECK(removeWhiteSpace(ariel::mat(11,3,'-','+')).compare(removeWhiteSpace("-----------\n-+++++++++-\n-----------\n")) == 0);
    CHECK(removeWhiteSpace(ariel::mat(3,7,'{','}')).compare(removeWhiteSpace("{{{\n{}{\n{}{\n{}{\n{}{\n{}{\n{{{\n")) == 0);
    CHECK(removeWhiteSpace(ariel::mat(15,9,'$','#')).compare(removeWhiteSpace("$$$$$$$$$$$$$$$\n$#############$\n$#$$$$$$$$$$$#$\n$#$#########$#$\n$#$#$$$$$$$#$#$\n$#$#########$#$\n$#$$$$$$$$$$$#$\n$#############$\n$$$$$$$$$$$$$$$\n")) == 0);
}

TEST_CASE("bad input")
{
    CHECK_THROWS(ariel::mat(4,1,'#','$'));
    CHECK_THROWS(ariel::mat(1,4,'#','$'));
    CHECK_THROWS(ariel::mat(7,0,'#','$'));
    CHECK_THROWS(ariel::mat(0,7,'#','$'));
    CHECK_THROWS(ariel::mat(0,0,'_','#'));
    CHECK_THROWS(ariel::mat(4,4,'#','*'));
    CHECK_THROWS(ariel::mat(-1,3,'#','*'));
    CHECK_THROWS(ariel::mat(3,-1,'#','*'));
    CHECK_THROWS(ariel::mat(-1,-1,'#','*'));
    CHECK_THROWS_MESSAGE(ariel::mat(-1,-1,'#','*'),"Mat size is always positive");
    CHECK_THROWS_MESSAGE(ariel::mat(4,1,'_','+'),"Mat size is always odd");
    CHECK_THROWS(ariel::mat(3,3,'\n','@'));
    CHECK_THROWS(ariel::mat(3,3,'\t','@'));
    CHECK_THROWS(ariel::mat(3,3,'\r','@'));
    CHECK_THROWS(ariel::mat(3,3,'\0','@'));
    CHECK_THROWS(ariel::mat(3,3,' ','@'));
    CHECK_THROWS(ariel::mat(3,3,'#','\n'));
    CHECK_THROWS(ariel::mat(3,3,'#',' '));
    CHECK_THROWS(ariel::mat(3,3,'#','\t'));
    CHECK_THROWS(ariel::mat(3,3,'#','\r'));
    CHECK_THROWS(ariel::mat(3,3,'#','\0'));
    CHECK_THROWS_MESSAGE(ariel::mat(5,5,'#','\t'), "Illegal symbol");


}
