#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <regex>
#include<conio.h>
#include "loginFunctions.h"

using namespace std;
string pass;
void profile ::registing(){
   
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

void profile ::saveData(){
    ofstream reg("profile_data.txt", ios ::app);
    reg << "name: " << name << endl
        << "Id: " << id << endl
        << "Password: " << pass << endl
        << "email: " << email << endl
        << "phon: " << phon << "\n\n";
    reg.close();
}
int profile::encrypt(int letter){
    return letter + 3;
}

bool profile :: check_id(string str){
    regex check_id("20(19|20|21)[0-9]{4}");
    return regex_match(str, check_id);
}
bool profile ::check_name(string str){
    regex check_name("[A-Z]+[a-z]*");
    return regex_match(str, check_name);
}
bool profile ::check_mail(string str){
    regex check_mail("^[a-zA-Z0-9_]+@(hotmail|yahoo|gmail)+.(com|edu|net)$");
    return regex_match(str, check_mail);
}

void profile:: search_mail(string a)
{
    int x;
    fstream reg;
    reg.open("profile_data.txt", ios ::in);
   
    while (!reg.eof()){
        while (getline(reg, a)){
            if (a.find(email, 1) != string ::npos){
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
        if (x == 0){
            cout << "valid email" << endl;
            break;
        }
    }

    reg.close();
}

bool profile ::check_phon(string str){
    regex check_phon("01[0125][0-9]{8}");
    return regex_match(str, check_phon);
}
bool profile ::strong_pass(string& str){
    regex pass_format("^(?=.*?[A-Z])(?=.*?[a-z])(?=.*?[0-9])(?=.*?[#?!@$%^&*-]).{8,}$");              // should contain at least one upper case  (?=.*?[A-Z])
      return regex_match(str,pass_format);                                                           // should contain at least one lower case  (?=.*?[a-z])
       }                                                                                            // should contain at least one digit       (?=.*?[0-9])                                                                                                         // should contain at least one Special character      (?=.*?[#?!@$%^&*-])   
                                                                                                  // Must be at least 8 characters in length      {8,}
bool profile :: is_valid_repeated(string& str){
bool check = true;
char ch;
string password2;
cout<<"comfirm your password: \n";
 char c;
for(int i=0;i<1000;i++)
	{
	 c=getch();
	 if(c=='\r'){
         break;
         }
         else if(c=='\b'){
             cout<<"\b \b";
         }
         else{
	 cout<<"*";
	 password2+=c;}
	}
    cout<<endl;

while (true)
{  
    if(password2!=str){
        check=false;
        cout<<"your should match your password\n";
        cout<<"rewrite your password again: \n";
         char c;
 for(int i=0;i<1000;i++)
	{
	 c=getch();
	 if(c=='\r'){
         break;
         }
         else if(c=='\b'){
             cout<<"\b \b";
         } else{
	cout<<"*";
	 password2+=c;}
	}
    cout<<endl;
}
    else{
        cout<<"your password saved";
        break;
        } 
    }
    return 0;
}  
bool profile ::  is_valid_password(string& str){
    bool check=true;
char c;
        //  for loop to input the password without being  seen
for(int i=0;i<1000;i++)
	{
	   c=getch();                    
	 if(c=='\r'){ 
         break;}                   
         else if(c=='\b'){
            cout<<"\b \b";     
 
         }else{
	 cout<<"*";
	 password+=c;}
	}
cout<<endl;
while (true)
{  
if(strong_pass(password)){
    cout<<"strong password\n";
    break;
}
else{
    cout<<"week password\n";
    check=false;
    cout<<"Enter your password again: \n";
     char c;
for(int i=0;i<1000;i++)
	{
	 c=getch();
	 if(c=='\r' ){
         break;}
    else if (c=='\b'){
             cout<<"\b \b";
         
         }else{
	 cout<<"*";
	 password+=c;}
	}
    cout<<endl;
    } 
}
is_valid_repeated(password);
return 0;
}
