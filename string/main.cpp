#include "string.h"
#include <iostream>

int main() {
    String s1 = "Hello", s2 = "World", s3 = "Test";

    bool mega_result = (((s1 + " " + s2) += "!") != "" &&              // +, +=, !=
                        (s1 + s2)[0] == 'H' &&                         // +, [], ==
                        (s1 + " " + s2)(0, 5) == "Hello" &&            // +, (), ==
                        s1 < s2 && s2 > s3 && s1 <= s2 && s2 >= s3 &&  // <, >, <=, >=
                        (std::cout << "Все операторы работают!", true) // <<
    );

    // // 1. Конструкторы
    // std::cout << "1. Конструкторы:\n";
    // String str1;
    // String str2("Hello");
    // String str3 = "World";
    // std::cout << "Пустая: '" << str1 << "'\n";
    // std::cout << "Из C-строки: '" << str2 << "'\n";
    // std::cout << "Присвоение: '" << str3 << "'\n";

    // // 2. Копирование и присваивание
    // std::cout << "\n2. Копирование и присваивание:\n";
    // String str4 = str2;
    // String str5;
    // str5 = str3;
    // std::cout << "Копия: '" << str4 << "'\n";
    // std::cout << "Присвоение: '" << str5 << "'\n";

    // // 3. Операторы + и +=
    // std::cout << "\n3. Конкатенация:\n";
    // String str6 = str2 + " " + str3;
    // std::cout << "str2 + str3: '" << str6 << "'\n";

    // String str7 = "Start";
    // str7 += " End";
    // std::cout << "str7 +=: '" << str7 << "'\n";

    // // 4. Оператор []
    // std::cout << "\n4. Доступ по индексу:\n";
    // String str8 = "ABCDE";
    // std::cout << "str8[0] = '" << str8[0] << "'\n";
    // std::cout << "str8[2] = '" << str8[2] << "'\n";

    // // 5. Подстрока ()
    // std::cout << "\n5. Подстрока:\n";
    // String str9 = "Hello World";
    // String substr1 = str9(0, 5);
    // String substr2 = str9(6, 11);
    // std::cout << "str9(0,5): '" << substr1 << "'\n";
    // std::cout << "str9(6,11): '" << substr2 << "'\n";

    // // 6. Сравнение
    // std::cout << "\n6. Сравнение:\n";
    // String a = "apple";
    // String b = "banana";
    // std::cout << "a == b: " << (a == b ? "true" : "false") << "\n";
    // std::cout << "a < b: " << (a < b ? "true" : "false") << "\n";

    // // 7. Ввод
    // std::cout << "\n7. Ввод:\n";
    // String str10;
    // std::cout << "Введите строку: ";
    // std::cin >> str10;
    // std::cout << "Вы ввели: '" << str10 << "'\n";

    // return 0;
}