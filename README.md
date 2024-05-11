Gradebook Class for Students
The Gradebook Class for Students is a C++ program designed to manage and calculate grades for students in a classroom setting. 
It provides functionality for adding students, entering grades, calculating averages, and generating reports.

Features
Add Students: Allows users to add students to the gradebook.
Enter Grades: Enables users to enter grades for each student.
Calculate Averages: Automatically calculates the average grade for each student.
Generate Reports: Provides options for generating reports such as class average, highest/lowest grades, etc.
User-Friendly Interface: Offers a simple and intuitive interface for ease of use.

Usage
To use the Gradebook Class for Students in your C++ project, follow these steps:

Clone or download the repository to your local machine.

Include the Gradebook.h header file in your project.

Create an instance of the Gradebook class in your main application.

Use the provided methods (addStudent, enterGrade, calculateAverage, etc.) to interact with the gradebook.

#include "Gradebook.h"
#include <iostream>

int main() {
    // Create a new Gradebook instance
    Gradebook gradebook;

    // Add students
    gradebook.addStudent("John");
    gradebook.addStudent("Alice");
    gradebook.addStudent("Bob");

    // Enter grades
    gradebook.enterGrade("John", 85);
    gradebook.enterGrade("Alice", 92);
    gradebook.enterGrade("Bob", 78);

    // Calculate averages
    gradebook.calculateAverages();

    // Generate reports
    gradebook.generateReport();

    return 0;
}
Contributing
Contributions to the Gradebook Class for Students project are welcome! If you'd like to contribute, 
please fork the repository, make your changes, and submit a pull request.

License
This project is licensed under the MIT License. See the LICENSE file for details.
