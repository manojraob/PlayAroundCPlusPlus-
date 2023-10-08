#include <iostream>
#include <map>

using namespace std;

int main() 
{
   // Create map with assignment operator. The same can be initialised as:
   // map<int, string> mapOfIntStrings {{1, "Amy"}, {2, "Brook"}, {3, "Chadli"}};
   map<int, string> mapOfIntStrings = {{1, "Amy"}, {2, "Brook"}, {3, "Chadli"}};
   
   // insert
   mapOfIntStrings.insert(make_pair(4, "Daniel"));
   mapOfIntStrings[5] = "Evelyn";
   mapOfIntStrings[5] = "Evan";// Now "Evelyn" will be overwritten by "Evan".
   
   // Access keys and values
   map<int, string>::iterator itr;
   for(itr = mapOfIntStrings.begin(); itr != mapOfIntStrings.end(); ++itr)
   {
       cout << "[" << itr->first << "] = " << itr->second <<endl; // Alternative way - use (*iter).first , (*iter).second
   }
   
   // find
   itr = mapOfIntStrings.find(4);
   cout << itr->second << endl ; // should print "Daniel".
   itr = mapOfIntStrings.find(6);
   cout << boolalpha << (itr == mapOfIntStrings.end()) << endl; // if key not found in map, itr points to map.end().
   
   // delete a particular key-value entry , in our case key 2.
   mapOfIntStrings.erase(2); // Alternative : map::iterator it = myMap.begin(); ++itr; myMap.erase(itr);
   cout << endl;
   for(itr = mapOfIntStrings.begin(); itr != mapOfIntStrings.end(); ++itr)
   {
       cout << "[" << itr->first << "] = " << itr->second <<endl; 
   }
   
   cout << endl;
   // delete a range of entries i.e erase(itr_first, itr_last). Here itr_first is included , but not itr_last.
   // Use either iterator to point to required keys or use find. In the given example, 3 and 4 will be removed but not 5.
   mapOfIntStrings.erase(mapOfIntStrings.find(3), mapOfIntStrings.find(5));
    for(itr = mapOfIntStrings.begin(); itr != mapOfIntStrings.end(); ++itr)
   {
       cout << "[" << itr->first << "] = " << itr->second <<endl; 
   }
}
