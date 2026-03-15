#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
    Function: checkUserExists
    Purpose:  Checks if the username already exists in the file
*/
bool checkUserExists(string username)
{
    ifstream file("users.txt");     // Open file for reading
    string storedUser, storedPass;

    // Read username and password from file
    while (file >> storedUser >> storedPass)
    {
        if (storedUser == username)
        {
            return true;   // Username already exists
        }
    }

    return false; // Username not found
}


/*
    Function: registerUser
    Purpose:  Takes username and password and saves them in file
*/
void registerUser()
{
    string username, password;

    cout << "\n----- USER REGISTRATION -----\n";

    cout << "Enter username: ";
    cin >> username;

    // Check if username already exists
    if (checkUserExists(username))
    {
        cout << "Error: Username already exists!\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    // Open file in append mode to store new user
    ofstream file("users.txt", ios::app);

    // Save username and password
    file << username << " " << password << endl;

    cout << "Registration Successful!\n";
}


/*
    Function: loginUser
    Purpose:  Verifies username and password from file
*/
void loginUser()
{
    string username, password;
    string storedUser, storedPass;
    bool loginSuccess = false;

    cout << "\n----- USER LOGIN -----\n";

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");

    // Read stored credentials
    while (file >> storedUser >> storedPass)
    {
        if (storedUser == username && storedPass == password)
        {
            loginSuccess = true;
            break;
        }
    }

    if (loginSuccess)
        cout << "Login Successful! Welcome " << username << endl;
    else
        cout << "Error: Invalid Username or Password\n";
}


/*
    Main Function
    Displays menu for registration and login
*/
int main()
{
    int choice;

    do
    {
        cout << "\n===== LOGIN SYSTEM =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 3);

    return 0;
}