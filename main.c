#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "parser.h"

void print_token(Token* token) {
    printf("Token(type=%d, value='%s')\n", token->type, token->value ? token->value : "NULL");
}

int main() {
    char* source = "my skibidi_toilet;\n"
                   "cameraman you_see;\n"
                   "transform(skibidi_toilet);\n"
                   "going (my face) {\n"
                   "    dance(you_see);\n"
                   "    dop (skibidi_toilet) {\n"
                   "        see(you_see);\n"
                   "    } skibidi {\n"
                   "        face 0;\n"
                   "    }\n"
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