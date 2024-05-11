#ifndef GRADEBOOK_H_INCLUDED
#define GRADEBOOK_H_INCLUDED
#include <string>
using namespace std;

// GradeBook class definition
 class GradeBook
  {
  public:

      // constant -- number of students who took the test
      static const int students = 10;
      static const int tests = 3;

    GradeBook( string, string, const int [][ tests ] ); // constructor initializes course name and array of grades
    void setCourseName( string ); // function to set the course name
    string getCourseName(); // function to retrieve the course name
    void displayMessage(); // function to display welcome message
    void setInstructorsName ( string ); // function to set the instructors name
    string getInstructorsName(); // function to retrieve instructors name
     void determineClassAverage(); //
     void inputGrades();
     void inputGrades1();
     void displayGradeReport();
     void displayGradeReport1();
     void gradePointAverage();
     int maximum( int, int, int );
     void processGrades(); // Perform various operations on the grade data
     double getAverage( const int[], const int );
     void outputBarChart();
     void outputGrades();
     int getMinimum();
     int getMaximum();

  private:
    string courseName;
    string InstructorsName;
    int aCount;
    int bCount;
    int cCount;
    int dCount;
    int fCount;
    int maximumGrade;
    int grades[ students ] [ tests ];
  };

#endif // GRADEBOOK_H_INCLUDED
