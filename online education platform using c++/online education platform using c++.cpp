#include <iostream>
#include <vector>
#include <string>

class Course {
public:
    Course(const std::string& name, const std::string& instructor)
        : name(name), instructor(instructor) {}

    void enrollStudent(const std::string& studentName) {
        enrolledStudents.push_back(studentName);
    }

    void displayInfo() const {
        std::cout << "Course: " << name << "\n";
        std::cout << "Instructor: " << instructor << "\n";
        std::cout << "Enrolled Students:\n";
        for (const auto& student : enrolledStudents) {
            std::cout << "- " << student << "\n";
        }
    }

private:
    std::string name;
    std::string instructor;
    std::vector<std::string> enrolledStudents;
};

class OnlineEducationPlatform {
public:
    void createCourse(const std::string& name, const std::string& instructor) {
        courses.push_back(Course(name, instructor));
    }

    void enrollStudentInCourse(int courseIndex, const std::string& studentName) {
        if (courseIndex >= 0 && courseIndex < courses.size()) {
            courses[courseIndex].enrollStudent(studentName);
            std::cout << studentName << " enrolled in course " << courses[courseIndex].getName() << "\n";
        } else {
            std::cout << "Invalid course index.\n";
        }
    }

    void displayAllCourses() const {
        std::cout << "Available Courses:\n";
        for (size_t i = 0; i < courses.size(); ++i) {
            std::cout << i << ". " << courses[i].getName() << "\n";
        }
    }

    void displayCourseInfo(int courseIndex) const {
        if (courseIndex >= 0 && courseIndex < courses.size()) {
            courses[courseIndex].displayInfo();
        } else {
            std::cout << "Invalid course index.\n";
        }
    }

private:
    std::vector<Course> courses;
};

int main() {
    OnlineEducationPlatform platform;

    platform.createCourse("Introduction to Programming", "John Smith");
    platform.createCourse("Linear Algebra", "Alice Johnson");

    platform.enrollStudentInCourse(0, "Emma");
    platform.enrollStudentInCourse(1, "James");
    platform.enrollStudentInCourse(1, "Sophia");

    platform.displayAllCourses();

    int selectedCourse;
    std::cout << "Enter the course index to display details: ";
    std::cin >> selectedCourse;
    platform.displayCourseInfo(selectedCourse);

    return 0;
}
