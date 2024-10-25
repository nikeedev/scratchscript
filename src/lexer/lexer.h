#include "token.h"
#include <vector>

class Lexer {
    std::vector<Token> tokens;
    std::string source;
    int current = 0;
    int line = 1;
    int column = 1;

    void lex(std::string _source);
};