#include <string>
#include <iostream>

enum TokenType {
    Comment, // #
    Identifier, // name
    Number, // 0-9
    String, // "string"
    Keyword,
    Dot, // .
    Whitespace, // space, tab, new line
    EndOF,
    Plus, // + 
    Minus, // -
    Star, // *
    Slash, // /
    Percent, // %
    Caret, // ^
    Ampersand, // &
    Tilde, // ~
    Equal, // =
    IsSame, // ==
    NotEqual, // !=
    LessThan, // <
    GreaterThan, // >
    SameOrGreaterThan, // >=
    SameOrLessThan, // <=
    Not, // !
    LeftParenthesis, // (
    RightParenthesis, // )
    LeftBracket, // [
    RightBracket, // ]
    LeftBrace, // {
    RightBrace, // }
    Comma, // ,
    Semicolon, // ;
    When,
    If,
    Else,
    For,
    Say,
    Get,
    Set,
    While,
    Unknown
};

// Text formatting to print the token types:

std::ostream& operator<<(std::ostream& os, TokenType type);

class Token {
public:
    TokenType type;
    std::string value;
    int line; 
    int column;

    bool is_terminated = true;
};
