#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include<conio.h>
using namespace std;


void phone_number(string& user_phonenumber);
void id(string& user_ID);
void username(string& userName);
void email(string& user_email);
void fill_profile(ofstream& file,string& user_phonenumber,string& user_ID, string& userName, string& user_email , string& encr_pass);
void check_password(string& pass);
bool strong_password(string& password);
void matching_password(string& pass1, string& pass2);
void hide_password(string& pass);
void encreption (string&pass,string&encr_pass);
void get_Pass_id(string& obtainedID, string& obtainedPass);
void changePassword(string& obtainedID,string& obtainedPass,string& n_pass);




#endif // HEADER_H_INCLUDED