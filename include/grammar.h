#pragma once
#include "types.h"
#include <vector>
#include <string>
#include <set>
#include <map>

class GrammarFileReader {
    Grammar grammar_;
    std::set<char> terms_;
    std::set<char> vars_;
    char start_sym;
    std::map<char, std::set<char>> firsts_;
    std::map<char, std::set<char>> follows_;


    public:
        GrammarFileReader();
        GrammarFileReader(std::string);

        void parseFile(std::string);
        void parseSymbols();

        void findFirsts();
        void findFirsts(char non_term);


        void printGrammar();
        void printVariables();
        void printTerminals();
        void print() {
            printGrammar();
            printVariables();
            printTerminals();
        }
        void printFirsts();

        bool isVariable(char var) {
           return (vars_.find(var) != vars_.end());
        }
        bool isTerminal(char term) {
           return (terms_.find(term) != terms_.end());
        }

        Grammar getGrammar() { return grammar_; }
        std::set<char> getTerminals() { return terms_; }
        std::set<char> getVariables() { return vars_; }
        std::set<char> getFirsts(char var) { return firsts_[var]; }
        char getStartSym() { return start_sym; }
};
