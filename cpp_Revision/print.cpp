/* 
    Printing to the Console 
*/

// -- Header Files --
#include <iostream>
using namespace std;

// -- Main Function --
int main() {
  
    cout << "Hello World!" << endl; // New line
    cout << "My name is Milly."; // No new line

    // --- Variables ---
    // Integer
    int age = 20;
    cout << age << endl;

    // Double
    double decimal = 0.17;
    cout << decimal << endl;  

    // Boolean (Case sensitive)
    bool TheTruth = true;
    cout << boolalpha << TheTruth << endl; // boolalpha makes output 'true' or 'false'

    bool TheSecondTruth = true;
    cout << TheSecondTruth << endl; // Without boolalpha, the output is 1 or 0
    
    //String
    string words = "I got peach.";
    cout << words << endl;

    /* 
    --- Variable Naming Rules ---
    + Start with a letter or underscore
    + Remainder of variable name is letters, numbers, or underscores
    + Cannot use keywords
    + Case sensitive
    */
    
    return 0;
}
