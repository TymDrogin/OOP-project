#pragma once

#include <string>
#include <iostream>
#include <cctype>
#include <vector>
#include <map>

enum class TokenType {
	Error, EoF,
	Keyword,

	Number,
};

class Token {
public:
	Token(TokenType t, const std::string& l);
    Token(TokenType t);

	void print() const;

    [[nodiscard]] TokenType getType() const;
    [[nodiscard]] std::string getLexeme() const;

    static std::string tokenTypeToString(TokenType t);

private:
	TokenType _type;
	std::string _lexeme;
};
void printTokens(const std::vector<Token>& tokens);