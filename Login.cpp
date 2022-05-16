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
    cout << "Welcome dear user!\nWhat do you want?";
    
    
    do
    {
        cout << "\n1_Login\n2_Registing\n3_Change PassWord\n4_Exit\n--->";
        cin >> choice;
        if(choice == 1)
        {
            p.login();
        }    
        else if(choice == 2)
        {    
            p.registing();
        }else if(choice == 3)
        {
            p.change_password();
            
        }
    } while (choice != 4);
        
    
    return 0;
}
