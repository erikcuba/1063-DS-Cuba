/* Erik Cuba
Data Sructures - 1063
Homework 1
This program sorts and prints a class list with grades.*/

#include <iostream> // prints and recieves to console
#include <string>   
#include <fstream>  // read a write files

#define SIZE 10		// Constant for static grade size

using namespace std;

struct Student
{
	string fname;
	string lname;
	int numGrades;
	int grades[10];
};

//Prototypes
int loadClassList(Student[], string);
void printClassList(Student[], int);

int main()
{
	int A[SIZE];        // Array to hold students read from file
	Student s0;
	Student s1;
	Student *classList=new Student[100];
	int classSize = 0;

	// Call the loadClassList function to open a file and load an array
	// of `Student` structs.
	classSize = loadClassList(classList, "input.txt");

	// Function to print out an array of students in a formatted way.
	printClassList(classList, classSize);

	return 0;
}
/*Function: loadClassList
Description:
	   Reads a file with student data, and loads it into an array of Students.
Params:
	  Student *classlist  : array of Students
	  string  filename    : name of file to process
 Returns:
	 int - number of students read in. */
int loadClassList(Student classList[], string input)
{
	ifstream inFile;       // get a stream variable
	inFile.open("input.txt"); // open the stream using our fileName param
	int i = 0;
	while (i<4)
	{
		inFile >> classList[i].fname >> classList[i].lname 
			>> classList[i].numGrades; 
		for (int j = 0; j < classList[i].numGrades; j++) //loop for grades
		{
			inFile >> classList[i].grades[j]; 
		}
		i++;
	}
	inFile.close(); //closes input file
	return i;
}
/*Function: printClassList
  Description:
	  Prints an array of students to stdout
Params:
	Student *classList : array of structs (and the structs are `Students`)
	  int     classSize  : size of class (returned from `loadClassList` )
Returns:
	 void */
void printClassList(Student classList[], int classSize)
{
	ofstream outFile;
	outFile.open("class_list.txt");
	outFile << "Erik Cuba\n" << '\n'
		<< "\tStudents\n" << "==================================\n"; //creates header

	for (int i = 0; i < classSize; i++) //loop to print classList array
	{
		outFile << classList[i].fname << " "
			<< classList[i].lname << ": ";
			for(int j = 0; j < classList[j].numGrades; j++) //loop to print grades
			{
				outFile << classList[i].grades[j] << "  ";
			}
			outFile << "\n";
	}
	outFile.close(); //closes output
}
