#pragma once

#include "Token.h"
#include <vector>
#include <exception>
#include <string>
#include <sstream>
#include <iostream>

class Scheme {
public:
    Scheme(const Token& id) {
        schemeID = new Token(id);
    }
    Scheme() {
        schemeID = nullptr;
    }
    ~Scheme() {
        if (schemeID != nullptr) { delete schemeID; }
    }

    void setSchemeID(const Token& id){
        if (id.getTokenType() != TokenType::ID){ throw std::invalid_argument("Non-ID token passed to setSchemeID"); }
        schemeID = new Token(id);
    }

    void addIdToScheme(const Token& id) {
        if (id.getTokenType() != TokenType::ID) { throw std::invalid_argument("Non-ID token passed to addIdToScheme"); }
        ids.push_back(new Token(id));
    }

    Token getSchemeId();
    std::vector<Token*>* getIdVector() { return &ids; }
    std::string toString();

private:
    Token* schemeID;
    std::vector<Token*> ids;
};