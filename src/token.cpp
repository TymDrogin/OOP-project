#include "user-input-processing/token.hpp"

/*Constructor*/
Token::Token(TokenType t, const std::string& l) : _type(t), _lexeme(l) {};
Token::Token(TokenType t) : _type(t) {};

/*Public*/
void Token::print() const {
    std::cout << "Type: " << tokenTypeToString(_type);
    std::cout << ", Value: " << _lexeme << std::endl;
}
TokenType Token::getType() const {return _type;}
std::string Token::getLexeme() const {return _lexeme;}
std::string Token::tokenTypeToString(TokenType t) {
    switch (t) {
        case TokenType::Error: return "Error";
        case TokenType::EoF: return "End of File";
        case TokenType::Keyword: return "Keyword";
        case TokenType::Number: return "Number";
        default: return "Unknown";
    }
}
/*Functions*/
void printTokens(const std::vector<Token>& tokens) {
    for (const Token& t : tokens) {
        t.print();
    }
}