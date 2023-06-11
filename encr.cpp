#include <iostream>
#include <string>

using namespace std;

string encrypt(const string& text, int rule) {
    string encryptedText = "";

    for (char c : text) {
        int asciiValue = static_cast<int>(c);
        int encryptedValue = (asciiValue + rule) % 256;
        encryptedText += static_cast<char>(encryptedValue);
    }

    return encryptedText;
}

int main() {
    string text;
    int rule;

    cout << "Enter the text to encrypt: ";
    getline(cin, text);

    cout << "Enter the encryption rule: ";
    cin >> rule;
    
    string encryptedText = encrypt(text, rule);
    cout << "Encrypted text: " << encryptedText << endl;

    return 0;
}
