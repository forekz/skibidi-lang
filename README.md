# Skibidi Language

Skibidi - это лучший язык программирования в мире, основанный на меме "Skibidi Toilet".

## Особенности языка

- Ключевые слова из песни Skibidi: `you`, `see`, `my`, `face`, `going`
- Условные конструкции: `dop` (if) и `skibidi` (else)
- Работа с камераменами и туалетами
- Специальные команды: `transform`, `dance`, `dopa`

## Пример кода

```c
my skibidi_toilet;           // Объявление переменной
cameraman you_see;          // Создание камерамена
transform(skibidi_toilet);  // Трансформация
going (my face) {          // Цикл
    dance(you_see);        // Танец
    dop (skibidi_toilet) { // Условие
        see(you_see);      // Вывод
    } skibidi {            // Иначе
        face 0;            // Возврат значения
    }
}
```

## Установка

1. Убедитесь, что у вас установлен компилятор GCC
2. Клонируйте репозиторий:
```bash
git clone https://github.com/forekz/skibidi-lang.git
```
3. Соберите проект:
```bash
gcc -Wall -Wextra main.c lexer.c parser.c -o skibidi
```

## Синтаксис

### Ключевые слова
- `my` - Объявление переменной
- `you` - Специальная операция
- `see` - Вывод значения (аналог print)
- `face` - Возврат значения
- `going` - Цикл (аналог while)

### Типы объектов
- `cameraman` - Камераман
- `toilet` - Скибиди туалет

### Команды
- `transform(object)` - Трансформация объекта
- `dance(object)` - Заставить объект танцевать
- `dopa(object)` - Усилить объект

### Управляющие конструкции
- `dop (условие) { ... }` - Условный оператор
- `skibidi { ... }` - Альтернативная ветка условного оператора
- `going (условие) { ... }` - Цикл

## Лицензия

MIT License 