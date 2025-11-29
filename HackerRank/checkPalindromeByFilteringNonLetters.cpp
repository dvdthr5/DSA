#include <bits/stdc++.h>

using namespace std;



/*
 * Complete the 'isAlphabeticPalindrome' function below.
 *
 * The function is expected to return a BOOLEAN.
 * The function accepts STRING code as parameter.
 */

bool isAlphabeticPalindrome(string code) {
    const char* forwards = code.c_str();
    const char* backwards = code.c_str() + code.length() -1 ;
    
    while (forwards < backwards){
        while (!isalpha(*forwards) && forwards < backwards){
            forwards++;
        } 
        while (!isalpha(*backwards) && forwards < backwards){
            backwards--;
        }
        if ((tolower(static_cast<unsigned char>(*forwards)) != tolower(static_cast<unsigned char>(*backwards))) && forwards != backwards){
            return false;
        }
        else{
            forwards++;
            backwards--;
        }
        
    }    
    return true;
}

int main()
{
    string code;
    getline(cin, code);

    bool result = isAlphabeticPalindrome(code);

    cout << result << "\n";

    return 0;
}

