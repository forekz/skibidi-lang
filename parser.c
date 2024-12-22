#include "parser.h"

Parser* create_parser(Lexer* lexer) {
    Parser* parser = (Parser*)malloc(sizeof(Parser));
    parser->lexer = lexer;
    parser->current_token = get_next_token(lexer);
    return parser;
}

void eat(Parser* parser, TokenType type) {
    if (parser->current_token->type == type) {
        parser->current_token = get_next_token(parser->lexer);
    } else {
        printf("Ошибка синтаксиса: ожидался токен типа %d\n", type);
        exit(1);
    }
}

ASTNode* create_node(NodeType type) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = type;
    node->left = NULL;
    node->right = NULL;
    node->condition = NULL;
    node->body = NULL;
    node->else_body = NULL;
    node->token = NULL;
    return node;
}

ASTNode* parse_number(Parser* parser) {
    ASTNode* node = create_node(NODE_NUMBER);
    node->token = parser->current_token;
    eat(parser, TOKEN_NUMBER);
    return node;
}

ASTNode* parse_identifier(Parser* parser) {
    ASTNode* node = create_node(NODE_IDENTIFIER);
    node->token = parser->current_token;
    eat(parser, TOKEN_IDENTIFIER);
    return node;
}

ASTNode* parse_expression(Parser* parser);

ASTNode* parse_factor(Parser* parser) {
    Token* token = parser->current_token;
    
    switch (token->type) {
        case TOKEN_NUMBER:
            return parse_number(parser);
        case TOKEN_IDENTIFIER:
            return parse_identifier(parser);
        case TOKEN_LPAREN: {
            eat(parser, TOKEN_LPAREN);
            ASTNode* node = parse_expression(parser);
            eat(parser, TOKEN_RPAREN);
            return node;
        }
        default:
            printf("Ошибка синтаксиса: неожиданный токен\n");
            exit(1);
    }
}

ASTNode* parse_term(Parser* parser) {
    ASTNode* node = parse_factor(parser);

    while (parser->current_token->type == TOKEN_MULTIPLY || 
           parser->current_token->type == TOKEN_DIVIDE) {
        Token* token = parser->current_token;
        if (token->type == TOKEN_MULTIPLY)
            eat(parser, TOKEN_MULTIPLY);
        else
            eat(parser, TOKEN_DIVIDE);

        ASTNode* new_node = create_node(NODE_BINARY_OP);
        new_node->token = token;
        new_node->left = node;
        new_node->right = parse_factor(parser);
        node = new_node;
    }

    return node;
}

ASTNode* parse_expression(Parser* parser) {
    ASTNode* node = parse_term(parser);

    while (parser->current_token->type == TOKEN_PLUS || 
           parser->current_token->type == TOKEN_MINUS) {
        Token* token = parser->current_token;
        if (token->type == TOKEN_PLUS)
            eat(parser, TOKEN_PLUS);
        else
            eat(parser, TOKEN_MINUS);

        ASTNode* new_node = create_node(NODE_BINARY_OP);
        new_node->token = token;
        new_node->left = node;
        new_node->right = parse_term(parser);
        node = new_node;
    }

    return node;
}

ASTNode* parse_statement(Parser* parser) {
    switch (parser->current_token->type) {
        case TOKEN_MY: {
            ASTNode* node = create_node(NODE_MY);
            eat(parser, TOKEN_MY);
            node->left = parse_identifier(parser);
            if (parser->current_token->type == TOKEN_ASSIGN) {
                eat(parser, TOKEN_ASSIGN);
                node->right = parse_expression(parser);
            }
            eat(parser, TOKEN_SEMICOLON);
            return node;
        }
        case TOKEN_IDENTIFIER: {
            ASTNode* node = create_node(NODE_ASSIGNMENT);
            node->left = parse_identifier(parser);
            eat(parser, TOKEN_ASSIGN);
            node->right = parse_expression(parser);
            eat(parser, TOKEN_SEMICOLON);
            return node;
        }
        case TOKEN_DOP: {
            ASTNode* node = create_node(NODE_IF);
            eat(parser, TOKEN_DOP);
            eat(parser, TOKEN_LPAREN);
            node->condition = parse_expression(parser);
            eat(parser, TOKEN_RPAREN);
            node->body = parse_statement(parser);
            if (parser->current_token->type == TOKEN_SKIBIDI) {
                eat(parser, TOKEN_SKIBIDI);
                node->else_body = parse_statement(parser);
            }
            return node;
        }
        case TOKEN_GOING: {
            ASTNode* node = create_node(NODE_GOING);
            eat(parser, TOKEN_GOING);
            eat(parser, TOKEN_LPAREN);
            node->condition = parse_expression(parser);
            eat(parser, TOKEN_RPAREN);
            node->body = parse_statement(parser);
            return node;
        }
        case TOKEN_SEE: {
            ASTNode* node = create_node(NODE_SEE);
            eat(parser, TOKEN_SEE);
            eat(parser, TOKEN_LPAREN);
            node->body = parse_expression(parser);
            eat(parser, TOKEN_RPAREN);
            eat(parser, TOKEN_SEMICOLON);
            return node;
        }
        case TOKEN_FACE: {
            ASTNode* node = create_node(NODE_FACE);
            eat(parser, TOKEN_FACE);
            node->body = parse_expression(parser);
            eat(parser, TOKEN_SEMICOLON);
            return node;
        }
        case TOKEN_YOU: {
            ASTNode* node = create_node(NODE_YOU);
            eat(parser, TOKEN_YOU);
            node->left = parse_identifier(parser);
            eat(parser, TOKEN_SEMICOLON);
            return node;
        }
        case TOKEN_CAMERAMAN: {
            ASTNode* node = create_node(NODE_CAMERAMAN);
            eat(parser, TOKEN_CAMERAMAN);
            node->left = parse_identifier(parser);  // имя камерамена
            eat(parser, TOKEN_SEMICOLON);
            return node;
        }
        case TOKEN_TOILET: {
            ASTNode* node = create_node(NODE_TOILET);
            eat(parser, TOKEN_TOILET);
            node->left = parse_identifier(parser);  // имя туалета
            eat(parser, TOKEN_SEMICOLON);
            return node;
        }
        case TOKEN_DANCE: {
            ASTNode* node = create_node(NODE_DANCE);
            eat(parser, TOKEN_DANCE);
            eat(parser, TOKEN_LPAREN);
            node->left = parse_identifier(parser);  // кто танцует
            eat(parser, TOKEN_RPAREN);
            eat(parser, TOKEN_SEMICOLON);
            return node;
        }
        case TOKEN_TRANSFORM: {
            ASTNode* node = create_node(NODE_TRANSFORM);
            eat(parser, TOKEN_TRANSFORM);
            eat(parser, TOKEN_LPAREN);
            node->left = parse_identifier(parser);  // кто трансформируется
            eat(parser, TOKEN_RPAREN);
            eat(parser, TOKEN_SEMICOLON);
            return node;
        }
        case TOKEN_DOPA: {
            ASTNode* node = create_node(NODE_DOPA);
            eat(parser, TOKEN_DOPA);
            eat(parser, TOKEN_LPAREN);
            node->left = parse_identifier(parser);  // кого усиливаем
            eat(parser, TOKEN_RPAREN);
            eat(parser, TOKEN_SEMICOLON);
            return node;
        }
        case TOKEN_WHILE: {
            ASTNode* node = create_node(NODE_WHILE);
            eat(parser, TOKEN_WHILE);
            eat(parser, TOKEN_LPAREN);
            node->condition = parse_expression(parser);
            eat(parser, TOKEN_RPAREN);
            node->body = parse_statement(parser);
            return node;
        }
        case TOKEN_PRINT: {
            ASTNode* node = create_node(NODE_PRINT);
            eat(parser, TOKEN_PRINT);
            eat(parser, TOKEN_LPAREN);
            node->body = parse_expression(parser);
            eat(parser, TOKEN_RPAREN);
            eat(parser, TOKEN_SEMICOLON);
            return node;
        }
        case TOKEN_LBRACE: {
            ASTNode* node = create_node(NODE_BLOCK);
            eat(parser, TOKEN_LBRACE);
            // TODO: Реализовать парсинг блока кода
            eat(parser, TOKEN_RBRACE);
            return node;
        }
        default:
            printf("Ошибка синтаксиса: неожиданный токен\n");
            exit(1);
    }
}

ASTNode* parse(Parser* parser) {
    return parse_statement(parser);
}

void free_ast(ASTNode* node) {
    if (node == NULL) return;
    
    free_ast(node->left);
    free_ast(node->right);
    free_ast(node->condition);
    free_ast(node->body);
    free_ast(node->else_body);
    free(node);
}

void free_parser(Parser* parser) {
    free(parser);
} 