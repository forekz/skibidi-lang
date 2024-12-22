#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Типы токенов
typedef enum {
    TOKEN_EOF = 0,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MULTIPLY,
    TOKEN_DIVIDE,
    TOKEN_ASSIGN,
    TOKEN_SEMICOLON,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_LBRACE,
    TOKEN_RBRACE,
    TOKEN_DOP,
    TOKEN_SKIBIDI,
    TOKEN_WHILE,
    TOKEN_PRINT,
    TOKEN_CAMERAMAN,    // Для объявления камерамена
    TOKEN_TOILET,       // Для объявления туалета
    TOKEN_DANCE,        // Для выполнения танца
    TOKEN_TRANSFORM,    // Для трансформации
    TOKEN_DOPA         // Для усиления способностей
} TokenType;

// Структура токена
typedef struct {
    TokenType type;
    char* value;
} Token;

// Структура лексера
typedef struct {
    char* source;
    int position;
    int length;
} Lexer;

// Функции лексера
Lexer* create_lexer(char* source);
Token* get_next_token(Lexer* lexer);
void free_lexer(Lexer* lexer);

#endif 