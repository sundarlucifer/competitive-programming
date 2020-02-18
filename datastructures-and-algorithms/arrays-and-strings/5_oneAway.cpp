#include <iostream>
using namespace std;

bool isOneAway(string str1, string str2){
    int len1 = str1.length();
    int len2 = str2.length();
    if(len1==len2){
        if(str1 == str2) // zero edit
            return true;
        int diffCount = 0;
        for(int i=0; i<len1; i++)
            if(str1[i] != str2[i])
                diffCount++;
        return diffCount==1 ? true : false;
    }else if(abs(len1-len2) == 1){
        string smallStr = (len1<len2) ? str1 : str2;
        string bigStr = (len1>len2) ? str1 : str2;
        
        bool changed = 0;
        for(int i=0; i<smallStr.length(); i++){
            if(smallStr[i] != bigStr[i+changed]){
                if(changed)
                    return false;
                changed = 1;
                i--;
            }
        }
        return true;
    }else{
        return false;
    }
}

int main(){
    
    string str1 = "abcdefg";
    string str2 = "abdefg";
    string str3 = "abdxfg";
    
    cout << (isOneAway(str1, str2) ? "one away" : "not one away") << endl;
    cout << (isOneAway(str2, str3) ? "one away" : "not one away") << endl;
    cout << (isOneAway(str3, str1) ? "one away" : "not one away") << endl;
    
    return 0;
}
