//Purpose : Find longest palindrome substring given a string
//Date : April 13, 2020

//Libraries
#include <iostream>
#include <string>

//Namespaces
using namespace std;

//Functions
string getString() {
	string temp;
	cout << "String to parse : ";
	cin >> temp;

	return temp;
}

string findPalindromeInSub(int startIndex, int endIndex, char startChar, string MyString, int &tempEnd) {
	//find last match
	for (int i = endIndex; i > startIndex; i--) {
		if (MyString[i] == startChar) {
			endIndex = i;
			break;
		}
		else {
			endIndex = -1;
		}
	}

	//if no match
	if (endIndex == -1) {
		return "";
	}
	//is at least one match
	else
	{
		//if only two chars
		if ((endIndex - startIndex) / 2 == 0)
		{
			//if those two are equal
			if (MyString[endIndex] == MyString[startIndex]) {
				tempEnd = endIndex;
				return MyString.substr(startIndex, (endIndex - startIndex) + 1);
			}
			else return "";
		}
		//more than two chars
		else
		{
			//Loop through indeces
			for (int i = 1; i <= (endIndex - startIndex) / 2; i++) {
				//if match
				if (MyString[startIndex + i] == MyString[endIndex - i]) {
					//if last match
					if (i == ((endIndex - startIndex) / 2)) {
						//Found palindrome
						tempEnd = endIndex;
						return MyString.substr(startIndex, (endIndex - startIndex) + 1);
					}
					//not last match
					continue;
				}
				//non-match
				else
				{
					//if last possible comparison
					if (i == ((endIndex - startIndex) / 2) + 1) {
						return "";
					}
					//further possible comparisons
					else {
						//recursive factor
						return findPalindromeInSub(startIndex, endIndex - 1, startChar, MyString, tempEnd);
					}
				}
			}
		}
	}
	
}


string findLongestPalindrome(string myString) {
	//vars
	int startIndex, endIndex, tempEnd;
	char start;

	string longestPalindrome = "";
	string temp;//This is the return value and is compared to the longest string

	//First iteration
	startIndex = 0;
	start = myString[0];
	endIndex = myString.length()-1;

	//keep looping as long as another palindrome is possible
	while (startIndex < myString.length()) {//Notice I use < not <= because a palindrome needs at least two characters... < ensures we will have at least 2

		//find a palindrome given start and stop index
		temp = findPalindromeInSub(startIndex, endIndex, start, myString, tempEnd);

		//no valid palindrome --> move start right one
		if (temp == "") {
			startIndex = startIndex + 1;
			start = myString[startIndex];
		}
		//found a valid palindrome
		else {
			//compare to longest current palindrome
			if (temp.length() > longestPalindrome.length()) {
				longestPalindrome = temp;
			}
			//move start to one after the current palindromes stop
			startIndex = tempEnd + 1;
			start = myString[startIndex];
		}
	}

	return longestPalindrome;
}




//Driver
int main()
{
	while (1) {
		//Get String from User
		string String = getString();

		//FindPalindrome
		string answer = findLongestPalindrome(String);

		cout << "Longest Palindrome in " << String << " is : " << answer << endl;
	}

	return 0;
}