#include <iostream>
using namespace std;

bool isUnique(string str){
    sort(str.begin(), str.end());
    
    for(int i=0; i<str.length()-1; i++)
        if(str[i] == str[i+1])
            return false;
    
    return true;
}

int main(){
    string str = "aabcdeef";
    
    if(isUnique(str))
        cout << "Unique characters" << endl;
    else
        cout << "Non-unique characters" << endl;
    
    return 0;
}
