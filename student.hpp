#include <string>
#include <float.h>
#include <vector>
#include <iostream>

class Course
{

private:
    const std::string c_name;
    float grade;
    int hours;
    friend class Student;
    
public:
    Course(std::string p_name, float p_grade, int p_hours) : c_name(p_name), grade(p_grade), hours(p_hours) {}
    
};

class Student
{

private:
    std::string name;
    std::vector<Course> courses;

public:
    Student(std::string p_name = "Unknown") : name(p_name) {}

    void addCourse(Course& c)
    {
        courses.push_back(c);
    }

    std::string getCourseName(int i)
    {
        return courses[i].c_name;
    }

    float getCourseGrade(int i)
    {
        return courses[i].grade;
    }

    int getCourseHours(int i)
    {
        return courses[i].hours;
    }

    int getCourseCount()
    {
        return courses.size();
    }

    std::string getName()
    {
        return name; 
    }

};

