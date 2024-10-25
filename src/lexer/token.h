#include <string>

enum TokenType {
    Comment, // #
    Identifier, // name
    Number, // 0-9
    String, // "string"
    Keyword,
    Punctuation,
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
    Return,
};

class Token {
public:
    TokenType type;
    std::string value;
    int line, column;
};