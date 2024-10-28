#include "lexer.h"
#include <cctype>
#include <fmt/core.h>

void Lexer::lex(std::string _source)
{
    src = _source;
    tokens.clear();

    while (current < src.length())
    {
        
        char c = src[current];

        int start = current;

        fmt::println("current: {} {}", c, current);

        Token current_token;

        switch (c)
        {
            case '\0':
                current_token.type = EndOF;
                break;

            case ' ':
            case '\t':
            case '\r':
                current_token.type = Whitespace;
                line++;
                column = 1;
                break;

            case '\n':
                current_token.type = Whitespace;
                break;

            case '+':
                current_token.type = Plus;
                break;

            case '-':
                current_token.type = Minus;
                break;

            case '*':
                current_token.type = Star;
                break;

            case '/':
                current_token.type = Slash;
                break;

            case '%':
                current_token.type = Percent;
                break;

            case '#':
                current_token.type = this->comment();
                break;

            case '^':
                current_token.type = Caret;
                break;

            case '&':
                current_token.type = Ampersand;
                break;

            case '~':
                current_token.type = Tilde;
                break;

            case '=':
                if (peek() == '=')
                {
                    current_token.type = IsSame;
                }
                else
                {
                    current_token.type = Equal;
                }
                break;

            case '(':
                current_token.type = LeftParenthesis;
                break;

            case ')':
                current_token.type = RightParenthesis;
                break;

            case '[':
                current_token.type = LeftBracket;
                break;

            case ']':
                current_token.type = RightBracket;
                break;

            case '{':
                current_token.type = LeftBrace;
                break;

            case '}':
                current_token.type = RightBrace;
                break;

            default:
                if (std::isalpha(c))
                {
                    current_token.type = this->id();
                }
                else if (c == '\"' || c == '\'')
                {
                    current_token.type = this->str();
                }
                else if (std::isdigit(c))
                {
                    current_token.type = this->number();
                }
                else
                {
                    current_token.type = Unknown;
                }
                break;
        }

        tokens.push_back(Token{
            .type = current_token.type,
            .value = src.substr(start, current - start),
            .line = line,
            .column = column,
            .is_terminated = is_terminated});

        current++;
        column++;
    }
}

TokenType Lexer::comment()
{
    char c = peek();

    while (c != '\n' && c != '\0')
    {
        // c = bump(); 
        c = peek();
    }

    return TokenType::Comment;
}

TokenType Lexer::str()
{
    while (true)
    {
        char c = bump();

        if (c == '\0')
        {
            is_terminated = false;
            break;
        }
        else if (c == '\"')
        {
            is_terminated = true;
            break;
        }
        else
        {
            continue;
        }
    }

    return TokenType::String;
}

TokenType Lexer::number()
{
    while (true)
    {
        char c = bump();

        if (!std::isdigit(c) || c != '.')
        {
            break;
        }
    }

    return TokenType::Number;
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
}

char Lexer::peek()
{
    return src[current + 1];
}

char Lexer::bump()
{
    char c = src[current++];

    if (c == '\n')
    {
        line++;
        column = 1;
    }
    else
    {
        column++;
    }
    return c;
}

bool Lexer::is_id(char c)
{
    return std::isalpha(c) || std::isdigit(c) || c == '_';
}