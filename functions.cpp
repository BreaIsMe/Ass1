#include "Header.h"

using namespace std;

/*string tokenize(string token, string tokens) {
	
	return token;
}
*/

/*Tokenize the Command line Example:
void TokenizeCommandLine(string tokens[], string commandLine) {
	char *token[MAX_TOKENS];
	char *workCommandLine = new char[commandLine.length + 1];

	for (int i = 0; i < MAX_TOKENS; i++) {
		tokens[i] = "";
	}

	strcpy(workCommandLine, commandLine.c_str()); //We will be using work command line to WORK with
	int i = 0;
	if ((token[i] = strtok(workCommandLine, " ")) != NULL) {
		i++;
		while ((token[i] = strtok(NULL, " ")) != NULL) {
			i++;
			}
	}

	int j = i;
	for (int i = 0; i < j; i++) {
		tokens[i] = token[i];
	}
	delete[] workCommandLine;
	return;
}
*/

/*
function purpose: to determin what command to execute based on the input given
paramaters:paramaters with CMD are used to compare in our if,
		command will be tokenized then used to help determine what should occure and what values are used
		the remaining paramaters used in specific functions
*/



/* Function 1 COMMANDPROMT

function purpose: to construct the command prompt
outputs: outputs the final constructed command line
inputs: gets the command from the user and returns it.
*/
char COMMANDPROMPT(int lineNum, string terminator, string shellname) {
	
	string SlineNum = to_string(lineNum); //converst the integer value to a string 
	string line = shellname + "[" + SlineNum + "]" + terminator; //constructs the command line
	char Command[MAX_TOKENS]; //used to save the command entered by the user

	//gets the command entered by the user
	cout << line; //outputs command line
	cin.getline(Command, MAX_TOKENS); //gets command from user
	cout << "Pass1" << endl;
	return Command[MAX_TOKENS];
};


/*Function 2 SETSHELLNAME     SETSHELLNAME <new_shell_name>

function purpose: give the user the ability to change the command prompt's shell name
output: confirmation that the shell name was changed
*/
void SETSHELLNAME(string newShell, string & shellname) {

	shellname = newShell; //updats the shellname 
	cout << "     Shellname changed" << endl;

	return;
};


/*Function 3 SETTERMINATOR    SETTERMINATOR <new_terminator>

function purpose: give the user the ability to change the command prompt's terminator
output: confirmation that the terminator was changed
*/
void SETTERMINATOR(string newTerminator, string & terminator) {

	terminator = newTerminator; //updates the terminator symbol
	cout << "     Terminator changed" << endl;

	return;
};


/*Function 4 HISTORY

function purpose: calls the .displayhistory function to display 10 most recent commands
*/
void HISTORY (history list) {
	
	list.displayhistory();

	return;
};


/*Function 5 HISTORYREPEAT    ! | <n>     (NOTE: <n> is stand in for a number)

function purpse: to re-execute one of the 10 most recent commands at a possition (poss) 

*/
string HISTORYREPEAT(int poss, history list) {

	if (poss <= list.size && poss > 0) {
		return list.cmd[poss-1];
	}
	
	cout << "     Error has occured"<<endl;
	return "ERROR";
};


/*Function 6 NEWNAME          <new_name> | <new_name> <old_name>

Manages a structure containing command aliases. The aliases should be stored in a
structure of size 10 (i.e., it can hold up to ten aliases). The first option deletes a
previously defined alias. The second option defines an alias for another command. For
example, the command NEWNAME mymove deletes the alias for mymove, and the
command NEWNAME mycopy cp defines mycopy as the alias for the cp command.
If an alias for a command already exists, then the new alias replaces the old alias.
*/
void NEWNAME() {
};//help


/*Function 7 ALIAS_SUB

Every command entered on the command line should be checked to determine whether it
is an alias by scanning the alias structure. When an alias is detected in a command,
the old name should be substituted into the command before the command is executed.
*/
void ALIAS_SUB() {

	return;
}//help


/*Function 8 NEWNAMES

function purpose: output all currently saved aliases
output: 1) displays all currently saved aliases with their original value
		2) displays an error messgae when an error occures
*/
void NEWNAMES(alias list) {
	
	//loops through the entire alias structure
	for (int x = 0; x < MAX - 1; x++) {
		//checks if an alias is saved at the x possition and displays it
		if (list.atAlias(x) != "ERROR" && list.atOriginal(x) != "ERROR" ||
			list.atAlias(x) != "" && list.atOriginal(x) != "") {
			cout << "Alias " << x + 1 << ": " << list.atAlias(x) << " for " << list.atOriginal(x) << endl;
		}
		//returns when the end of the filled portion of the structure is read
		else if (list.atAlias(x) == "" && list.atOriginal(x) == ""){
			return;
		}
		//when either an aliases has no original value or original value with no alias is found
		else { 
			cout << "     Unknown Error" << endl;
			return;
		}
	}

	//redundency for if an error occures
	cout << "     Unknown Error" << endl;
	return;
};


/*Function 9 SAVENEWNEAMES   SAVENEWNAMES <file_name>

function purpose: Stores all currently defined aliases in a file whose name is file_name.
output: displays an error messgae when an error occures
*/
void SAVENEWNAMES(alias list, string file_name) {
	
	ofstream myfile; //opens output stream variable
	myfile.open(file_name); //opens file in variable
	
	//loops through the entire structure to save all aliases in the file
	for (int x = 0; x < MAX - 1; x++) {
		//when there is a alias saved
		if (list.atAlias(x) != "ERROR" && list.atOriginal(x) != "ERROR" ||
			list.atAlias(x) != "" && list.atOriginal(x) != "") {
			//saved in the same structure as the command
			myfile << list.atAlias(x)<< " | " << list.atAlias(x)<< " " << list.atOriginal(x) << endl;
		}
		//if it is the end of the saved aliases 
		else if (list.atAlias(x) != "" && list.atOriginal(x) != "") {
			myfile.close(); //closes file
			return;
		}
		else { //when an error occured

			myfile.close(); //closes file
			cout << "     Unknown error" << endl;
			return;
		}
	}
	//only reaches here if the whole alias structure was filled and saved succesfully
	myfile.close();
	return;
}


/*Function 10 READNEWNAMES    READNEWNAMES <file_name>

Reads all aliases stored in the file whose name is file_name and adds them to the
aliases defined in the current session. If an alias in file_name already exists in
the alias structure (i.e., it is a duplicate), it should be ignored.

NEEDS TO BE LOOKED AT AND FIXED

*/
void alias::READNEWNAMES(string file_name) {
	string oldname;
	string newname;

	ifstream myfile;
	myfile.open(file_name);

	//inputs all aliases or until end of file
	while (!myfile.eof() ) {
		
		myfile >> newname; //gets first alias
		
		//determins the original name
		//oldname = newname.replace(newname.begin(), newname.end(), newname.substr(0, newname.find(" | ") - 1), ""); //help
		
		//determins the alias
		newname = newname.substr(0, newname.find(" | ")-1);

		//loops through array to insert new alias
		for (int x = 0; x < MAX - 1; x++) {

			//if there is a previous entry of an aliase it gets replaced
			if (original[x] == oldname) {
				newAlias[x] = newname; //saves new alias
			}
			//checks if an alias is being replaced 
			else if (newAlias[x] == oldname) {
				newAlias[x] = newname; //saves new alias
			}
			//if there is a free space with in the array
			else if (original[x] == "") {
				original[x] == oldname; //saves original command name
				newAlias[x] = newname; //saves alias name
				size++; //increases the size counter
			}
		}
	}
		myfile.close();
	return;
}


/*Function 11 LINUX_CHECK

function purpose: checks to see if a command is a linux command
*/
void LINUX_CHECK() {
	string cmd;//need tokenized string
	//system(cmd); //help

	return;
}


/*Function 12 SAVES_EXECUTE

checks to see if commands entered from a previous shell use have been saved and
re-executes them before anything else is done on the shell.
*/
void SAVES_EXECUTE(string file_name) {

	string command;
	ifstream myfile;
	myfile.open(file_name);

	while (!myfile.eof()) {
		
		getline(myfile, command);
		COMMANDEXECUTION(); //variables
		
	}

	return;
}


//function purpose: constructor for history
history::history() {
	size = 0;
	poss = 0;
	return;
};


//function purpose: adds the next value into the array
void history::addnext(string newCMD) {

	if (size == MAX - 1) { //ifthe array is at max capacity
		cmd[MAX - 1] = newCMD; //adds new value into the additional spot in array

		//shifts everything in the array 1 to the left to include the new value within the valid part of the array
		for (int x = 0; x < MAX - 1; x++) {
			cmd[x] = cmd[x + 1];
		}

	}
	else { //when the array is not yet full
		cmd[size] = newCMD;
		size++;
	}

	return;
};


//function purpose: 
void history::displayhistory() {

	int counter = 1; //used to display the order of command age

	//displays the commands from oldest to newest
	for (int x = 0; x < size; x++) { //display issues

		string display = to_string(counter) + ": " + cmd[x];
		cout << display << endl;
		counter++;
	}

	return;
};


//function purpose: 
alias::alias() {

	for (int x = 0; x < MAX-1; x++) {
		original[x] = "";
		newAlias[x] = "";
	}

	size = 0;
	return;
};


//function purpose: 
bool alias::aliasNext(string oldname, string newname) {
	
	//loops through array to insert new alias
	for (int x = 0; x < MAX-1; x++) {
		
		//if there is a previous entry of an aliase it gets replaced
		if (original[x] == oldname) {
			newAlias[x] = newname; //saves new alias
			cout << "     Insert Successful" << endl; //result sent to user
			return true; //returns true to signify that the insert was successful
		}
		//checks if an alias is being replaced 
		else if (newAlias[x] == oldname) {
			newAlias[x] = newname; //saves new alias
			cout << "     Insert Successful" << endl; //result sent to user
			return true; //returns true to signify that the insert was successful
		}
		//if there is a free space with in the array
		else if (original[x] == "") {
			original[x] == oldname; //saves original command name
			newAlias[x] = newname; //saves alias name
			cout << "     Insert Successful" << endl; //result sent to user
			return true;//returns true to signify that the insert was successful
		}
	}
	cout << "     Insert unsuccessful, max of 10 aliases reached" << endl; //result sent to user
	return false; //returns false to signify the insert did not happen
};


/*
function purpose: to search if an alias exists 
return value: anything other than -1 is the possition of the alias
*/
int alias::aliasSearch(string search) {

	for (int x = 0; x < MAX - 1; x++) {
		
		if (newAlias[x] == search) {
			return x; //returns the value 
		}
	}
	return -1;//returns -1 to signify that the alias was not found
};


/*
function purpose: returns the value at possition x of the alias value alias array
output: error when the value is outside the bounds
*/
string alias::atAlias(int poss) {
	if (poss > 0 && poss < MAX - 1){
		return newAlias[poss];
	}
	else {
		return "ERROR";
	}
}


/*
function purpose: returns the value at possition x of the original value alias array
output: error when the value is outside the bounds
*/
string alias::atOriginal(int poss) {
	
	if (poss > 0 && poss < MAX - 1) {
		return original[poss];
	}
	else {
		return "ERROR";
	}
}