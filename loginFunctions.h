#ifndef LOGINFUNCTIONS_H_INCLUDED
#define LOGINFUNCTIONS_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <regex>
#include<conio.h>

using namespace std;

class profile
{
private:
    string name;
    string id;
    string email;
    string password;
    string phon;

public:
    void data(string n, string i, string m, string pw, string p)
    {
        name = n;
        id = i;
        email = m;
        password = pw;
        phon = p;
    }
    void registing();
    void login();
    void saveData();
    int encrypt(int letter);
    bool check_name(string);
    bool check_mail(string);
    bool check_phon(string);
    bool check_id(string); 
    bool is_valid_repeated(string& str); 
    bool strong_pass(string& str);
    bool is_valid_password(string& str);
};
#endif