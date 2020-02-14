// checks if a given string is a permutation of a palindrome
#include <iostream>
using namespace std;

bool isPermutationOfPalindrome(string str){
	const int NUM_ALPHA = 26; // number of alphabets
	int memo[NUM_ALPHA] = {0};

	for(int i=0; i<str.length(); i++)
		memo[str[i]-'a']++;	

	int oddCount = 0;
	for(int i=0; i<NUM_ALPHA; i++){
		if(memo[i]%2 == 1)
			oddCount++;
	}
	
	if(oddCount <= 1)
		return true;

	return false;
}

int main(){
	
	string str1 = "velle"; // permutation of level
	string str2 = "abcad"; // non palindrome
	string yesOrNo;        // to print result
	
	yesOrNo = isPermutationOfPalindrome(str1) ? "" : "not ";
	cout << str1 << " is " << yesOrNo << "a permutation of palindrome" << endl;

	yesOrNo = isPermutationOfPalindrome(str2) ? "" : "not ";
        cout << str2 << " is " << yesOrNo << "a permutation of palindrome" << endl;

	return 0;
}
