#include "student.hpp"
#include <stdbool.h>
#include <iomanip>

int main() 
{
    //enter name
    std::string name;
    std::cout << "What is your name?\n";
    std::cin >> name;
    Student student{name};

    //ask for class name
    std::cout << "Hi " << name << "! Please enter the name of a class you are taking."<< "\n";
    std::string class_name;
    std::cin >> class_name;
    
    //ask for the grade
    std::cout << "What is your grade in the class? Please enter a number inbetween 0 and 4.0.\n";
    float grade;
    std::cin >> grade;

    //ask for credit hours
    std::cout << "How many credit hours is it? Please enter a whole number\n";
    int hours;
    std::cin >> hours;

    //add first course to the vector
    Course course1{class_name, grade, hours};
    student.addCourse(course1);

    //Do it all on repeat till all courses have been added
    while(true)
    {
        std::cout << "Please enter the next class name. If you are done adding classes, please type done to calculate your cummulative GPA.\n";
        std::cin >> class_name;

        if(class_name == "done")
        {
            break;
        }

        std::cout << "What is your grade in the class? Please enter a number inbetween 0 and 4.0.\n";
        std::cin >> grade;

        std::cout << "How many credit hours is it? Please enter a whole number\n";
        std::cin >> hours;

        Course temp_course{class_name, grade, hours};
        student.addCourse(temp_course);
    }
    
    //Calculate the cummulative gpa
    int total_courses = student.getCourseCount();
    float final_gpa = 0.0;
    int final_hours = 0;

    for (int i = 0; i < total_courses; i++)
    {
        float temp_gpa = student.getCourseGrade(i);
        int temp_hours = student.getCourseHours(i);
        float temp_total = temp_gpa * temp_hours;
        final_gpa += temp_total;
        final_hours += temp_hours;
    }

    final_gpa = final_gpa / final_hours;

    //Print the results
    std::cout << "Your final cummulative GPA is " << std::fixed << std::setprecision(2) << final_gpa << "\n\n" << "If you'd like to use the calculator again, close and reopen it!";

    while(true)
    {
        
    }
}