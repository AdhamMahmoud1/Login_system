#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <regex>
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
};
string pass;
int main()
{
    profile p;
    int choice;
    cout << "Welcome dear user!\nWhat do you want?\n1_Login   2_Registing   3_Change PassWord" << endl;
    cin >> choice;

    p.registing();

    return 0;
}
void profile ::registing(){
   
    cout << "Please Enter your name: ";
    cin >> name;
    while (!check_name(name)){
        cout << "invalid name!\nPlease try again: ";
        cin >> name;
    }
    cout << "Please Enter the password: ";
    cin >> password;
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

bool profile ::check_phon(string str){
    regex check_phon("01[0125][0-9]{8}");
    return regex_match(str, check_phon);
}
