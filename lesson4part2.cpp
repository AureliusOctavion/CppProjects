// Siddharth Sriram, CS1436.010, Lab 4
// The followiing program will read in the number of seconds and convert it to days, hours, minutes and remaining seconds.

#include <iostream>
using namespace std;

int main(){ // Beginning of program
    
    // Long long integers throughout program
    long long int Seconds_Input;
    long long int Days;
    long long int Hours;
    long long int Minutes;
    long long int Seconds;
    
    // Asks user to enter in the amount of seconds which is then put in for total seconds as well
    cout << "Enter seconds" << "\n";
    cin >> Seconds_Input;
    cout << "Total seconds: " << Seconds_Input << "\n";
    
   // Blank line before output
   cout << "\n";
    
   // If this value is 0 or less you need to output the message Total seconds must be greater than zero
   if (Seconds_Input <= 0){
       cout << "Total seconds must be greater than zero" << "\n";
       return 0;
   }
   
   // Formulas to calculate for the days, hours, minutes, and seconds 
   
    Days = Seconds_Input / (24 * 3600); // Days is found by dividing the seconds we put in originally by 86400
    
    Seconds_Input %= (24 * 3600);       // Updates the value of Seconds_Input by taking the remainder after dividing it by the number of seconds in a day
    
    Hours = Seconds_Input / 3600;       // Hours is found by dividing the number of seconds we put in orignally by 3600 (the amount of seconds in an hour)
    
    Seconds_Input %= 3600;              // Updates the value of Seconds_Input by taking the remainder when it is divided by 3600 seconds.
    
    Minutes = Seconds_Input / 60;       // Minutes is found by dividing the seconds we orignally put in by 60 (amount of seconds in minute)
    
    Seconds = Seconds_Input % 60;       // Our remaining seconds
    
    
    // Output of all the results from the calculations of input seconds to days, hours, minutes, and seconds. These are only outputted when the number of days is more than 0, the hours if the number of hours is more than 0, the minutes if the number of minutes is more than 0 and output the seconds if the number of seconds is greater than 0.
    
    if (Days > 0)
    cout << Days << " day(s)" << "\n";
    if (Hours > 0)
    cout << Hours << " hour(s)" << "\n";
    if (Minutes > 0)
    cout << Minutes << " minute(s)" << "\n";
    if (Seconds > 0)
    cout << Seconds << " second(s)" << "\n";
    
    return 0;
}