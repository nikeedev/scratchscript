#include "lexer.h"
#include <cctype>

void Lexer::lex(std::string _source)
{
    src = _source;
    tokens.clear();

    while (current < src.length())
    {
        char c = src[current];

        Token current_token;

        switch (c)
        {
        case '\0':
            current_token.type = EndOF;
            break;

        case ' ' || '\t' || '\n' || '\r':
            current_token.type = Whitespace;
            break;

        default:
            if (std::isalpha(c))
            {
                current_token.type = this->id();
            }
            break;
        }

        tokens.push_back(Token{
            .type = current_token.type,
            .line = line,
            .column = column});

        current++;
    }
}

TokenType Lexer::id()
{
    std::string id = "";

    while (is_id(peek()))
    {
        id += bump();
    }

    if (id == "if")
    {
        return TokenType::If;
    }
    else if (id == "else")
    {
        return TokenType::Else;
    }
    else if (id == "while")
    {
        return TokenType::While;
    }
    else if (id == "for")
    {
        return TokenType::For;
    }
    else if (id == "set")
    {
        return TokenType::Set;
    }
    else if (id == "get")
    {
        return TokenType::Get;
    }
    else if (id == "when")
    {
        return TokenType::When;
    }
    
    else
    {
        return TokenType::Identifier;
    }

    return TokenType::String;
}
