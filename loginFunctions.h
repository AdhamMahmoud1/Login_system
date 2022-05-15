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
    string a;
    
    //login variables 
    string UserNameAttempt;
    string PassWordAttempt;
    string IDAttempt; 

public:
    void data(string n, string i, string m, string pw, string p, string em, string uA, string pA, string iA)
    {
        name = n;
        id = i;
        email = m;
        password = pw;
        phon = p;
        a = em;

        UserNameAttempt = uA;
        PassWordAttempt = pA;
        IDAttempt = iA;
    }
    void registing();
    void saveData();
    int encrypt(int letter);
    bool check_name(string);
    bool check_mail(string);
    bool check_phon(string);
    bool check_id(string); 
    void search_mail(string);
    bool is_valid_repeated(string& str); 
    bool strong_pass(string& str);
    void is_valid_password(string& str);
    string insertPasword();

    // login functions
    void login();
    bool checkFile(string attempt, string ID, const char* filePath);
    bool searchForWord(string line, string attempt1);

};
#endif
