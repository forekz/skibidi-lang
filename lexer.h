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
    TOKEN_YOU,        // Новое ключевое слово (вместо while)
    TOKEN_SEE,        // Новое ключевое слово (вместо print)
    TOKEN_MY,         // Новое ключевое слово (для объявления переменной)
    TOKEN_FACE,       // Новое ключевое слово (для возврата значения)
    TOKEN_GOING,      // Новое ключевое слово (для цикла)
    TOKEN_CAMERAMAN,
    TOKEN_TOILET,
    TOKEN_DANCE,
    TOKEN_TRANSFORM,
    TOKEN_DOPA
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