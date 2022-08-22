//
//  Lexer.cpp
//  Black
//
//  Created by Apekshik Panigrahi on 8/21/22.
//

#include "Lexer.hpp"

namespace blackLexer {

using namespace std;

vector<Token> Tokenizer::parse(const string &sourceCode) {
    vector<Token> tokens;
    Token currentToken;
    
    for(char currCh : sourceCode) {
        switch (currCh) {
            case <#constant#>:
                <#statements#>
                break;
                
            default:
                break;
        }
    }
    
    return tokens;
}

}
