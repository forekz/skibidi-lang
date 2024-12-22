#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

// Типы узлов AST
typedef enum {
    NODE_NUMBER,
    NODE_BINARY_OP,
    NODE_IDENTIFIER,
    NODE_ASSIGNMENT,
    NODE_IF,
    NODE_GOING,     // Вместо WHILE
    NODE_SEE,       // Вместо PRINT
    NODE_BLOCK,
    NODE_MY,        // Для объявления переменных
    NODE_FACE,      // Для возврата значения
    NODE_YOU,       // Для специальных операций
    NODE_CAMERAMAN,
    NODE_TOILET,
    NODE_DANCE,
    NODE_TRANSFORM,
    NODE_DOPA
} NodeType;

// Структура узла AST
typedef struct ASTNode {
    NodeType type;
    struct ASTNode* left;
    struct ASTNode* right;
    struct ASTNode* condition;
    struct ASTNode* body;
    struct ASTNode* else_body;
    Token* token;
} ASTNode;

// Структура парсера
typedef struct {
    Lexer* lexer;
    Token* current_token;
} Parser;

// Функции парсера
Parser* create_parser(Lexer* lexer);
ASTNode* parse(Parser* parser);
void free_parser(Parser* parser);
void free_ast(ASTNode* node);

#endif 