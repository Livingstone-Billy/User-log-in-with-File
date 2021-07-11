#include"User.h"
#include<fstream>
#include<iostream>
#include<vector>
#include <iterator>
#include<string>
#include<algorithm>
#include <type_traits>

using namespace std;

User::User()
{
    password = " ";
    userName = " ";
}
User:: ~User()
{

}
User::User(string &username,string &password):userName(username),password(password){}
//accessor
string User::getUserName() const
{
    return userName;
}
string User::getPassword()const
{
    return password;
}
//mutator
void User::setUsername(string &name)
{
    this->userName = name;
}
void User::setPassword(string &password)
{
    this->password = password;
}
struct details
{
    string name;
    string password;
};
//Sign Up
void User::SignUp(User &user)
{
    details data;
    string username;
    cout<<"Enter your username: ";
    cin>>username;
    cout<<"Enter your password: ";
    string password;
    cin>>password;
    while(password.size() < 6)
    {
        cout<<"Password must be more than 6 characters long\nEnter password:";
        cin>>password;
    }
    cout<<"Confirm password: ";
    string conf_pass;
    cin>>conf_pass;
    while(conf_pass != password)
    {
        cout<<"[Password mismatch!] Enter correct password: ";
        cin>>conf_pass;
    }
    if(password == conf_pass)
    {
        cout<<"You've signed up successfully "<<username<<endl;
    }
    user.setPassword(password);
    user.setUsername(username);
    fstream inout;
    inout.open("data.txt",ios::out|ios::app);
    if(inout.fail())
    {
        cout<<"System busy try again later: "<<endl;
    }
    inout<<username+password<<"\n";
    inout.close();
    data.name = username;
    data.password = password;
}
bool isPassword(vector<string>matrix,string key)
{
    bool isFound = false;
    int low = 0;
    int high = matrix.size() -1;
    while(high >= low)
    {
        int mid = (low + high)/2;
        if(key < matrix[mid])
        {
            high = mid -1;
        }
        else if(key == matrix[mid])
        {
            isFound = true;
        }
        else
        {
            low = mid + 1;
        }
    }
    return isFound;
}
//Log in
void User::LogIn(const User & user)
{
    details get;
    bool isUser = false;
    string systemusername = get.name;
    string systemPassword = get.password;
    string userName;
    cout<<"Enter your username: ";
    cin>>userName;
    cout<<"Enter password: ";
    string userPassword;
    cin>>userPassword;
    fstream inout;
    inout.open("data.txt",ios::in);
    string pass_username;
    static vector<string>matrix;
    while(!inout.eof())
    {
        inout>>pass_username;
        // cout<<name1<<" "<<space<<" "<<pass<<endl;
        matrix.push_back(pass_username);
    }
    string key = userName+userPassword;
    if(isPassword(matrix,key))
    {
        cout<<"Log in successful"<<endl;
    }
    else
    {
        cout<<"Log In successful"<<endl;
    }
    inout.close();
}