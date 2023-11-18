#pragma once

#include "token.hpp"
#include <vector>
#include <cctype>
#include <memory>

class Lexer {
public:
	Lexer(std::string& input);
	std::vector<Token> tokenize();

private:
	std::string _input;
	int _position; //current lexing position

	void advance(); //increment position by 1
	void skipWhitespace();
	char getCurrentChar() const;
	void resetPosition();

	Token nextToken();
	Token parseNumber();
	Token parseIdentifier();
};