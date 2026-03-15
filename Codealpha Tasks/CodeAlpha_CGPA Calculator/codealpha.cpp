#include <iostream>
using namespace std;

int main()
{
    int numCourses;              // Variable to store number of courses
    float grade, creditHours;   // Variables for grade and credit hours
    float totalCredits = 0;     // To store total credit hours
    float totalGradePoints = 0; // To store total (grade × credit hours)

    // Ask the user how many courses they have taken
    cout << "Enter number of courses: ";
    cin >> numCourses;

    // Loop to take input for each course
    for (int i = 1; i <= numCourses; i++)
    {
        cout << "\nCourse " << i << endl;

        // Input grade for the course
        cout << "Enter grade (GPA value e.g., 4.0, 3.7, 3.0 etc): ";
        cin >> grade;

        // Input credit hours for the course
        cout << "Enter credit hours: ";
        cin >> creditHours;

        // Calculate grade points for this course
        float gradePoints = grade * creditHours;

        // Add to totals
        totalCredits = totalCredits + creditHours;
        totalGradePoints = totalGradePoints + gradePoints;

        // Display course information
        cout << "Grade Points for this course: " << gradePoints << endl;
    }

    // Calculate CGPA
    float CGPA = totalGradePoints / totalCredits;

    // Display results
    cout << "\n----- RESULT -----" << endl;
    cout << "Total Credit Hours: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "Final CGPA: " << CGPA << endl;

    return 0;
}