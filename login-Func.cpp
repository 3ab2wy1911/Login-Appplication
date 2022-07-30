#include "login-header.h"

//_____________________________________________________
void phone_number(string& user_phonenumber)
{

    cout<<"Enter your phone number: ";
    cin>>user_phonenumber;
    regex valid_phonenumber("(01)[0125][0-9]{8}");

    while (!regex_match(user_phonenumber, valid_phonenumber))
    {
        cout<<"Enter your phone number correctly,please: ";
        cin>>user_phonenumber;
    }
    cout<<" valid phone number \n";
}
//_____________________________________________________
void id(string& user_ID)
{

    cout<<"Enter your ID: ";
    cin>>user_ID;
    regex valid_ID("(20)[0-2][0-9]{5}");

    while(!regex_match(user_ID, valid_ID))
    {
        cout<<"Enter your ID correctly,please: ";
        cin>>user_ID;
    }
    cout<<" valid ID \n";
}
//_____________________________________________________
void username(string& userName)
{
    cout<<"Enter your username: ";
    cin>>userName;
    regex valid_username("([a-zA-Z])+[\\_]?([a-zA-Z])+") ;

    while(!regex_match(userName,valid_username))
    {
        cout<<"Enter your username correctly,please: "<<endl;
        cin>>userName;

    }
    cout<<" valid username \n";
}
//_____________________________________________________
void email(string& user_email)
{

    cout<<"Enter your e-mail: ";
    cin>>user_email;
    regex valid_email("^[a-zA-Z0-9+_.]+@[a-zA-Z.-]+[.][c][o][m]$") ;

    while(!regex_match(user_email,valid_email))
    {
        cout<<"Enter your e-mail correctly,please: "<<endl;
        cin>>user_email;

    }
    cout<<" valid e_mail \n";
}
//_____________________________________________________
void fill_profile(ofstream& file,string& user_phonenumber,string& user_ID, string& userName, string& user_email , string& encr_pass)
{
    file.open("information.txt",ios:: app);

    if (file.is_open())
    {
    file<< endl << user_ID <<endl;
    file<< user_phonenumber <<endl;
    file<< userName <<endl;
    file<<  user_email <<endl;
    file << encr_pass << endl;
    }

    file.close();
}
//_____________________________________________________
bool strong_password(string& password) // function that check if input from user is matching with this form.
{
    regex valid_password("^(?=.*?[A-Z])(?=.*?[a-z])(?=.*?[0-9])(?=.*?[#?!@$%^&*-]).{8,15}$");
    return regex_match(password, valid_password);

}
//_____________________________________________________
void check_password(string& pass)
{
    f1:
    cout<<"Password must contain: " << endl;
    cout<<"1-At least 8 characters and max of 15 characters " << endl;
    cout<<"2-A mixture of both uppercase and lowercase letters " << endl;
    cout<<"3-A mixture of letters and numbers "<< endl;
    cout<<"4-At least one special character, e.g., ! @ # ? ] \n==>"<< endl;

    hide_password(pass);

    if(strong_password(pass))
    {
        cout << "\n This password is strong \n " << endl;
    }
    else
    {
        cout << "\n This is weak password try again\n "<< endl;
        goto f1;
    }
}
//_____________________________________________________
void matching_password(string& pass1, string& pass2)
{
    f2:
    cout << "Please repet password " << endl;
    hide_password(pass2);
    if (pass1 == pass2)
    {
        cout << " \n Matching password successfully :) " << endl;
    }
    else
    {
        cout << "\n You entered wrong passorword Please try again " << endl;
        goto f2;
    }
}
//_____________________________________________________
void hide_password(string& pass)
{
    int x;
    cout << "Enter the password " << endl;
    while ((x = getch()) != 13) 
    {
        if (x == 8) 
        {
            if (pass.size() > 0) 
            {
                pass.pop_back();
                cout << "\b \b";
            }
        }
        else
        {
            pass.push_back(x);
            cout << "*";
        }
    }
}
//_____________________________________________________
void encreption (string&pass,string&encr_pass)
{
    encr_pass=pass;
   for(int i=0;i<pass.length();i++){
        if (int (pass[i])<=90){
                encr_pass[i]=(pass[i]-65+1)%26+65;
        }
        else{
                encr_pass[i]=(pass[i]-97+1)%26+97;
        }
     }
}
//_____________________________________________________
void get_Pass_id(string &obtainedID, string &obtainedPass)
{
    ifstream file;
    int ntries=1;
    bool check;
    f3:
    obtainedID="";
    obtainedPass="";
    string encr_Pass="";
    string name;
    vector<string>text;
    file.open("information.txt");
    cout<<"Enter your id \n";
    cin>>obtainedID;
    char line[100];

    hide_password(obtainedPass);
    encreption(obtainedPass,encr_Pass);

    while (!file.eof())
    {
        file.getline(line, 100, '\n');
        text.push_back(string(line));
        }
    file.close();
    for(int i=0;i<text.size();i++){
            if(obtainedID==string(text[i])&&encr_Pass==string(text[i+4])){
                name=string(text[i+2]);
                check=true;
                break;
            }
            else{
                check=false;
                }
    }
    if(check){
            cout<<" Successful login, welcome "<<name<<endl;
    }
    else{
        if (ntries<3){
            cout<<"Failed login. Try again. \n";
            cout << "\nYou have " << 3 - (++ntries)+1 << " trials left\n";
            goto f3;

        }
        else {
            cout<<"Failed login.\n";
            cout << "\nYou have 0 trials left\n";
            cout<<"Your denied from accessing our system \n";
        }
    }
}
//_____________________________________________________
void changePassword(string& obtainedID,string& obtainedPass,string& n_pass)
{
    ifstream file;
    ofstream target;
    int ntries=1;
    bool check;
    int loc;
    cout<<"Please login to your existing profile first : \n ";
    f3:
    obtainedID="";
    obtainedPass="";
    string encr_Pass="";
    string encr_Pass2="";
    string pass2 ="";
    string name;
    vector<string>text;
    file.open("information.txt");
    cout<<"Enter your id : \n";
    cin>>obtainedID;
    char line[100];

    hide_password(obtainedPass);
    encreption(obtainedPass,encr_Pass);

    while (!file.eof())
    {
        file.getline(line, 100, '\n');
        text.push_back(string(line));
        }
    file.close();
    for(int i=0;i<text.size();i++){
            if(obtainedID==string(text[i])&&encr_Pass==string(text[i+4])){
                name=string(text[i+2]);
                loc=(i+4);
                check=true;
                break;
            }
            else{
                check=false;
                }
    }
    if(check){
            cout<<" Successful login, welcome "<<name<<endl;
    }
    else{
        if (ntries<3){
            cout<<"Failed login. Try again. \n";
            cout << "\nYou have " << 3 - (++ntries)+1 << " trials left\n";
            goto f3;

        }
        else {
            cout<<"Failed login.\n";
            cout << "\nYou have 0 trials left\n";
            cout<<"Your denied from accessing our system \n";
        }
    }
    if(check){
    cout<<"Enter your new password : \n";
    check_password(n_pass);
    matching_password(n_pass,pass2);
    encreption(n_pass,encr_Pass2);
    for(int i=0;i<text.size();i++){
            text[loc]=encr_Pass2;
    }

    target.open("information.txt");
    for(int i=0 ;i< text.size();i++ ){
        target<<text[i];
        target<<'\n';
    }
    cout<<"Password has changed successfully";
    target.close();
    }
}
