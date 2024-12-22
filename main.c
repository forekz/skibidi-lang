#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "parser.h"

void print_token(Token* token) {
    printf("Token(type=%d, value='%s')\n", token->type, token->value ? token->value : "NULL");
}

int main() {
    char* source = "cameraman cam1;\n"
                   "toilet toilet1;\n"
                   "transform(toilet1);\n"
                   "dop (cam1) {\n"
                   "    dance(cam1);\n"
                   "    dopa(toilet1);\n"
                   "} skibidi {\n"
                   "    print(0);\n"
                   "}\n";

    printf("Исходный код:\n%s\n", source);

    // Создаем лексер
    Lexer* lexer = create_lexer(source);
    
    // Тестируем лексер
    printf("\nТокены:\n");
    Token* token;
    do {
        token = get_next_token(lexer);
        print_token(token);
    } while (token->type != TOKEN_EOF);

    // Создаем парсер
    lexer = create_lexer(source); // Сбрасываем лексер
    Parser* parser = create_parser(lexer);
    
    // Парсим код
    printf("\nПарсинг...\n");
    ASTNode* ast = parse(parser);
    
    // TODO: Добавить генерацию кода и выполнение

    // Освобождаем память
    free_ast(ast);
    free_parser(parser);
    free_lexer(lexer);

    return 0;
} 