#include <bits\stdc++.h>
using namespace std;

void login();
void registration();
void forgot();

int main()
{
    int c;
    cout << "\t\t\t___________________________________________________________________________________\n\n\n";
    cout << "\t\t\t                       Welcome to the Login Page                                   \n\n\n";
    cout << "\t\t________________________          Menu           ____________________________________\n\n";
    cout << "                                                                                         \n\n";
    cout << "\t| Press 1 for login                  |" << endl;
    cout << "\t| Press 2 to Register                |" << endl;
    cout << "\t| Press 3 if you forgot Password     |" << endl;
    cout << "\t| Press 4 to exit                    |" << endl;
    cout << "\n\t\t\t Please enter your choice: ";
    cin >> c;
    cout << endl;

    switch (c)
    {
    case 1:
        login();
        break;

    case 2:
        registration();
        break;

    case 3:
        forgot();
        break;

    case 4:
        cout << "\t\t\t ThankYou!  \n\n";
        break;

    default:
        system("CLS");
        cout << "\t\t\t Please select from options given above \n"
             << endl;
        main();
    }

    return 0;
}
void login()
{
    int count = 0;
    string userId, password, id, pass;
    system("CLS");
    cout << "\t\t\t Please Enter the Username and Password: " << endl;
    cout << "\t\t\t USERNAME ";
    cin >> userId;
    cout << "\t\t\t Password ";
    cin >> password;

    ifstream input("records.txt");
    while (input >> id >> pass)
    {
        if (id == userId && pass == password)
        {
            count = 1;
            system("CLS");
        }
    }
    input.close();
    if (count == 1)
    {
        cout << userId << "\n Your Login is Successful\n";
        main();
    }
    else
    {
        cout << "\n Your Login is Unsuccessful\n";
        main();
    }
}

void registration()
{
    string ruserId, rpassword;
    system("CLS");
    cout << "\t\t\t Enter the username: ";
    cin >> ruserId;
    cout << "\t\t\t Enter the password: ";
    cin >> rpassword;

    ofstream f1("records.txt", ios::app);
    f1 << ruserId <<"   "<< rpassword << endl;
    system("CLS");
    cout << "\n\t\t\t Registration is Successfull \n";
    main();
}
void forgot()
{
    int options;
    system("CLS");
    cout << "\t\t\t You Forgot the password? No worries\n";
    cout << "Press 1 to search your id by username" << endl;
    cout << "Press 2 to go to main menu";
    cout << "Enter Your Choice: ";
    cin >> options;
    switch (options)
    {
    case 1:
    {
        int count = 0;
        string suserId, spass, sId;
        cout << "\n\t\t Enter the username which you remembered: ";
        cin >> suserId;
        ifstream f2("records.txt");
        while (f2 >> sId >> spass)
        {
            if (sId == suserId)
            {
                count = 1;
            }
        }
        f2.close();
        if (count == 1)
        {
            cout << "\n\n Your account is found! \n";
            cout << "\n\n Your Password is: " << spass;
            main();
        }
        else
        {
            cout << "\n\t Sorry! Your account is not found\n ";
            main();
        }
        break;
    }

    case 2:
    {
        main();
        break;
    }
    default:
        cout << "\t\t\t Wrong Choice! Please try again" << endl;
        forgot();
    }
}