// Siddharth Sriram, CS1436.010, Lab 10
// This program will will be creating a quiz grading program. You will 
// compare the student's answers with the correct answers, and determine if the student passed the quiz or not.

#include <iostream>
#include <string>
#include <fstream> // For ifstream and ofstream

using namespace std;

// This is the max size of the answer arrays for both the student answers and correct answers
const int Maximum_Size = 30;

// The 3 functions used in the program
int ReadinAnswers(char Answers[], string FN);
void ShowResults(const char CorrectAnswers[], const char AnswersbyStudents[], int NumberofCorrectAnswers, int NumberofStudentAnswers);

int main() {
    // Store the answers of the students
    char AnswersbyStudents[Maximum_Size];

    // Store the correct answers which are compared to the students answers
    char CorrectAnswers[Maximum_Size];

    // The number of student answers and correct answers from the students answers read in from students answers
    int NumberofStudentAnswers;
    int NumberofCorrectAnswers;

    // File names for both student and correct answers
    string StudentFN;
    string CorrectFN;

    // Asks the user to enter the answers of the student file
    cout << "Enter student answers file name" << "\n";
    cin >> StudentFN;

    // Reads in the answers by the student file
    NumberofStudentAnswers = ReadinAnswers(AnswersbyStudents, StudentFN);

    // If the student enters in an invalid input this is outputted
    if (NumberofStudentAnswers == -1) {
        cout << "File \"" << StudentFN << "\" could not be opened" << "\n";
        return 1;
    }

    // Asks the user for the correct answers file
    cout << "Enter correct answer file name" << "\n";
    cin >> CorrectFN;

    // Reads in the correct answers file
    NumberofCorrectAnswers = ReadinAnswers(CorrectAnswers, CorrectFN);

    // If the student enters in an invalid input this is outputted
    if (NumberofCorrectAnswers == -1) {
        cout << "File \"" << CorrectFN << "\" could not be opened" << "\n";
        return 1;
    }

    // Check if the answers are correct
    if (NumberofStudentAnswers != NumberofCorrectAnswers) {
        cout << "The student answers file has " << NumberofStudentAnswers 
             << " entries and the correct answers file has " << NumberofCorrectAnswers << " entries" << "\n";
        
        // Tells the user the issue with why the grading can't be proceed
        cout << "Grading cannot be done if they are not the same" << "\n"; 
        return 1;
    }

    if (NumberofStudentAnswers == 0) {
        cout << "The number of student answers and correct answers are both 0" << "\n";
        cout << "No grade can be calculated" << "\n";
        return 1;
    }

    // Show the results 
    ShowResults(CorrectAnswers, AnswersbyStudents, NumberofCorrectAnswers, NumberofStudentAnswers);

    return 0;
}

// Function to read answers from a file
int ReadinAnswers(char Answers[], string FN) {
    ifstream file(FN); // Open the file
    if (!file.is_open()) {
        return -1; // Return -1 if the file could not be opened
    }

    int Count = 0;
    // Read answers into the array while there is space
    while (file >> Answers[Count] && Count < Maximum_Size) {
        Count++;
    }

    file.close(); // Close the file
    return Count;
}

// Function that displays output
void ShowResults(const char CorrectAnswers[], const char AnswersbyStudents[], int NumberofCorrectAnswers, int NumberofStudentAnswers) {
    int MissedQuestions = 0; // Count the number of missed questions
    cout << fixed; // Set the precision for floating-point output
    cout.precision(1);

    // For loop to go through students answers and correct answers stating 
    // which is incorrect and which is correct as well
    for (int x = 0; x < NumberofStudentAnswers; ++x) {
        char StudentAnswer = AnswersbyStudents[x];
        char CorrectAnswer = CorrectAnswers[x];
        if (StudentAnswer != CorrectAnswer) {
            MissedQuestions++; // Increment missed question count
            cout << "Question " << x + 1 << " has incorrect answer '" << StudentAnswer
                 << "', the correct answer is '" << CorrectAnswer << "'" << "\n";
        }
    }

    // Displays wheather the student passed or failed as well as his grade
    int TotalQuestions = NumberofStudentAnswers;
    double CorrectPercentage = ((TotalQuestions - MissedQuestions) / static_cast<double>(TotalQuestions)) * 100;

    cout << MissedQuestions << " questions were missed out of " << TotalQuestions << "\n";
    cout << "The student grade is " << CorrectPercentage << "%" << "\n";

    if (CorrectPercentage >= 70.0) {
        cout << "The student passed" << "\n";
    } else {
        cout << "The student failed" << "\n";
    }
}
