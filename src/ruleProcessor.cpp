#include "ruleProcessor.hpp"

class Rule {
public:
    // Pure virtual function evaluate
    virtual bool evaluate() const = 0;

    // Virtual destructor (optional but recommended for abstract classes)
    virtual ~Rule() {}
};