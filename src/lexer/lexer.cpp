#include "lexer.h"

void Lexer::lex(std::string _source) {
    this->source = _source;
    this->tokens.clear();

    while (this->current < this->source.length()) {

        char c = this->source[this->current];

        Token current_token;

        switch (c) {
        {
        case '\0':
            current_token.type = EndOF;
            break;

        case ' ' || '\t' || '\n' || '\r':
            current_token.type = Whitespace;
            break;
        
        default:
            break;
        }

    }
}