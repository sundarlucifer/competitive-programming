#include <iostream>
using namespace std;

bool checkPermutation(string str1, string str2){
	if(str1.length() != str2.length())
		return false;

	const int NUM_ALPHA = 26; // number of alphabets
	int memo[NUM_ALPHA] = {0};

	for(int i=0; i<str1.length(); i++){
		memo[str1[i]-'a']++;
		memo[str2[i]-'a']--;
	}

	for(int i=0; i<NUM_ALPHA; i++)
		if(memo[i] != 0)
			return false;	

	return true;
}

int main(){
	
	string str1 = "aabbcde";
	string str2 = "bacbdae";

	if(checkPermutation(str1, str2))
		cout << "yes" << endl;
	else
		cout << "no" << endl;

	return 0;
}
