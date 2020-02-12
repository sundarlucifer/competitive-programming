// KMP String Searching algorithm
// refer : https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
# include <iostream>
using namespace std;

void preprocess(char* ptrn, int* lps){
    lps[0] = 0;
    int len = 0;
    int i = 1;
    while(i < strlen(ptrn)){
        if(ptrn[i]==ptrn[len]){
            len++;
            lps[i]=len;
            i++;
        }else{
            len = lps[len-1];
            if(len==0){
                lps[i]=0;
                i++;
            }
        }
    }
}

void kmpSearch(char* str, char* ptrn){
    int lps[strlen(ptrn)];
    preprocess(ptrn, lps);
    cout << "Longest proper prifix come suffix : ";
    for(int i=0;i<strlen(ptrn);i++)
        cout << lps[i];
    cout<<endl;
    int i=0;
    int j=0;
    while(i<strlen(str)){
        if(str[i]==ptrn[j]){
            i++;
            j++;
        }
        if(j==strlen(ptrn)){
            cout << "Ocuurance found at index "<<i-j<<endl;
            j=0;
        }else if(i<strlen(str) && str[i]!=ptrn[j]){
            if(j!=0)
                j = lps[j-1];
            else
                i++;
        }
    }
}

int main(){
    char* str = "AABCAABC";
    char* ptrn = "BAB";
    kmpSearch(str, ptrn);
    return 0;
}