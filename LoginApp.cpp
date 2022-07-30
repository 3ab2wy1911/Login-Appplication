// FCI – Programming 1 – 2022 - Assignment 4
// Program Name: login application
// Last Modification Date: 20/5/2022
// Youssef Ahmed
// Mohamed Ahmed
// Yara Salah


#include "login-header.h"
#include "login-Func.cpp"


int main()
{
    int ans;
    while(ans!=4)
    {
        string num, num2, mail, name, password, password2, encr;
        string o_pass="";
        string n_pass="";
        string id_log="";
        string pass_log="";
        ofstream profile;
        ofstream file;
        cout<<"*************************\n\n";
        cout<<"              Welcome to login page                        \n\n";
        cout<<"*******        MENU        ***********\n\n";
        cout<<"1.REGISTER"<<endl;
        cout<<"2.LOGIN"<<endl;
        cout<<"3.Change password"<<endl;
        cout<<"4.Exit"<<endl;
        cout<<"\nEnter your choice :\n";
        cin>>ans;
        if(ans==1)
        {
            username(name);
            phone_number(num);
            id(num2);
            email(mail);
            check_password(password);
            matching_password(password, password2);
            encreption (password,encr);
            fill_profile(profile, num, num2, name, mail ,encr);
        }
        if(ans==2)
        {
            get_Pass_id(id_log, pass_log);
        }
        if (ans==3)
        {
            changePassword(id_log,pass_log,n_pass);
        }
    }
    return 0;
}
