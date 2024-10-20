#include <iostream>
#include <cstring>
#include <Windows.h>
#pragma warning(disable : 4996)
#include "Header.h"
using namespace std;

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
    cout << "Demonstration of MyDelChr ('o'): ";
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
    str4.MyStrcpy(str4.GetStr(), str1.GetStr());
    str4.Output();

    // �������� ��������� = (������������)
    cout << "Demonstration of operator= : ";
    MyString str5;
    str5 = str1;
    str5.Output();

    // ���������� ��������
    cout << "Object count: " << MyString::getObjectCount() << endl;

    MyString str6("Hello");

    //������������ ��������� []
    cout << "Demonstration of [] operator: " << str6[1] << endl;

    //// ������������ ��������� ()
    str6();
    cout << "Updated string: ";
    str6.Output();

    //// ������������ ���������� ������� � �����
    MyString str7 = str6 + 'A';  
    cout << "After adding 'A' to the end: ";
    str7.Output();

    // ������������ ���������� ������� � ������
    cout << "Adding 'A' to beginning: ";
    str7 = 'A' + str6;
    str7.Output();

    // ������������ ���������� 10 ��������  � ����� ������
    MyString str8 = str6 + 10; 
    cout << "After adding 10 ! to the end: ";
    str8.Output();

    // ������������ ���������� 10 �������� � ������ ������
    MyString str9 = 10 + str6;  
    cout << "After adding 10 ! to the start: ";
    str8.Output();

    // ����������� ���������
    cout << "Add _ to the end: ";
    MyString str10 = str6++;
    str10.Output();

    // ����������� ��������� (���������� � ������)
    cout << "Add _ to the start: ";
    MyString str11 = ++str6;
    str11.Output();

    return 0;
}