#include <iostream>
#include <string>

using std::string;

class GradeBook
{
    public:
        void setCourseName(string name)
        {   
            courseName = name;
        }
        string getCourseName()
        {
            return courseName;
        }
        void displayMenssage()
        {
            std::cout << "Welcome to the grade book for\n" << getCourseName() << "!" << std::endl;
        }
        private:
        string courseName;
};

int main()
{
    GradeBook myGradeBook;
    string nameOfCourse;

    std::cout << "Please enter the course name:" << std::endl;
    std::getline(std::cin, nameOfCourse);
    
    myGradeBook.setCourseName(nameOfCourse);
    myGradeBook.displayMenssage();
}