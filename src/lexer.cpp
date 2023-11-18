#include "lexer.hpp"


/*Constructor*/
Lexer::Lexer(std::string& input) : _input(input), _position(0) {};


/*Public*/
std::vector<Token> Lexer::tokenize() {
	std::vector<Token> tokens;
	Token token = nextToken();

	while (token.getType() != TokenType::EoF) {
		tokens.push_back(token);
		token = nextToken();
	}

	resetPosition(); //reset position to allow multiple tokenize() calls
	return tokens;
};

/*Private*/
void Lexer::advance() {
	_position++;
}
void Lexer::skipWhitespace() {
	while (_position < _input.length() && isspace(_input[_position])) {
		advance();
	}
}
char Lexer::getCurrentChar() const {
	return _input[_position];
};
void Lexer::resetPosition() {_position = 0;}

Token Lexer::nextToken() {
	skipWhitespace();
	char c = getCurrentChar();

	if (c == '\0') {
		return Token(TokenType::EoF, "EOF"); // Return an EoF token
	}
    if (isdigit(c)) {
        return parseNumber();
    }
    else if (isalpha(c)) {
        return parseIdentifier();
    }
}
Token Lexer::parseNumber() {
	std::string lexeme;

	auto readWhileIsDigit = [&]() {
		while (isdigit(getCurrentChar())) {
			lexeme += getCurrentChar();
			advance();
		}
	};

	// Read integer part
	readWhileIsDigit();

	// Check for a decimal point
	/* if (getCurrentChar() == '.') {
		lexeme += getCurrentChar();
		advance();

		// Read decimal part
		readWhileIsDigit();
	}
	Token token(TokenType::Number, lexeme);
	return token;
	 */
}
Token Lexer::parseIdentifier() {
	std::string lexeme;

	while (isalpha(getCurrentChar()) || isdigit(getCurrentChar())) {
		lexeme += getCurrentChar();
		advance();
		//if lexeme is in constants return Token constant with value 
	}

	Token token(TokenType::Keyword, lexeme);
	return token;
}