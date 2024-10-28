#include "token.h"

std::ostream& operator<<(std::ostream& os, TokenType type) {
    switch (type) {
        case Comment: os << "Comment"; break;
        case Identifier: os << "Identifier"; break;
        case Number: os << "Number"; break;
        case String: os << "String"; break;
        case Keyword: os << "Keyword"; break;
        case Dot: os << "Dot"; break;
        case Whitespace: os << "Whitespace"; break;
        case EndOF: os << "EndOF"; break;
        case Plus: os << "Plus"; break;
        case Minus: os << "Minus"; break;
        case Star: os << "Star"; break;
        case Slash: os << "Slash"; break;
        case Percent: os << "Percent"; break;
        case Caret: os << "Caret"; break;
        case Ampersand: os << "Ampersand"; break;
        case Tilde: os << "Tilde"; break;
        case Equal: os << "Equal"; break;
        case IsSame: os << "IsSame"; break;
        case NotEqual: os << "NotEqual"; break;
        case LessThan: os << "LessThan"; break;
        case GreaterThan: os << "GreaterThan"; break;
        case SameOrGreaterThan: os << "SameOrGreaterThan"; break;
        case SameOrLessThan: os << "SameOrLessThan"; break;
        case Not: os << "Not"; break;
        case LeftParenthesis: os << "LeftParenthesis"; break;
        case RightParenthesis: os << "RightParenthesis"; break;
        case LeftBracket: os << "LeftBracket"; break;
        case RightBracket: os << "RightBracket"; break;
        case LeftBrace: os << "LeftBrace"; break;
        case RightBrace: os << "RightBrace"; break;
        case Comma: os << "Comma"; break;
        case Semicolon: os << "Semicolon"; break;
        case When: os << "When"; break;
        case If: os << "If"; break;
        case Else: os << "Else"; break;
        case For: os << "For"; break;
        case Say: os << "Say"; break;
        case Get: os << "Get"; break;
        case Set: os << "Set"; break;
        case While: os << "While"; break;
        case Unknown: os << "Unknown"; break;
        default: os << "Invalid TokenType"; break;
    }
    return os;
}
