#include <iostream>
using namespace std;

char toAscii(int i){
    return i + '0';
}

string compressString(string str){
    string compressedString = "";
    int i = 0;
    int strLength = str.length();
    int charCount = 0;
    char currentChar = str[0];
    compressedString += currentChar;
    while(i<strLength){
        if(str[i] == currentChar){
            charCount++;
            if(charCount>9){
                compressedString += '1';
                charCount = 0;
            }
        }else{
            compressedString += toAscii(charCount);
            currentChar = str[i];
            compressedString += currentChar;
            charCount = 1;
        }
        i++;
    }
    compressedString += toAscii(charCount);
    if(str.length() <= compressedString.length())
        return str;
    else
        return compressedString;
}

int main(){
    
    string str = "aabccccccccccaaa";
    
    str = compressString(str);
    
    cout << str << endl;
    
    return 0;
}
