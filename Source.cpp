#include <iostream>
#include <cstring>
#include <Windows.h>
#pragma warning(disable : 4996)
using namespace std;

class MyString {
	char* str;
	int length;
    static int objCount;

public:
    MyString() {
        length = 80;
        str = new char[length + 1];
        for (int i = 0; i < length; ++i) {
            str[i] = '\0';
        }
        str[length] = '\0';

        objCount++;
    }

    MyString(int size) {
        length = size;
        str = new char[length + 1];
        for (int i = 0; i < length; ++i) {
            str[i] = '\0';
        }
        str[length] = '\0';
        objCount++;
    }

    MyString(const char* inputStr) {
        length = MyStrLen(inputStr);
        str = new char[length + 1];
        MyStrcpy(str, inputStr);
        objCount++;
    }

    MyString(const MyString& other) {
        length = other.length;
        str = new char[length + 1];
        MyStrcpy(str, other.str);
        objCount++;
    }

    ~MyString() {
        delete[] str;
        objCount--;
    }

    void Input() {
        cout << "������� ������: ";
        cin.getline(str, length);
    }

    void Output() const {
        cout << str << endl;
    }

    void MyStrcpy(char* dest, const char* src) //����������� ����� 
    {
        int i = 0;
        while (src[i] != '\0') {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }

    bool MyStrStr(const char* substr) // ����� ��������� � ������
    {
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

    int MyChr(char c) //����� ������� � ������ 
    {
        for (int i = 0; i < length; ++i) {
            if (str[i] == c) {
                return i;
            }
        }
        return -1;
    }

    int MyStrLen(const char* s = nullptr) const {
        if (!s) s = str;
        int len = 0;
        while (s[len] != '\0') {
            len++;
        }
        return len;
    }

    void MyStrCat(MyString& b) //����������� �����
    {
        char* newStr = new char[length + b.length + 2]; 
        for (int i = 0; i < length; ++i) {
            newStr[i] = str[i];
        }
        newStr[length] = ' '; 
        for (int i = 0; i < b.length; ++i) {
            newStr[length + 1 + i] = b.str[i];
        }
        newStr[length + b.length + 1] = '\0';  
        delete[] str;
        str = newStr;
        length += (b.length + 1);
    }

    void MyDelChr(char c) //������� ��������� ������ 
    {
        int newLength = 0;
        for (int i = 0; i < length; ++i) {
            if (str[i] != c) str[newLength++] = str[i];
        }
        str[newLength] = '\0';
        length = newLength;
    }

    int MyStrCmp(MyString& b) //��������� �����
    {
        int i = 0;

        while (str[i] != '\0' && b.str[i] != '\0') {
            if (str[i] < b.str[i]) return -1;
            if (str[i] > b.str[i]) return 1;
            i++;
        }

        if (str[i] == '\0' && b.str[i] != '\0') return -1;  
        if (str[i] != '\0' && b.str[i] == '\0') return 1; 

        return 0;
    }


    MyString operator+(const MyString& b) const {
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

    MyString& operator=(const MyString& other) {
        if (this == &other) return *this;
        delete[] str;
        length = other.length;
        str = new char[length + 1];
        MyStrcpy(str, other.str);
        return *this;
    }

    bool operator==(const MyString& other) const {
        if (length != other.length) {
            return false;
        }

        for (int i = 0; i < length; ++i) {
            if (str[i] != other.str[i]) {
                return false; 
            }
        }

        return true; 
    }

    static int getObjectCount() {
        return objCount;
    }
};

int MyString::objCount = 0;

int main() {
    // �������� �����
    MyString str1("Hello");
    MyString str2("World");

    // ������������ ������� MyStrCat (����������� �����)
    cout << "Demonstration of MyStrCat: ";
    str1.MyStrCat(str2);
    str1.Output();

    // ������������ ������� MyStrLen (����� ������)
    cout << "Demonstration of MyStrLen: " << str1.MyStrLen() << endl;

    // ������������ ������� MyStrStr (����� ���������)
    cout << "Demonstration of MyStrStr ('World'): " << (str1.MyStrStr("World") ? "Found" : "Not Found") << endl;

    // ������������ ������� MyChr (����� �������)
    cout << "Demonstration of MyChr ('o'): Index = " << str1.MyChr('o') << endl;

    // ������������ ��������� + (������������)
    cout << "Demonstration of + operator: ";
    MyString str3 = str1 + str2;
    str3.Output();

    // ������������ ������� MyDelChr (�������� �������)
    cout << "Demonstration of MyDelChr ('o'): " ;
    str1.MyDelChr('o');
    str1.Output();

    // ������������ ��������� == (��������� �����)
    cout << "Demonstration of == operator: ";
    cout << (str1 == str2 ? "Equal" : "Not Equal") << endl;

    // ������������ ������� MyStrCmp (��������� �����)
    cout << "Demonstration of MyStrCmp: " << endl;
    cout << "Comparing str1 and str2: " << str1.MyStrCmp(str2) << endl;

    // ������������ ����������� ������ (MyStrcpy)
    cout << "Demonstration of MyStrcpy: ";
    MyString str4;
    str4.MyStrcpy(str2.str, str1.str);
    str4.Output();

    // ���������� ��������
    cout << "Object count: " << MyString::getObjectCount() << endl;

    return 0;
}