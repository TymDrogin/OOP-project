#include "ruleProcessor.hpp"

RuleProcessor::RuleProcessor(std::vector<std::unique_ptr<Rule>>& rules_ref) : _rules(rules_ref){}

void RuleProcessor::process() {
    for(auto &rule : _rules) {
        rule->evaluate();
    }
}
