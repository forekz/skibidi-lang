#include "lexer.h"

Lexer* create_lexer(char* source) {
    Lexer* lexer = (Lexer*)malloc(sizeof(Lexer));
    lexer->source = source;
    lexer->position = 0;
    lexer->length = strlen(source);
    return lexer;
}

char peek(Lexer* lexer) {
    if (lexer->position >= lexer->length) {
        return '\0';
    }
    return lexer->source[lexer->position];
}

char advance(Lexer* lexer) {
    if (lexer->position >= lexer->length) {
        return '\0';
    }
    return lexer->source[lexer->position++];
}

void skip_whitespace(Lexer* lexer) {
    while (isspace(peek(lexer))) {
        advance(lexer);
    }
}

Token* create_token(TokenType type, char* value) {
    Token* token = (Token*)malloc(sizeof(Token));
    token->type = type;
    token->value = value;
    return token;
}

Token* get_next_token(Lexer* lexer) {
    skip_whitespace(lexer);

    char current = peek(lexer);
    
    if (current == '\0') {
        return create_token(TOKEN_EOF, NULL);
    }

    // Обработка чисел
    if (isdigit(current)) {
        char* number = (char*)malloc(256);
        int i = 0;
        while (isdigit(peek(lexer))) {
            number[i++] = advance(lexer);
        }
        number[i] = '\0';
        return create_token(TOKEN_NUMBER, number);
    }

    // Обработка идентификаторов и ключевых слов
    if (isalpha(current)) {
        char* identifier = (char*)malloc(256);
        int i = 0;
        while (isalnum(peek(lexer))) {
            identifier[i++] = advance(lexer);
        }
        identifier[i] = '\0';

        if (strcmp(identifier, "dop") == 0) return create_token(TOKEN_DOP, identifier);
        if (strcmp(identifier, "skibidi") == 0) return create_token(TOKEN_SKIBIDI, identifier);
        if (strcmp(identifier, "you") == 0) return create_token(TOKEN_YOU, identifier);
        if (strcmp(identifier, "see") == 0) return create_token(TOKEN_SEE, identifier);
        if (strcmp(identifier, "my") == 0) return create_token(TOKEN_MY, identifier);
        if (strcmp(identifier, "face") == 0) return create_token(TOKEN_FACE, identifier);
        if (strcmp(identifier, "going") == 0) return create_token(TOKEN_GOING, identifier);
        if (strcmp(identifier, "cameraman") == 0) return create_token(TOKEN_CAMERAMAN, identifier);
        if (strcmp(identifier, "toilet") == 0) return create_token(TOKEN_TOILET, identifier);
        if (strcmp(identifier, "dance") == 0) return create_token(TOKEN_DANCE, identifier);
        if (strcmp(identifier, "transform") == 0) return create_token(TOKEN_TRANSFORM, identifier);
        if (strcmp(identifier, "dopa") == 0) return create_token(TOKEN_DOPA, identifier);

        return create_token(TOKEN_IDENTIFIER, identifier);
    }

    // Обработка операторов
    char operator = advance(lexer);
    char* op_str = (char*)malloc(2);
    op_str[0] = operator;
    op_str[1] = '\0';

    switch (operator) {
        case '+': return create_token(TOKEN_PLUS, op_str);
        case '-': return create_token(TOKEN_MINUS, op_str);
        case '*': return create_token(TOKEN_MULTIPLY, op_str);
        case '/': return create_token(TOKEN_DIVIDE, op_str);
        case '=': return create_token(TOKEN_ASSIGN, op_str);
        case ';': return create_token(TOKEN_SEMICOLON, op_str);
        case '(': return create_token(TOKEN_LPAREN, op_str);
        case ')': return create_token(TOKEN_RPAREN, op_str);
        case '{': return create_token(TOKEN_LBRACE, op_str);
        case '}': return create_token(TOKEN_RBRACE, op_str);
    }

    free(op_str);
    return NULL;
}

void free_lexer(Lexer* lexer) {
    free(lexer);
} 