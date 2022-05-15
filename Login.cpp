#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <regex>
#include <conio.h>
#include "loginFunctions.cpp"
using namespace std;

int main()
{
    profile p;
    int choice;
    cout << "Welcome dear user!\nWhat do you want?\n1_Login   2_Registing   3_Change PassWord" << endl;
    cin >> choice;
    if(choice == 1)
    {
        p.login();
    }    
    else if(choice == 2)
    {    
        p.registing();
    }
    return 0;
}
