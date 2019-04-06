/* Aaron Shehan
Project 2: This program will use user input for salary, experience, and employee role to 
caclulate the total salary of each employee processed and the total company payout. */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main () 
{

char endProgram; 		       // used to continue or end do while loop
int totalExecutives = 0; 	      // used to count number of executives processed
int totalManagers = 0; 		     // used to count number of managers processed 
int totalStaff = 0; 		    // used to count number of staff processed
float totalPayout = 0;		   // for adding salarys together to get the company's total payout 
const int EXECBONUS = 10000; 	  // constant for executive bonus
const int MANAGERBONUS = 5000;	 // constant for manager bonus
const int STAFFBONUS = 1000; 	// constant for staff bonus

do // loop which will allow the user to repeatedly enter data
{

string fullName;  // employees full name
cout << "Enter full name: ";
getline(cin,fullName);

int Experience; // employee experience in years
cout << "Enter number of years experience: ";
cin >> Experience;

float Salary; 				//employee salary
cout << "Enter salary of the employee: ";
cin >> Salary;

int i = 0; // index number where capitalization will occur
int nameSize;
nameSize = fullName.size();

for (int x = 0; x < nameSize; ++x) 	//for loop to capitalize the first letter in a string and every letter after a white space
	{
		fullName.at(i) = toupper(fullName.at(i));
		i = fullName.find(" ", i) + 1;
	}

	
cout << "Enter the role of the employee:\n";
cout << "1. Executive\n" << "2. Manager\n" << "3. Staff\n";
	
int choice = 0; // for user input to select role of employee
enum {Executive = 1, Manager = 2, Staff = 3}; // used in the switch case to select employee role
		
while (choice != Executive && choice != Manager && choice != Staff) 
	{
	cin >> choice;
		switch (choice) 		// switch case used to select type of employee role 
		{
			case Executive:
				totalExecutives += 1; // counter for total number of executives processed
					if (Experience > 20) // if/else if statements using experience to calculate total salary of executive role
					{
						srand(time(NULL));
						Salary = (Salary/100) * ((rand() % 6) + 115) + EXECBONUS;
					}
					else if (Experience > 10 && Experience <= 20)
					{
						srand(time(NULL));
						Salary = (Salary/100) * ((rand() % 6) + 110) + EXECBONUS;
					}
					else if (Experience < 10)
					{
						srand(time(NULL));
						Salary = (Salary/100) * ((rand() % 6) + 105) + EXECBONUS;
					} 	
				break;
				
			case Manager:
				totalManagers += 1; // counter for total managers processed
					if (Experience > 20) // if/else if statements using experience to calculate total salary of manager role

					{
						srand(time(NULL));
						Salary = (Salary/100) * ((rand() % 6) + 110) + MANAGERBONUS;
					}
					else if (Experience > 10 && Experience <= 20)
					{
						srand(time(NULL));
						Salary = (Salary/100) * ((rand() % 6) + 105) + MANAGERBONUS;
					}
					else if (Experience < 10)
					{
						srand(time(NULL));
						Salary = (Salary/100) * ((rand() % 5) + 101) + MANAGERBONUS;
					} 
				break;

			case Staff:
				totalStaff += 1; // counter for total staff processed
					if (Experience > 20) // if/else if statements using experience to calculate total salary of staff role

					{
						srand(time(NULL));
						Salary = (Salary/100) * ((rand() % 6) + 105) + STAFFBONUS;
					}
					else if (Experience > 10 && Experience <= 20)
					{
						srand(time(NULL));
						Salary = (Salary/100) * ((rand() % 5) + 101) + STAFFBONUS;
					}
					else if (Experience < 10)
					{
						Salary = Salary + STAFFBONUS;
					} 

				break;

			default: // in this case the while loop will repeat
				cout << "Wrong role. Enter Again.\n"; // if user input for switch case is not 1, 2, or 3
		}
	}

cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);
cout << fullName << " obtained a total payout of $" << Salary << endl;

totalPayout += Salary; // adds salaries together after each iteration of the do while loop

cout << "Another employee? " << "Press N or n to stop, any other key to continue: ";
cin >> endProgram;
cin.ignore();
		
}
while ( endProgram != 'n' && endProgram != 'N'); // will end do while loop if user input is N or n

cout << "Total executives processed: " << totalExecutives << endl;
cout << "Total managers processed: " << totalManagers << endl;
cout << "Total staff processed: " << totalStaff << endl;

cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);
cout << "Total company payout: $" << totalPayout << endl;

return 0;
}
