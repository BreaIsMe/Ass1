/*
Main file
Program name: CS330 assignment 1
Purpose: a shell program to mimic the terminal in the linux lab, 
		 should be able to run custom commands and linux commands
Creators: Kyle Callander (200252132) & Brea Monaghan (200339206)
*/

#include <string> //for strings
#include <cstring>
#include <iostream> //for input and output functions
#include <fstream> //used for input and output text files
#include "Header.h"
//#include "file_name"

using namespace std;

int main() {

	//used for functions
	int counter = 1; //used to display the number of commands entered on command line
	history historyList;
	char command[100] = "";
	string terminator = ">";
	string shellname = "toyshell";
	char delimeter[] = " ";
	//command aliases
	string CMDprogramEnd = "STOP";
	string CMDhistoryRep = "!" ;
	string CMDsetShell = "SETSHELLNAME";
	string CMDsetTerminator = "SETTERMINATOR";
	string CMDhistory = "HISTORY";
	string CMDaliasDisplay = "NEWNAMES";
	alias aliasList;

	char *token;
	int countertoken = 1;
	bool emptyCommandLine = true;
	string commandLine[MAX_TOKENS];
	string emptyStr = "";
	commandLine[0] = "";

/*
	//check if there are command to run to update shell from past uses
	1. import the file in to a variable
	2. call SAVES_CHECK function and send the file_name (as variable)
	3. continue with program, IF THE FILE IS EMPTY NOTHING SHOULD HAPPEN
*/

//main loop for the shell commands
	do {
		cout << shellname << "[" << counter << "]" << terminator;
		cin.getline(command, MAX_TOKENS);


		if (command[0] == NULL) {
			emptyCommandLine = false;
			cout << "This is empty" << endl; //Just displays to the terminal that there was nothing entered in the command line


		}
		else { //If there is something entered into the command line, proceeds to tokenize 
			//In the first call to strtok, the first argument is the line to be tokenized
			token = strtok(command, delimeter); // tokenizes 
			commandLine[0] = token; //Must initialize the 0 position first because the while loop in line 73 will not initilize the first.
			cout << endl;
			while ((token = strtok(NULL, delimeter)) != NULL)
			{
				commandLine[countertoken] = token; // ptr array is set
				countertoken++; //counter increased

			}
		}

		//HERE WE SHOULD SAVE COMMAND FOR HISTORY

		//checks if the command line is empty
		if (emptyCommandLine == false) {
			emptyCommandLine = true; //initilize emptyCommandLine back to True
			//nothing happens and the loop occur again
			//no increase to the counter will occur
		}
		//checks if it should break out of the loop
		else if (commandLine[0] == CMDprogramEnd) { //If STOP command is entered, stops shell
			break;
		}
		else if (commandLine[0] == CMDsetTerminator) { //If SETTERMINATOR command is entered, sets new terminator
			SETTERMINATOR(commandLine[1], terminator);
			counter++;
		}
		else if (commandLine[0] == CMDsetShell){
			SETSHELLNAME(commandLine[1], shellname);
			counter++;

		}
		//checks validity of command and executes it if possible
		else {
			counter++;
			//does not save the command yet if it is a HISTORYREPEAT command 
			if (commandLine[0] == CMDhistoryRep) {
				historyList.addnext(command); //saves the command in history before execution
				COMMANDEXECUTION(command, delimeter); // historyList, terminator, shellname, CMDprogramEnd, aliasList, CMDhistoryRep, CMDhistory, CMDaliasDisplay, CMDsetShell, CMDsetTerminator);
				counter++; //update counter
			}
			else { 
				COMMANDEXECUTION(command, delimeter);
					//, historyList, terminator, shellname, CMDprogramEnd, aliasList, CMDhistoryRep, CMDhistory, CMDaliasDisplay, CMDsetShell, CMDsetTerminator);;
				//historyList.addnext(command); //saves the command in history after execution
				counter++; //update counter
			}
			
			//execute function
		}

		//rebuild new command line
	} while (true);

	cout << endl; //for spaceing between the end of program and end program text
	return 0;
};