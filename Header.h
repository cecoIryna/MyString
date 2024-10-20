#pragma once 

class MyString {
    char* str;
    int length;
    static int objCount;

    int x;
    int y;

public:
    MyString();
    MyString(int);
    MyString(const char*);
    MyString(const MyString& other);
    ~MyString();

    char* GetStr() const;

    void Input();
    void Output() const;
    void MyStrcpy(char*, const char*);
    bool MyStrStr(const char*);
    int MyChr(char);
    int MyStrLen(const char* s = nullptr) const; 
    void MyStrCat(MyString& b);
    void MyDelChr(char);
    int MyStrCmp(MyString& b);

    MyString operator+(const MyString& b) const;
    MyString operator=(const MyString& other);

    bool operator==(const MyString& other) const;

    static int getObjectCount();

    char& operator[](int);
    const char& operator[](int) const;
    void operator()();

    MyString operator++();
    MyString operator++(int);

    void setLength(int newLength);
};

MyString operator+(const MyString& a, char b);
MyString operator+(char b, const MyString& a);

MyString operator+(const MyString& a, int num);
MyString operator+(int num, const MyString& a);

ostream& operator << (ostream& os, const MyString& obj);
istream& operator >> (istream& is, MyString& obj);