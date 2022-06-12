#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//define structure to hold Course
struct Course {
    string ID;
    string title;
    string preq1;
    string preq2;
};

// function to compare two string, used for printing all courses in alphanumeric order, from lowest to highest
bool compareFunction(string a, string b) { return a < b; }


// menu function
void displayMenu() {
    cout << "Welcome to the course planner." << endl;
    cout << "a. Load Data Structure" << endl;
    cout << "b. Print Course List" << endl;
    cout << "c. Print Course" << endl;
    cout << "d. Exit" << endl;
    cout << endl;
    cout << "What would you like to do?" << endl;
}

int main()
{
    //create a vector to hold all Course objects
    vector<Course>courses;
   
    //create a string vector to hold all course IDs, which can be rearranged to a desired order
    vector<string> vectID;


    // while loop to get user choice
    displayMenu();
    char userChoice;
    cin >> userChoice;
    while (true) {
        if (userChoice == 'a') {
            //use ifstream to read txt file
            ifstream myFileStream("course_info.txt");
            if (!myFileStream.is_open())
            {
                cout << "File failed to open" << endl;
                return 0;
            }

            string courseID, courseTitle, courseReq1, courseReq2;
            string line;

            //while loop to read txt line by line
            while (getline(myFileStream, line)) {
                //each loop, create a new instance of Course
                Course* course = new Course;
                stringstream ss(line);

                // reset the following variables to " "
                //to prevent the following variables being carried over from previous line's reading
                courseReq1 = "";
                courseReq2 = "";

                //the first string is the course ID, assign it to course->ID
                getline(ss, courseID, ',');
                course->ID = courseID;
                //the second string is course title, assign it to course->title
                getline(ss, courseTitle, ',');
                course->title = courseTitle;

                //push_back to courseID to the vector vectID.
                vectID.push_back(courseID);

                //the third string is 1st prerequisite, assign it to course->preq1
                // for those course without prerequisite, their preq1 and preq2 will be empty
                getline(ss, courseReq1, ',');
                course->preq1 = courseReq1;

                //the four string is 2st prerequisit, assign it to course->preq2
                getline(ss, courseReq2, ',');
                course->preq2 = courseReq2;

                // push_back the course instance to the vector courses
                courses.push_back(*course);

            }
        }
        else if (userChoice == 'b') {
            //sort the ID vector from the lowest to the highest
            sort(vectID.begin(), vectID.end(), compareFunction);
            //interate through the ID vector
       //interate through the courses vector
           // if the course ID in the ID vector equals to the course ID in courses
               //print the course information
            for (int i = 0; i < vectID.size(); ++i) {
                for (int j = 0; j < courses.size(); ++j) {
                    if (vectID.at(i) == courses.at(j).ID) {
                        cout << courses.at(i).ID << " " << courses.at(i).title << endl;
                        if (courses.at(i).preq1 != "") {
                            cout << "    Prerequisites: " << courses.at(i).preq1<<" ";
                            if (courses.at(i).preq2 != "") {
                                cout << courses.at(i).preq2;
                            }
                            cout << endl;
                        }

                    }
                }
            }
        }
        else if (userChoice == 'c') {
            cout << "What course do you want to know about?" << endl;
            string courseSearch;
            cin >> courseSearch;
            transform(courseSearch.begin(), courseSearch.end(), courseSearch.begin(), ::toupper);

            for (unsigned i = 0; i < courses.size(); ++i) {
                if (courses.at(i).ID == courseSearch) {
                    cout << courses.at(i).ID << ", "<< courses.at(i).title << endl;
                    if (courses.at(i).preq1 != "") {
                        cout << "Prerequisites: " << courses.at(i).preq1;
                    }
                    if (courses.at(i).preq2 != "") {
                        cout << courses.at(i).preq2;
                    }
                }
            }
        }
        else if (userChoice == 'd') {
            cout << "You exit the program" << endl;
            break;
        }
        else {
            cout << userChoice << " is not a valid option." << endl;
        }
        displayMenu();
        cin >> userChoice;
    }
   
}
      

    

      