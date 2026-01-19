#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <limits>

// Define the Student structure
struct Student {
    std::string name;
    int age;
    char grade;
};

//write 
void save_students_to_file(const std::string& filename, const std::vector<Student>& students) {
    std::ofstream outFile(filename); // Open file for writing
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << " for writing." << std::endl;
        return;
    }

    for (const auto& student : students) {
        // Write each student's data as a new line in a consistent format
        outFile << student.name << std::endl;
        outFile << student.age << std::endl;
        outFile <<  student.grade << std::endl;
    }

    outFile.close(); // Close the file
}

//read
std::vector<Student> load_students_from_file(const std::string& filename) {
    std::vector<Student> students;
    std::ifstream inFile(filename); // Open file for reading

    if (!inFile.is_open()) {
        std::cerr << "Error: Could not open file " << filename << " for reading." << std::endl;
        return students;
    }

    Student tempStudent;
    std::string nameLine;
    // Read data piece by piece until the end of the file is reached
    //getline(myFile , tempStudent.name )
    while (std::getline(inFile,nameLine,'\n')) {
        tempStudent.name = nameLine;
        inFile >> tempStudent.age;
        inFile >> tempStudent.grade;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        students.push_back(tempStudent); // Add the read struct to the vector
    }

    inFile.close(); // Close the file
    return students;
}

int main() {
    // 1. Create a vector of students in memory
    std::vector<Student> classA;
    classA.push_back({"Alice ", 18, 'A'});
    classA.push_back({"Bob ", 19, 'B'});
    classA.push_back({"Charlie ", 17, 'C'});

    // 2. Save the data to a file
    save_students_to_file("students.txt", classA);
    std::cout << "Student data saved to students.txt" << std::endl;

    // 3. Load the data back into a new vector
    std::vector<Student> loadedStudents = load_students_from_file("students.txt");
    std::cout << "Student data loaded from students.txt" << std::endl;

    // 4. Verify the loaded data
    std::cout << "\nLoaded Students:" << std::endl;
    for (const auto& s : loadedStudents) {
        std::cout << "Name: " << s.name << ", Age: " << s.age << ", Grade: " << s.grade << std::endl;
    }

    return 0;
}


