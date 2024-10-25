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

    void lex(std::string _source);

    TokenType id();

    std::vector<Token> get_tokens() { return tokens; }

    char peek()
    {
        return src[current + 1];
    }

    char bump()
    {
        if (src[current] != NULL)
        {
            current++;
            return src[current];
        }
        else
        {
            return '\0';
        }
    }

    bool is_id(char c) 
    {
        return std::isalpha(c) || std::isdigit(c) || c == '_';
    }
};
