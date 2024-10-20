//HW_10
#include <iostream>
#include <cstring>
#include <Windows.h>
#pragma warning(disable : 4996)
#include "Header.h"
using namespace std;

int MyString::objCount = 0;

MyString::MyString() {
    length = 80;
    str = new char[length + 1];
    for (int i = 0; i < length; ++i) {
        str[i] = '\0';
    }
    str[length] = '\0';
    objCount++;
}

MyString::MyString(int size) {
    length = size;
    str = new char[length + 1];
    for (int i = 0; i < length; ++i) {
        str[i] = '\0';
    }
    str[length] = '\0';
    objCount++;
}

MyString::MyString(const char* inputStr) {
    length = strlen(inputStr);
    str = new char[length + 1];
    strcpy(str, inputStr);
    objCount++;
}

MyString::MyString(const MyString& other) {
    length = other.length;
    str = new char[length + 1];
    strcpy(str, other.str);
    objCount++;
}

MyString::~MyString() {
    delete[] str;
    objCount--;
}

char* MyString:: GetStr() const {
    return str;
}


void MyString::Input() {
    cout << "Enter string: ";
    cin.getline(str, length);
}

void MyString::Output() const {
    cout << str << endl;
}

void MyString::MyStrcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

bool MyString::MyStrStr(const char* substr) {
    int substrLen = MyStrLen(substr);
    if (substrLen == 0 || substrLen > length) {
        return false;
    }

    for (int i = 0; i <= length - substrLen; ++i) {
        int j = 0;
        while (j < substrLen && str[i + j] == substr[j]) {
            j++;
        }
        if (j == substrLen) {
            return true;
        }
    }
    return false;
}

int MyString::MyChr(char c) {
    for (int i = 0; i < length; ++i) {
        if (str[i] == c) {
            return i;
        }
    }
    return -1;
}

int MyString::MyStrLen(const char* s) const {
    if (!s) s = str;
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

void MyString::MyStrCat(MyString& b) {
    char* newStr = new char[length + b.length + 1]; // Убираем лишний пробел
    for (int i = 0; i < length; ++i) {
        newStr[i] = str[i];
    }
    for (int i = 0; i < b.length; ++i) {
        newStr[length + i] = b.str[i];
    }
    newStr[length + b.length] = '\0';
    delete[] str;
    str = newStr;
    length += b.length;
}

void MyString::MyDelChr(char c) {
    int newLength = 0;
    for (int i = 0; i < length; ++i) {
        if (str[i] != c) str[newLength++] = str[i];
    }
    str[newLength] = '\0';
    length = newLength;
}

int MyString::MyStrCmp(MyString& b) {
    int i = 0;
    while (i < length && i < b.length) {
        if (str[i] < b.str[i]) return -1;
        if (str[i] > b.str[i]) return 1;
        i++;
    }

    if (i == length && i < b.length) return -1;
    if (i == b.length && i < length) return 1;
    return 0;
}

MyString MyString::operator+(const MyString& b) const {
    MyString result(length + b.length);
    for (int i = 0; i < length; ++i) {
        result.str[i] = str[i];
    }
    for (int i = 0; i < b.length; ++i) {
        result.str[length + i] = b.str[i];
    }
    result.str[length + b.length] = '\0';
    return result;
}

MyString MyString::operator=(const MyString& other) {
    if (this == &other) return *this;
    delete[] str;
    length = other.MyStrLen();
    str = new char[length + 1];
    MyStrcpy(str, other.GetStr());
    return *this;
}

bool MyString::operator==(const MyString& other) const {
    return strcmp(str, other.str) == 0;
}

int MyString::getObjectCount() {
    return objCount;
}

//HW_11
char& MyString::operator[](int index) {
    return str[index];
}

const char& MyString::operator[](int index) const {
    return str[index];
}

void MyString::operator()() {
    Input(); 
}

MyString operator+(const MyString& a, char b) {
    int newLength = a.MyStrLen() + 1;
    char* newStr = new char[newLength + 1];

    for (int i = 0; i < newLength - 1; i++)
    {
        newStr[i] = a[i];
    }

    newStr[newLength - 1] = b;
    newStr[newLength] = '\0';

    MyString newString(newStr);
    delete[] newStr;
    return newString;
}

MyString operator+(char b, const MyString& a) {
    int newLength = a.MyStrLen() + 1;
    char* newStr = new char[newLength + 1];

    for (int i = 0; i < newLength - 1; i++) 
    {
        newStr[i + 1] = a[i];
    }

    newStr[0] = b;
    newStr[newLength] = '\0';

    MyString newString(newStr);
    delete[] newStr;
    return newString;
}

MyString operator+(const MyString& a, int num) {
    int newLength = a.MyStrLen() + num;
    char* newStr = new char[newLength + 1];

    for (int i = 0; i < newLength - 1; i++)
    {
        newStr[i] = a[i];
    }
    for (int i = a.MyStrLen(); i < newLength; i++) {
        newStr[i] = '!';
    }
    newStr[newLength] = '\0';

    MyString newString(newStr);
    delete[] newStr;
    return newString;
}

MyString operator+(int num, const MyString& a) {
    int newLength = a.MyStrLen() + num;
    char* newStr = new char[newLength + 1];

    for (int i = 0; i < num; i++) {
        newStr[i] = '!'; 
    }

    for (int i = 0; i < a.MyStrLen(); i++) {
        newStr[i + num] = a[i];
    }

    newStr[newLength] = '\0';

    MyString newString(newStr);
    delete[] newStr;
    return newString;
}

MyString MyString::operator++()
{
    int newLength = MyStrLen() + 1;
    char* newStr = new char[newLength + 1];

    for (int i = 0; i < MyStrLen(); i++)
    {
        newStr[i + 1] = (*this)[i];
    }

    newStr[0] = '_';
    newStr[newLength] = '\0';

    MyString newString(newStr);
    delete[] newStr;
    return newString;
}

MyString MyString::operator++(int)
{
    int newLength = MyStrLen() + 1;
    char* newStr = new char[newLength + 1];

    for (int i = 0; i < MyStrLen(); i++)
    {
        newStr[i] = str[i];
    }

    newStr[newLength - 1] = '_';
    newStr[newLength] = '\0';

    MyString newString(newStr);
    delete[] newStr;
    return newString;
}

//HW_12
void MyString::setLength(int newLength) {
    length = newLength;
}

ostream& operator<<(ostream& os, const MyString& obj)
{
    os << obj.GetStr();
    return os;
}

istream& operator>>(istream& is, MyString& obj)
{
    char buffer[1000];
    is.getline(buffer, 1000);

    int newLength = obj.MyStrLen(buffer);
    delete[] obj.GetStr();

    char* newStr = new char[newLength + 1];
    obj.MyStrcpy(newStr, buffer);
    obj.setLength(newLength);

    return is;
}