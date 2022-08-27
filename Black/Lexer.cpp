//
//  Lexer.cpp
//  Black
//
//  Created by Apekshik Panigrahi on 8/21/22.
//

#include "Lexer.hpp"

namespace blackLexer {

using namespace std;


// Takes the source Code and lexes it. Returns a list of
// all tokens in the source code
vector<Token> Lexer::lex(const string &sourceCode) {
    vector<Token> tokens; // holds the list of tokens we generate by lexing through source code
    Token currentToken;
    
    currentToken.tLineNumber = 1; // initialize to one since most line numbers are 1 indexed.
    
    for(char currCh : sourceCode) {
        switch (currCh) {
            // integer literal handling
            case '0': case '1': case '2':
            case '3': case '4': case '5':
            case '6': case '7': case '8':
            case '9':
                // We keep adding numbers to an integer token until we
                // stop encountering consecutive numbers
                if (currentToken.tType == WHITESPACE) {
                    currentToken.tType = INTEGER_LITERAL;
                    currentToken.tString.push_back(currCh);
                } else {
                    currentToken.tString.push_back(currCh);
                }
                break;
            // operator handling
            case '{': case '}': case '(': case ')':
            case '+': case '-': case '*':
            case '=': case '<': case '>':
            case ';':
            case ',':
                // end token and add it to tokens list when we encounter one of these operators
                if (currentToken.tType != STRING_LITERAL) {
                    endTokenAndAddToTokensList(currentToken, tokens);
                    currentToken.tType = OPERATOR;
                    currentToken.tString.push_back(currCh);
                } else { // This executes when we're simply parsing a string and the operators above then are
                    // simply part of the string and not a separate token itself
                    currentToken.tString.push_back(currCh);
                }
                break;
            // whitespace handling
            case ' ': case '\t':
                endTokenAndAddToTokensList(currentToken, tokens);
                break;
            case '\r': case '\n':
                endTokenAndAddToTokensList(currentToken, tokens);
                ++currentToken.tLineNumber;
                break;
                
        }
    }
    
    return tokens;
}

// along with adding the new token to tokens list, we clean the token variable
// so it's immediately reusable
void Lexer::endTokenAndAddToTokensList(Token &token, vector<Token> &tokens) {
    // the if statement is there to handle whitespaces we'll encounter during lexing
    // since we call this method everytime we encounter a whitespace case in Lexer::lex().
    if (token.tType != WHITESPACE) {
        tokens.push_back(token); // added new token to tokens list
    }
    // token holder cleaning process
    token.tType = WHITESPACE;
    token.tString.erase();
}

} // namespace blackLexer end
