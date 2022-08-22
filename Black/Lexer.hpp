//
//  Lexer.hpp
//  Black
//
//  Created by Apekshik Panigrahi on 8/21/22.
//
#pragma once

#include <vector>
#include <string>

namespace blackLexer {

using namespace std;

enum TokenType {
    WHITESPACE,
    IDENTIFIER,
    INTEGER_LITERAL,
    STRING_LITERAL,
    OPERATOR
};

class Token {
public:
    enum TokenType tType{WHITESPACE};
    string tText;
    size_t tStartOffset{0};
    size_t tEndOffset{0};
    size_t tLineNumber{0};
};

class Tokenizer {
public:
    vector<Token> parse(const string &sourceCode);
};

}



