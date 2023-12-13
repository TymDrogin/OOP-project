#include "ruleProcessor.hpp"

RuleProcessor::RuleProcessor(std::unique_ptr<std::vector<Rule>> rules) : _rules(std::move(rules)) {

}
