# CS260-Data-Structures-and-Algorithms

What was the problem you were solving in the projects for this course?
In this course, I designed three different data structures to hold a list of courses, including vector, hash table, and binary search tree. In each data structure, the program starts with loading the course data from the txt file into that data structure. Then, create the infrastructure of the data type to hold each course. And finally, create functions to print the courses in alphanueric order and implement searching function based on user requirements.

How did you approach the problem? Consider why data structures are important to understand.
I went over the algorithm of each data structure and understood how create an example of each. Finally, considering the complexity of the data structure and functions from user requirements, I chose vector to store the course information. 

How did you overcome any roadblocks you encountered while going through the activities or project?
There were quite a few challanges before I completed the project. The first one is to load a txt file into the vector. Not all the courses have prerequisites. Therefore, I decided to create two prerequisite variables for each course object. Thus, for those courses that do not have prerequisites, their prerequisites will be empty. The second challange was to create an Course instance course, but the IDE tool recommmends using pointer like this: Course* course = new Course; . I do not understand that '*' because I don't think vector was using the pointers. However, I appreciate that Visual Studio can catch my error and provide right solutions.

How has your work on this project expanded your approach to designing software and developing programs?
During the develoment of the project, I was able to outline my work, implement each step that builds for the next, and finally troubleshoot the errors that occurred in each testing. The core value that I learned from the development of the project is being able to analyze and choose the right data structure to fulfill user requirements. 


How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?
Actually, there were several versions of my codes. In the beginning, I had everything in the main function. As I worked towards the end of the project, I was able to break the whole program two sections: the methods outside the main method, and the main method. This way, the main function does not appear clumsy. If there is no course list, I can just change the file path of the course so that the program can still run. 
