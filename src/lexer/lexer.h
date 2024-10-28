#include "token.h"
#include <vector>

class Lexer
{
public:
    std::vector<Token> tokens;
    std::string src;
    int current = 0;
    int line = 1;
    int column = 1;
    bool is_terminated = true;

    void lex(std::string _source);

    TokenType id();
    TokenType str();
    TokenType comment();
    TokenType number();

    std::vector<Token> get_tokens() { return tokens; }

    char bump();
    char peek();
    bool is_id(char c);
};
