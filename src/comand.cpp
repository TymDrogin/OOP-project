#include "command.hpp"

CommandFromString::CommandFromString(std::string command) {
    Lexer lexer(command);
    _tokens = lexer.tokenize();
}

bool CommandFromString::isValid() const {
    return static_cast<bool>(getCommandType());
}

std::optional<CommandType> CommandFromString::getCommandType() const {
    if (_tokens.empty()) {
        // Handle the case where there are no tokens.
        return std::nullopt;
    }
    if (isNext())    return CommandType::Next;
    if (isAdvance()) return CommandType::Advance;

    if (isHnova())   return CommandType::Hnova;
    if (isHrem())    return CommandType::Hrem;
    if (isZnew())    return CommandType::Znew;
    if (isZrem())    return CommandType::Zrem;
    if (isZlista())  return CommandType::Zlista;

    if (isZcomp())   return CommandType::Zcomp;
    if (isZprops())  return CommandType::Zprops;
    if (isPmod())    return CommandType::Pmod;
    if (isCnew())    return CommandType::Cnew;
    if (isCrem())    return CommandType::Crem;

    //if (isRnew())    return CommandType::Rnew;
    //if (isPmuda())   return CommandType::Pmuda;
    if (isRlista())  return CommandType::Rlista;
    if (isRrem())    return CommandType::Rrem;
    if (isAsoc())    return CommandType::Asoc;
    if (isAdes())    return CommandType::Ades;

    //if (isAcom())    return CommandType::Acom;

    //if (isPsalva())  return CommandType::Psalva;
    if (isPrepoe())  return CommandType::Prepoe;
    if (isPrem())    return CommandType::Prem;
    if (isPlista())  return CommandType::Plista;

    if (isExec()) return CommandType::Exec;

    if(isExit()) return CommandType::Exit;

    return std::nullopt;  // No match found
}
std::vector<Token> CommandFromString::getTokens() const {return _tokens;}

std::string CommandFromString::getCommandTypeAsString() const {
    std::optional<CommandType> t = getCommandType();
    if(t) {
        switch (t.value()) {
            case CommandType::Next:
                return "Next";
            case CommandType::Advance:
                return "Advance";
            case CommandType::Hnova:
                return "Hnova";
            case CommandType::Hrem:
                return "Hrem";
            case CommandType::Znew:
                return "Znew";
            case CommandType::Zrem:
                return "Zrem";
            case CommandType::Zlista:
                return "Zlista";
            case CommandType::Zcomp:
                return "Zcomp";
            case CommandType::Zprops:
                return "Zprops";
            case CommandType::Pmod:
                return "Pmod";
            case CommandType::Cnew:
                return "Cnew";
            case CommandType::Crem:
                return "Crem";
            case CommandType::Rnew:
                return "Rnew";
            case CommandType::Pmuda:
                return "Pmuda";
            case CommandType::Rlista:
                return "Rlista";
            case CommandType::Rrem:
                return "Rrem";
            case CommandType::Asoc:
                return "Asoc";
            case CommandType::Ades:
                return "Ades";
            case CommandType::Acom:
                return "Acom";
            case CommandType::Psalva:
                return "Psalva";
            case CommandType::Prepoe:
                return "Prepoe";
            case CommandType::Prem:
                return "Prem";
            case CommandType::Plista:
                return "Plista";
            case CommandType::Exec:
                return "Exec";
            case CommandType::Exit:
                return "Exit";
        }
    } else {
        return "Unknown";
    }
}

// -------Commands for simulated time-------
bool CommandFromString::isNext() const {
    if (_tokens.size() == 1) {
        return _tokens[0].getLexeme() == "next";
    }
    return false;
}
bool CommandFromString::isAdvance() const {
    if (_tokens.size() == 2) {
        return _tokens[0].getLexeme() == "advance"
                && _tokens[1].getType() == TokenType::Number;
    }
    return false;
}

// -------Commands for managing housing and zones------
bool CommandFromString::isHnova() const {
    if (_tokens.size() == 3) {
        return _tokens[0].getLexeme() == "hnova"
               && _tokens[1].getType() == TokenType::Number
               && _tokens[2].getType() == TokenType::Number;
    }
    return false;
}
bool CommandFromString::isHrem() const {
    if (_tokens.size() == 1) {
        return _tokens[0].getLexeme() == "hrem";
    }
    return false;
}
bool CommandFromString::isZnew() const {
    if (_tokens.size() == 3) {
        return _tokens[0].getLexeme() == "znew"
               && _tokens[1].getType() == TokenType::Number
               && _tokens[2].getType() == TokenType::Number;
    }
    return false;
}
bool CommandFromString::isZrem() const {
    if (_tokens.size() == 2) {
        return _tokens[0].getLexeme() == "zrem"
        && _tokens[1].getType() == TokenType::Number;
    }
    return false;
}
bool CommandFromString::isZlista() const {
    if (_tokens.size() == 1) {
        return _tokens[0].getLexeme() == "zlista";
    }
    return false;
}

// -------Commands to manage zones and their content-------
bool CommandFromString::isZcomp() const {
    if (_tokens.size() == 2) {
        return _tokens[0].getLexeme() == "zcomp"
               && _tokens[1].getType() == TokenType::Number;
    }
    return false;
}
bool CommandFromString::isZprops() const {
    if (_tokens.size() == 2) {
        return _tokens[0].getLexeme() == "zprops"
               && _tokens[1].getType() == TokenType::Number;
    }
    return false;
}
bool CommandFromString::isPmod() const {
    if (_tokens.size() == 4) {
        // FIXME: bool isPropertyNameValidAndExists = PropertyReferenceTable.count(_tokens[2].getLexeme());

        return _tokens[0].getLexeme() == "pmod"
               && _tokens[1].getType() == TokenType::Number
               //&& isPropertyNameValidAndExists
               && _tokens[3].getType() == TokenType::Number;
    }
    return false;
}
//TODO
bool CommandFromString::isCnew() const {
    //TODO: add devices support and check if device is in table bla bla bla
    if (_tokens.size() == 4) {
        return _tokens[0].getLexeme() == "cnew"
        && _tokens[1].getType() == TokenType::Number;
    }
    return false;
}
//TODO
bool CommandFromString::isCrem() const {
    //TODO: add devices support and check if device is in table bla bla bla
    if (_tokens.size() == 4) {
        return _tokens[0].getLexeme() == "crem";
    }
    return false;
}


// -------Commands for rule processors-------
//TODO:
bool CommandFromString::isRnew() const {
    return false;
}
//TODO:
bool CommandFromString::isPmuda() const {
    return false;
}
bool CommandFromString::isRlista() const {
    if (_tokens.size() == 3) {
        return _tokens[0].getLexeme() == "rlista"
               && _tokens[1].getType() == TokenType::Number
               && _tokens[2].getType() == TokenType::Number;
    }
    return false;
}
bool CommandFromString::isRrem() const {
    if (_tokens.size() == 4) {
        return _tokens[0].getLexeme() == "rrem"
               && _tokens[1].getType() == TokenType::Number
               && _tokens[2].getType() == TokenType::Number
               && _tokens[3].getType() == TokenType::Number;
    }
    return false;
}
bool CommandFromString::isAsoc() const {
    if (_tokens.size() == 4) {
        return _tokens[0].getLexeme() == "asoc"
               && _tokens[1].getType() == TokenType::Number
               && _tokens[2].getType() == TokenType::Number
               && _tokens[3].getType() == TokenType::Number;
    }
    return false;
}
bool CommandFromString::isAdes() const {
    if (_tokens.size() == 4) {
        return _tokens[0].getLexeme() == "ades"
               && _tokens[1].getType() == TokenType::Number
               && _tokens[2].getType() == TokenType::Number
               && _tokens[3].getType() == TokenType::Number;
    }
    return false;
}

// -------Commands to interact with devices-------
//TODO:
bool CommandFromString::isAcom() const {
    return false;
}

// -------Commands for copying/retrieving rule processors--------
//TODO:
bool CommandFromString::isPsalva() const {
    return false;
}
bool CommandFromString::isPrepoe() const {
    if (_tokens.size() == 2) {
        return _tokens[0].getLexeme() == "prepoe"
               && _tokens[1].getType() == TokenType::Keyword;
    }
    return false;
}
bool CommandFromString::isPrem() const {
    if (_tokens.size() == 2) {
        return _tokens[0].getLexeme() == "prem"
               && _tokens[1].getType() == TokenType::Keyword;
    }
    return false;
}
bool CommandFromString::isPlista() const {
    if (_tokens.size() == 1) {
        return _tokens[0].getLexeme() == "plista";
    }
    return false;
}

// -------Additional general commands--------
//TODO: File validation
bool CommandFromString::isExec() const {
    if (_tokens.size() == 2) {
        bool isValidSequence = _tokens[0].getLexeme() == "exec"
               && _tokens[1].getType() == TokenType::Keyword;

        std::ifstream inputFile(_tokens[1].getLexeme());

        if (inputFile.is_open()) {
            return isValidSequence;
        }
    }
    return false;
}

// -------Special commands----------
bool CommandFromString::isExit() const {
    if(_tokens.size() == 1) {
        return _tokens[0].getLexeme() == "exit";
    }
    return false;
}

