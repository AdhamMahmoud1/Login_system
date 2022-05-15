#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <regex>
#include<conio.h>
#include "loginFunctions.h"

using namespace std;
string pass;
void profile ::registing()
{
   
    cout << "Please Enter your name: ";
    cin >> name;
    while (!check_name(name)){
        cout << "invalid name!\nPlease try again: ";
        cin >> name;
    }
    cout<<"Your password should contain at least one uppercase , lowercase , digit and special charcter\n";
    cout << "Please Enter the password: \n";
    is_valid_password(password);
    for (int i = 0; i < password.length(); i++)
    {
        pass += encrypt(password[i]);
    }
    cout << "Please enter your ID: ";
    cin >> id;
    while (!check_id(id)){
        cout<< "invalid id!\nPlease try again: ";
        cin >> id;
    }
    cout << "Please enter your email: ";
    cin >> email;
    while (!check_mail(email)){
        cout << "invalid email!\nPlease try again: ";
        cin >> email;
    }
    search_mail(email);
    
    cout << "Please enter your phon: ";
    cin >> phon;
    while (!check_phon(phon)){      
        cout << "invalid phon !\nPlease try again: ";
        cin >> phon;
    }
    cout << "thanks" << endl;
    saveData();
}

void profile ::saveData()
{
    ofstream reg("profile_data.txt", ios ::app);
    reg << "name: " << name << endl
        << "Password: " << pass << endl
        << "email: " << email << endl
        << "phon: " << phon << endl 
        << "Id: " << id << "\n\n";
        
    reg.close();
}

int profile::encrypt(int letter)
{
    return letter + 3;
}

bool profile :: check_id(string str)
{
    regex check_id("20(19|20|21)[0-9]{4}");
    return regex_match(str, check_id);
}

bool profile ::check_name(string str)
{
    regex check_name("[A-Z]+[a-z]*");
    return regex_match(str, check_name);
}

bool profile ::check_mail(string str)
{
    regex check_mail("^[a-zA-Z0-9_]+@(hotmail|yahoo|gmail)+.(com|edu|net)$");
    return regex_match(str, check_mail);
}

void profile:: search_mail(string a)
{
    int x;
    fstream reg;
    reg.open("profile_data.txt", ios ::in);
   
    while (!reg.eof()){
        while (getline(reg, a))
        {
            if (a.find(email, 1) != string ::npos)
            {
                cout << "That email has been used before!\nPlease enter another one: ";
                cin >> email;
                while (!check_mail(email)){
                    cout << "invalid email!\nPlease try again: ";
                    cin >> email;
                }
                x = 1;
                break;
            }
        }
        if (x == 0)
        {
            cout << "valid email" << endl;
            break;
        }
    }

    reg.close();
}

bool profile ::check_phon(string str)
{
    regex check_phon("01[0125][0-9]{8}");
    return regex_match(str, check_phon);
}

bool profile ::strong_pass(string& str)
{
    regex pass_format("^(?=.*?[A-Z])(?=.*?[a-z])(?=.*?[0-9])(?=.*?[#?!@$%^&*-]).{8,}$");              // should contain at least one upper case  (?=.*?[A-Z])
      return regex_match(str,pass_format);                                                           // should contain at least one lower case  (?=.*?[a-z])
}                                                                                            // should contain at least one digit       (?=.*?[0-9])                                                                                                         // should contain at least one Special character      (?=.*?[#?!@$%^&*-])   
                                                                                                  // Must be at least 8 characters in length      {8,}
bool profile :: is_valid_repeated(string& str)
{
    bool check = true;
    string password2;
    cout<<"comfirm your password: \n";
   insertPasword(password2);
   

    while (true)
    {  
        
        if(password2!=str)
        {
            check=false;
            cout<<"your should match your password\n";
            cout<<"rewrite your password again: \n";
            insertPasword(password2);
        }
        else{
            cout<<"your password saved";
            break;
            } 
        }
    return 0;
    
}

void profile ::  is_valid_password(string& str)
{
    bool check=true;
  string x=insertPasword(str);
	
    cout<<endl;
    while (true)
    {  
        if(strong_pass(x))
        {
            cout<<"strong password\n";
            break;
        }
        else
        {
            cout<<"week password\n";
            check=false;
            cout<<"Enter your password again: \n";
         insertPasword(str);

    }    
    
}
is_valid_repeated(x);

}

//________________________________________________________________________

void profile :: login()
{
    cout << "\nEnter ID, Email, PassWord. \n";
    cout << "Please enter your ID: ";
    cin >> IDAttempt;
    while (!check_id(IDAttempt)){
        cout<< "invalid id!\nPlease try again: ";
        cin >> IDAttempt;
    }


    cout << "Enter your Email:";
    cin >> UserNameAttempt;

    if(checkFile(UserNameAttempt, IDAttempt, "profile_data.txt"))
    {
        string pass;
        cout<<"Enter your password: ";
       string x= insertPasword(pass);

        for (int i = 0; i < PassWordAttempt.length(); i++)
        {
            x += encrypt(PassWordAttempt[i]);
        }
        if(checkFile(pass, IDAttempt, "profile_data.txt"))
        {
            cout << "\nSuccessful login\n\n";
            PassWordAttempt.erase(PassWordAttempt.begin(), PassWordAttempt.end());
            

        }else
        {
            cout << "\nInValid PassWord :(\nTry Again :)\n";
            PassWordAttempt.erase(PassWordAttempt.begin(), PassWordAttempt.end());
            login();
        }
    }else
    {
        cout << "\nInvalid UserName or Paasword :(\n try Again :)\n";
        PassWordAttempt.erase(PassWordAttempt.begin(), PassWordAttempt.end());
        login();
    }

}

bool profile :: checkFile(string attempt, string ID, const char* filePath)
{
    string word, content, object, line;
    fstream myfile;
    int a = 0;

    myfile.open(filePath, ios::in);

    if(!myfile)
    {
        cout<<"error whlie opening file";
        return false;
    }
    else
    {
        while (true)
        {
        
            while(getline(myfile,word))
            {
                stringstream sin(word);
                sin >> object;
                sin >> content;

            
                if(content == ID)
                {
                    
                    if(searchForWord(line, attempt))
                    {
                        a = 1;
                        return true;
                    }else
                    {
                        line.erase(line.begin(),line.end());
                    }
                }else if(object == "Id:")
                {
                    line.erase(line.begin(),line.end());
                }else
                {
                    line += (content + "\n");
                }
                
            }

            if(a == 0)
            {
                return false;
            }

            if(myfile.peek() == EOF)
            {
                myfile.close();
                return false;
            }


        }
    }
    
}

bool profile :: searchForWord(string line, string attempt1)
{
    if(line.find(attempt1,0) != string :: npos)
    {
        return true;
    }else
    {
        return false;
    }
}
string profile::insertPasword(string& str) {

    
    char ch;

   
    

    // while pressed key not equal enter
    while ((ch = getch()) != '\r')
    {
        // check if returned key from getch is a backspace and stream isn't empty
        if ((ch == 8) && (str.size() > 0))
        {
            // use pop_back to remove the last character added to the string
            str.pop_back();

            // use \d \d to remove the last * from stream
            cout << "\b \b";
        }
        else
        {
            
            cout << '*';

           
            str += ch;
        }
    }
    cout << endl;
    return str;

}