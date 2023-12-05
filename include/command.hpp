#pragma once

#include "lexer.hpp"
#include "property.hpp"
#include <optional>
#include <iostream>
#include <fstream>


enum class CommandType {
    // -------Commands for simulated time-------
    Next,
    Advance,

    // -------Commands for managing housing and zones------
    Hnova,
    Hrem,
    Znew,
    Zrem,
    Zlista,

    // -------Commands to manage zones and their content-------
    Zcomp,
    Zprops,
    Pmod,
    Cnew,
    Crem,

    // -------Commands for rule processors-------
    Rnew,
    Pmuda,
    Rlista,
    Rrem,
    Asoc,
    Ades,

    // -------Commands to interact with devices-------
    Acom,

    // -------Commands for copying/retrieving rule processors--------
    Psalva,
    Prepoe,
    Prem,
    Plista,

    // -------Additional general commands--------
    Exec,

    // -------Special commands----------
    Exit
};

class CommandFromString : {
public:
    CommandFromString(std::string command);
    bool isValid() const; // calls command type
    std::optional<CommandType> getCommandType() const;

    std::vector<Token> getTokens() const;
    std::string getCommandTypeAsString() const;

private:
    std::vector<Token> _tokens;

    // -------Commands for simulated time-------
    bool isNext() const;
    bool isAdvance() const;

    // -------Commands for managing housing and zones------
    bool isHnova() const;
    bool isHrem() const;
    bool isZnew() const;
    bool isZrem() const;
    bool isZlista() const;

    // -------Commands to manage zones and their content-------
    bool isZcomp() const;
    bool isZprops() const;
    bool isPmod() const;
    bool isCnew() const;
    bool isCrem() const;

    // -------Commands for rule processors-------
    bool isRnew() const;
    bool isPmuda() const;
    bool isRlista() const;
    bool isRrem() const;
    bool isAsoc() const;
    bool isAdes() const;

    // -------Commands to interact with devices-------
    bool isAcom() const;

    // -------Commands for copying/retrieving rule processors--------
    bool isPsalva() const;
    bool isPrepoe() const;
    bool isPrem() const;
    bool isPlista() const;

    // -------Additional general commands--------
    bool isExec() const;

    // -------Special commands----------
    bool isExit() const;

};

class CommandFromFile {
public:
    CommandFromFile(const std::string& filename);

    bool isValid();
    std::vector<std::optional<CommandType>> getCommandTypes();

    std::vector<std::vector<Token>> getTokenMatrix();

    std::vector<std::string> getCommandsTypesAsStrings();

private:
    std::vector<std::vector<Token>> _tokensMatrix
};
