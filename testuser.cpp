#include "User.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    User *init,user;
    init = &user;
    cout<<"Press 1 to Log in\nPress 2 to Sign up\nPress 3 to change password\nPress 4 to Logout: \n";
    int answer;
    cin >> answer;
    switch(answer)
    {
        case 1: init->LogIn(user);
        break;
        case 2: init->SignUp(user);break;
        // case 3: init->changeDetails(user);break;
        // case 4: init->LogOut(user);break;
    }
    return 0;
}