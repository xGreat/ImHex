#pragma once

#include <hex.hpp>

#include "lang/pattern_data.hpp"
#include "ast_node.hpp"

#include <string>
#include <unordered_map>
#include <vector>

namespace hex::lang {

    class Evaluator {
    public:
        Evaluator();

        std::pair<Result, std::vector<PatternData*>> evaluate(const std::vector<ASTNode*>& ast);

    private:
        std::unordered_map<std::string, ASTNode*> m_types;

        std::pair<PatternData*, size_t> createStructPattern(ASTNodeVariableDecl *varDeclNode, u64 offset);
        std::pair<PatternData*, size_t> createEnumPattern(ASTNodeVariableDecl *varDeclNode, u64 offset);
        std::pair<PatternData*, size_t> createArrayPattern(ASTNodeVariableDecl *varDeclNode, u64 offset);
        std::pair<PatternData*, size_t> createStringPattern(ASTNodeVariableDecl *varDeclNode, u64 offset);
        std::pair<PatternData*, size_t> createCustomTypePattern(ASTNodeVariableDecl *varDeclNode, u64 offset);
        std::pair<PatternData*, size_t> createBuiltInTypePattern(ASTNodeVariableDecl *varDeclNode, u64 offset);

    };

}