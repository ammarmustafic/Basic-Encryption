#include <iostream>
#include <fstream>
#include <windows.h>
#include <sstream>
#include <cstring>
#include <functional>
#include <bitset>

using namespace std;

bool isUsernameExists(const string& filename, const string& username)
{
    ifstream file(filename);
    string line;
    while (getline(file, line))
    {
        if (line.find("Username: " + username) != string::npos)
        {
            return true; 
        }
    }
    return false;
}

void appendFile(const string& filename, const string& content)
{
    ofstream file(filename, ios::app);
    if (file)
    {
        file << endl << "----------" << endl << content;
        cout << "Content appended to file: " << filename << endl;
    }
    else
    {
        cerr << "Failed to open file: " << filename << endl;
    }
}

string hashString(const string& input)
{
   hash<string> hasher;
    size_t hashValue = hasher(input);
    stringstream ss;
    ss << hex << hashValue; 
    return ss.str();
}

string toBinary(const string& input)
{
    string binary;
    for (char c : input)
    {
        binary += bitset<8>(c).to_string();
    }
    return binary;
}

int main()
{
    string inputFile = "credentials.txt";

    string username;
    string password;

    again:
    cout << "Enter username: ";
    cin >> username;

    if (isUsernameExists(inputFile, username))
    {
        cout << "Username already exists. Try again." << endl;
        Sleep(500);
        system("CLS");
        goto again;
    }

    cout << "Enter password: ";
    cin >> password;

    string plaintextContent = "Username: " + username + "\nPassword: " + password;

    string hashedUsername = hashString(username);
    string hashedPassword = hashString(password);

    string hashedContent = "Hashed:\nUsername: " + hashedUsername + "\nPassword: " + hashedPassword;

    string binaryContent = "Binary:\nUsername: " + toBinary(username) + "\nPassword: " + toBinary(password);

    appendFile(inputFile, plaintextContent + "\n\n" + hashedContent + "\n\n" + binaryContent);

    return 0;
}
