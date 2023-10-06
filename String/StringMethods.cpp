/* C++ program containing examples for usage of various C++ string functions */
#include <iostream>
using namespace std;

int main() 
{
  string str1 = "Good ";
  string str2(" Day");
  string str3 = "Beautiful";
  
  //append
  string str4 = str3.append(str2);
  cout << str4 << endl;
  
  // substr
  string subString = str4.substr(10, 3);
  cout << subString << endl;
  
  // replace
  string replacedSubString = str4.replace(10, 5, "Life");
  cout << replacedSubString << endl;
  
  // find
  string searchString = "auti";
  cout << "The search string starts from " << replacedSubString.find(searchString, 0) << endl;
  
  // at
  cout << "The character at index 2 of replacedSubString is " << replacedSubString.at(2) << endl;
  
  // insert
  string insertString = replacedSubString.insert(10, str1);
  cout << "replacedSubString after inserting str1 : "<< insertString << endl;
  
  //compare
  if(insertString.compare(replacedSubString.insert(10, str1)) == 0) 
  {
      cout << " Equal Strings!!!" << endl ;
      
  }
  else
  {
      cout << "Compared Strings unequal!!!" << endl;
      }
  
  // string iterator, string.begin() and string.end() methods. 
  string::iterator itString = insertString.begin();
  cout << "First letter of insertString : " << *itString << endl;
  itString++;
  cout << "Second letter of insertString : " << *itString << endl;
  
  itString = insertString.end() - 1;
  cout << "Last character of insertString : " << *itString << endl;
  
  // clear and erase methods
  insertString.clear();
  cout << "After clearing insertString, value : " << insertString << endl;
  
  cout << "After erasing Beautiful Good from replacedSubString, the new string : " << replacedSubString.erase(0, 15) << endl;
  
  // empty
  cout << "String str1 is empty - " <<  boolalpha << str1.empty() << endl;
}

/* 
OUTPUT
-----------------------------------
Beautiful Day
Day
Beautiful Life
The search string starts from 2
The character at index 2 of replacedSubString is a
replacedSubString after inserting str1 : Beautiful Good Life
Compared Strings unequal!!!
First letter of insertString : B
Second letter of insertString : e
Last character of insertString : e
After clearing insertString, value : 
After erasing Beautiful Good from replacedSubString, the new string : Good Life
String str1 is empty - false
*/
