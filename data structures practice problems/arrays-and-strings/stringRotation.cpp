#include <iostream>
using namespace std;

bool isStringRotated(string str1, string str2){
	if(str1.length() != str2.length())
		return false;
	
	str1 = str1 + str1;
	
	if(str1.find(str2) != string::npos)
		return true;
	return false;
}

int main(){

	string str1 = "abcdef";
	string str2 = "cdefab";
	
	if(isStringRotated(str1, str2))
		cout << "Rotated" << endl;
	else
		cout << "Not rotated" << endl;

	return 0;
}
