#include <iostream>
#include <string>

using namespace std;

string encrypt(string text, int shift) {
    string ciphertext = "";
    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        if (isalpha(c) || isdigit(c) || ispunct(c)) {
            int ascii = int(c);
            ascii = (ascii + shift) % 127;
            if (ascii < 32) {
                ascii += 32;
            }
            ciphertext += char(ascii);
        }
        else {
            ciphertext += c;
        }
    }
    return ciphertext;
}


string decrypt(string ciphertext, int shift) {
    string text = "";
    for (int i = 0; i < ciphertext.length(); i++) {
        char c = ciphertext[i];
        if (isalpha(c) || isdigit(c) || ispunct(c)) {
            int ascii = int(c);
            ascii = (ascii - shift + 127) % 127;
            if (ascii < 32) {
                ascii += 32;
            }
            text += char(ascii);
        }
        else {
            text += c;
        }
    }
    return text;
}


int main() {
    string text, ciphertext;
    int shift;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter shift: ";
    cin >> shift;
    ciphertext = encrypt(text, shift);
    cout << "Ciphertext: " << ciphertext << endl;
    cout << "Decrypted text: " << decrypt(ciphertext, shift) << endl;
    return 0;
}