#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>
#include "Gradebook.h"

using namespace std;
// constructor for initializing all functions
  GradeBook::GradeBook( string name, string prof, const int gradesArray[][ tests ] )
  {
      setCourseName( name ); // validate and store courseName
      setInstructorsName( prof ); // validate and store instructors name
      aCount=0;
      bCount=0;
      cCount=0;
      dCount=0;
      fCount=0;
      maximumGrade = 0;
      for ( int student = 0; student < students; student++ )

        for ( int test = 0; test < tests; test++ )
             grades[ student ][ test ] = gradesArray[ student ][ test ];
  } // end two -argument grade book constructor

  void GradeBook::setCourseName( string name )
  {
      if (name.length() <= 25 ) // if name has 25 or fewer characters
      courseName = name;

      if ( name.length() > 25 )
      {
          //set courseName to first 25 characters of parameter name
          courseName = name.substr( 0, 25 ); // start at 0, length of 25

          cout << "Name \"" << name << "\" exceeds maximum length (25). \n"
          << "Limiting courseName to first 25 characters.\n" << endl;
      }//end if
  }//end function setCourseName

  string GradeBook::getCourseName()
  {
      return courseName;
  }

  void GradeBook::displayMessage()
  {
      cout << "Welcome to GradeBook for\n" << getCourseName() << "!" << endl;
  }

 //function that collects instructors name
      void GradeBook::setInstructorsName( string prof )
      {
          InstructorsName = prof;
      }

      string GradeBook::getInstructorsName()
      {
          return InstructorsName;
      }

       // processing all grade analizers in one place instead of calling them each after the other
        void GradeBook::processGrades()
    {
        outputGrades(); // output grades array

        // calls function getMInimum and getMaximum
        cout << "\nLowest grade in the grade book is " << getMinimum() << endl;
        cout << "\nHighest grade in the grade book is " << getMaximum() << endl;

        outputBarChart(); // print grade distribution chart
    }// end function processGrades

      void GradeBook::determineClassAverage()
      {
          int total;
          int gradeCounter;
          int grade;

          // Initialization phase
          total = 0;
          gradeCounter = 0;

          // Processing phase
          cout << "Enter grade or -1 to quit" << endl;
          cin >> grade;

          //loop until sentinel value read user
          while ( grade != -1 )
          {
              total = total + grade;
              gradeCounter = gradeCounter + 1;

              // prompt for input and read next grade from user
              cout << "Enter grade or -1 to quit: " << endl;
              cin >> grade;
          } // end while

          // Termination phase
          if ( gradeCounter != 0 )
          {
              double average = static_cast< double >( total ) / gradeCounter;

              // display total and average ( with two digits of precision )
              cout << "\nTotal of all " << gradeCounter << " grades entered is: " << total << endl;
              cout << "Class Average is: " << setprecision( 2 ) << fixed << average << endl;
          } // End of if statement
          else
            cout << "No grades were entered" << endl;
      }


      // input and arbitrary number of grades from user; update grade counter
      void GradeBook::inputGrades()
      {
          int grade;

          cout << "Enter the letter grades: " << endl;
          cout << "Enter the EOF character to end input" << endl;

           // loop until user types end-of-file key sequence
      while(( grade = cin.get() ) != EOF )
      {
          // determined which grade was entered
          switch ( grade ) // switch statement nested in while
          {
              case 'A':
              case 'a':
                aCount++;
                break; // necessary to exit switch

              case 'B':
              case 'b':
                  bCount++;
                      break;

              case 'C':
              case 'c':
                  cCount++;
                  break;

              case 'D':
              case 'd':
                   dCount++;
                   break;

              case 'F':
              case 'f':
                   fCount++;
                   break;

             case '\n':
             case '\t':
             case ' ':
                break;


             default:
                cout << "Incorrect letter grade entered" << "Enter a new grade. " << endl;
                break;
          }//end switch
       }// end while

      }//end function input grades

    void GradeBook::displayGradeReport()
    {
        // Output summary of results
        cout << "\n\nNumber of students who received each letter grade:" << endl;
            cout << "\nA: " << aCount << endl;
            cout << "\nB: " << bCount << endl;
             cout << "\nC: " << cCount << endl;
             cout << "\nD: " << dCount << endl;
             cout << "\nF: " << fCount << endl;
    }

    // function to calculate the average of all grade points
    void GradeBook::gradePointAverage()
    {
        int average;
        average = aCount+bCount+cCount+dCount+fCount;
        cout << "\n\nAverage Grade Point= " << static_cast <double> (average)/5 << setprecision(2) << fixed << endl;
    }


    // input three grades from user to determine three maximum of them grades
    void GradeBook::inputGrades1()
    {
        int grade1;
        int grade2;
        int grade3;

        cout << "Enter three integer grades: " << endl;
        cin >> grade1 >> grade2 >> grade3;

        // store maximum in member maximum grade
        maximumGrade = maximum( grade1, grade2, grade3 );
    }// end input function grades

    // function that takes three integer variables and returns the maximum and can be reused in another class
    // software engineering observation tip
    int GradeBook::maximum( int x, int y, int z )
    {
        int maximumValue = x; // Assume x is the largest

        if ( y > maximumValue )
            maximumValue = y;

        if ( z > maximumValue )
            maximumValue = z;

        return maximumValue;
    } //end of the maximum value function


    // displaying a report based on the grades entered by the user
    void GradeBook::displayGradeReport1()
    {
        cout << "Maximum of grades entered: " << maximumGrade << endl;
    }

    int GradeBook::getMinimum()
    {
        int lowGrade = 100; // Assume lowest grade is 100

        // loop through grades array
        for ( int student = 0; student < students; student++ )
        {
            // loop through columns of current row
            for ( int test = 0; test < tests; test++ )
            {
                // if current grade less than low grade assign it to low grade
                if ( grades[ student ][ test ] < lowGrade )
                lowGrade = grades[ student ][ test ];
            }
        } // End for

        return lowGrade;
    }

    // Find maximum grade
    int GradeBook::getMaximum()
    {
        int highGrade = 0; // assume highest grade is 0

        // loop through grades array
        for ( int student = 0; student < students; student++ )
        {
            for ( int test = 0; test < tests; test++ )
            {
                 // if current grade higher than highGrade, assign it to highGrades
            if ( grades [ student ][ tests ] > highGrade )
                highGrade = grades [ student ][ tests ]; // new highest grade
            } // end inner for

        } // end for
        return highGrade;
    }


    // determine average grade for test
    double GradeBook::getAverage( const int setOfGrades[], const int grades )
    {
        int total = 0; // Initialize total

        //Sum grades in array
        for ( int grade = 0; grade < grades; grade++ )
            total += setOfGrades[ grade ];

        // return average of grades
        return static_cast< double >( total ) / grades;
    } // end function getAverage


    // Output bar chart displaying grade distributing
    void GradeBook::outputBarChart()
    {
        cout << "\nOverall Grade Distribution:" << endl;

        // stores frequency of grades in each range of 10 grades
        const int frequenceSize = 11;
        int frequency[ frequenceSize ] = {}; // initializes elements to zero

        // for each grade, increment the appropriate frequency
        for ( int student = 0; student < students; student++ )

            for ( int test = 0; test < tests; test++ )
                ++frequency[ grades[ student ][ test ] / 10 ];

        // for each grade frequency, print bar in chart
        for ( int count = 0; count < frequenceSize; count++ )
        {
            // output bar labels ( "0-9:" ...., "90-99:", "100:" )
            if ( count == 0 )
                cout << " 0-9: ";
            else if ( count == 10 )
                cout << " 100: ";
            else
                cout << count * 10 << "-" << ( count * 10 ) + 9 << ": ";

            // print bar asterisks
            for ( int stars = 0; stars < frequency[ count ]; stars++ )
                cout << '*';

            cout << endl;
        }
    }


    void GradeBook::outputGrades()
    {
       cout << "\nThe grades are:\n" << endl;
       cout << "           "; // align column heads

       // create a column heading for each of the tests
        for ( int test = 0; test < tests; test++ )
            cout << "Test " << test + 1 << "   ";

        cout << "Average" << endl; // student average column heading

        // create rows/columns of text representing array grades
        for ( int student = 0; student < students; student++ )
        {

          cout << "Student " << setw( 2 ) << student + 1;

          // output student's grades
          for ( int test = 0; test < tests; test++ )
            cout << setw( 8 ) << grades[ student ][ test ];

          // call members function getAverage to calculate student's average;
          // pass row of grades and the value of tests as the arguments
          double average = getAverage( grades[ student ], tests );
          cout << setw( 10 ) << setprecision( 2 ) << fixed << average << endl;

        }
    }



















