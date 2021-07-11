#ifndef USER_H
#define USER_H
#include<string>
#include<vector>
using namespace std;
class User
{
    public:
        User();
        virtual ~User();
        User(string&, string &);
        string getUserName() const;
        string getPassword() const;

        //mutator
        void setUsername(string &name);
        void setPassword(string &password);
        //log in
        void LogIn(const User & user);
        //Sign up
        void SignUp(User & user);
        //Change password and username;
        void changeDetails(const User & user);
        //Log out 
        void LogOut(const User & user);
        struct details {string name;string password;};
    private:
        string userName;
        string password;
};

#endif