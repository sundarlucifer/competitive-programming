#include <iostream>
#include <string>
using namespace std;

void rightShift(char* str, int startIndex, int endIndex, int numberOfShifts){
    for(int i=endIndex-1; i>=startIndex; i--)
        str[i+numberOfShifts] = str[i];
}

void stringURLify(char* url, int currentLength, int trueLength){
    for(int i=0; i<trueLength; i++){
        cout << url[i] << endl;
        if(url[i] == ' '){
            rightShift(url, i, currentLength, 2);
            url[i] = '%';
            url[i+1] = '2';
            url[i+2] = '0';
            i+=2;
            currentLength += 2;
        }
    }
}

int main(){
    
    int trueLength;
    cout << "Enter true length of the url : ";
    cin >> trueLength;
    
    string inputString;
    char url[trueLength];
    cout << "Enter a string to URLify : ";
    
    cin.ignore(); // to skip the /n from int input
    int i;
    getline(cin, inputString);
    int currentLength = inputString.length();
    for(i=0; i<currentLength; i++)
        url[i] = inputString[i];
    for( ; i<trueLength; i++)
        url[i] = '?';
    
    stringURLify(url, currentLength, trueLength);
    
    cout << "URL (? - extra space): " << url << endl;
    
    return 0;
}
