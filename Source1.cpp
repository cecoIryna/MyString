#include <iostream>
#include <cstring>
#include <Windows.h>
#pragma warning(disable : 4996)
#include "Header.h"
using namespace std;

int main() {

    // Создание строк
    MyString str1("Hello");
    MyString str2("World");

    // Демонстрация функции MyStrCat (объединение строк)
    cout << "Demonstration of MyStrCat: ";
    str1.MyStrCat(str2);
    str1.Output();

    // Демонстрация функции MyStrLen (длина строки)
    cout << "Demonstration of MyStrLen: " << str1.MyStrLen() << endl;

    // Демонстрация функции MyStrStr (поиск подстроки)
    cout << "Demonstration of MyStrStr ('World'): " << (str1.MyStrStr("World") ? "Found" : "Not Found") << endl;

    // Демонстрация функции MyChr (поиск символа)
    cout << "Demonstration of MyChr ('o'): Index = " << str1.MyChr('o') << endl;

    // Демонстрация оператора + (конкатенация)
    cout << "Demonstration of + operator: ";
    MyString str3 = str1 + str2;
    str3.Output();

    // Демонстрация функции MyDelChr (удаление символа)
    cout << "Demonstration of MyDelChr ('o'): ";
    str1.MyDelChr('o');
    str1.Output();

    // Демонстрация оператора == (сравнение строк)
    cout << "Demonstration of == operator: ";
    cout << (str1 == str2 ? "Equal" : "Not Equal") << endl;

    // Демонстрация функции MyStrCmp (сравнение строк)
    cout << "Demonstration of MyStrCmp: " << endl;
    cout << "Comparing str1 and str2: " << str1.MyStrCmp(str2) << endl;

    // Демонстрация копирования строки (MyStrcpy)
   cout << "Demonstration of MyStrcpy: ";
    MyString str4;
    str4.MyStrcpy(str4.GetStr(), str1.GetStr());
    str4.Output();

    // Проверка оператора = (присваивание)
    cout << "Demonstration of operator= : ";
    MyString str5;
    str5 = str1;
    str5.Output();

    // Количество объектов
    cout << "Object count: " << MyString::getObjectCount() << endl;

    MyString str6("Hello");

    //Демонстрация оператора []
    cout << "Demonstration of [] operator: " << str6[1] << endl;

    //// Демонстрация оператора ()
    str6();
    cout << "Updated string: ";
    str6.Output();

    //// Демонстрация добавления символа в конец
    MyString str7 = str6 + 'A';  
    cout << "After adding 'A' to the end: ";
    str7.Output();

    // Демонстрация добавления символа в начало
    cout << "Adding 'A' to beginning: ";
    str7 = 'A' + str6;
    str7.Output();

    // Демонстрация добавления 10 символов  в конец строки
    MyString str8 = str6 + 10; 
    cout << "After adding 10 ! to the end: ";
    str8.Output();

    // Демонстрация добавления 10 символов в начало строки
    MyString str9 = 10 + str6;  
    cout << "After adding 10 ! to the start: ";
    str8.Output();

    // Постфиксный инкремент
    cout << "Add _ to the end: ";
    MyString str10 = str6++;
    str10.Output();

    // Постфиксный инкремент (добавление в начало)
    cout << "Add _ to the start: ";
    MyString str11 = ++str6;
    str11.Output();

    return 0;
}