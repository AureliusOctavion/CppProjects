// Siddharth Sriram, CS1436.010, Lab 6
// The following program will be outputting the characters that map to the ASCII codes 32 through 126.

#include <iostream>
using namespace std;

int main() { // Beginning of the program

    // Unsigned Integers lower and upper value
    unsigned int Lower_Value;
    unsigned int Upper_Value;

do {
    // Prompts user to enter in his/her own selected Lower and Upper Values in the range of 32 to 126
    cout << "Enter lower and upper values" << "\n";
    cin >> Lower_Value; // Lower Value user enters first
    cin >> Upper_Value; // Upper Value user enters second

    // Checks to make sure the Lower and Upper Values are in the range of 32 to 126, and if the values are less than 32 or greater than 126 you need to display the cout message
   if (Lower_Value < 32 || Lower_Value > 126 || Upper_Value < 32 || Upper_Value > 126 || Lower_Value > Upper_Value) {
       cout << "Values must be in range 32 to 126 inclusive" << "\n"; // This is the message thats displayed if one of the following conditions above are not meant
   }
   // While portion of the do-while loop where if the first condition is not met it goes all the way back to the do portion of the program and asks the user to enter in the lower and upper value again if the values the user entered previously were invalid
} while (Lower_Value < 32 || Lower_Value > 126 || Upper_Value < 32 || Upper_Value > 126 || Lower_Value > Upper_Value);
// Outputs what the characters for ASCII values between whatever numbers the user inputs from before (lower value and upper value)
cout << "Characters for ASCII values between " << Lower_Value << " and " << Upper_Value << "\n";
// Beginning of the table output
cout << "----+----+----+----+" << "\n";

// This keeps trask of the number of character printed, starting at 0 as no characters were printed yet at the beginning of the program.
int tracker_of_numbers_printed = 0; 


for (unsigned int iterates_through_ASCII = Lower_Value; iterates_through_ASCII <= Upper_Value; iterates_through_ASCII++){ // Goes through the ASCII values between lower value and upper value
    cout << static_cast<char>(iterates_through_ASCII); // Outputs whatever character was entered to the corresponding ASCII value

    // Makes sure user displays the values as characters with 20 characters per line of output
    tracker_of_numbers_printed++; 

    if (tracker_of_numbers_printed % 20 == 0){
        cout << "\n";
    }
}
// For the last line, so output formats correctly through adding \n if the total number of characters outputted is not a multiple of 20
if (tracker_of_numbers_printed % 20 !=0) { // Remainder given when tracker_of_numbers_printed is divided by 20, if the remainder we get is not 0 in turn does that mean there are less than 20 characters on our final line
        cout << "\n";
    }

// Bottom of the table output
cout << "----+----+----+----+" << "\n";

return 0;


}