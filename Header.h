#include <string> //for strings
#include <iostream> //for input and output functions
#include <fstream> //used for input and output text files
//#include "file_name"
using namespace std;

int const MAX = 11;
const int MAX_TOKENS = 50;

class alias {
	private:
		string original[10];
		string newAlias[10];
		int size;
	public:
		alias();
		bool aliasNext(string, string); //returns true if element was added to the list
		int aliasSearch(string);
		string atAlias(int);
		string atOriginal(int);
		//Function 10 READNEWNAMES   READNEWNAMES <file_name>
		void READNEWNAMES(string); //maybe have file as argument, to read 
};

class history {
	public:
		string cmd [MAX];
		int size;
		int poss;
		history(); //default constructor
		void addnext(string);//adds the next value into the array
		void displayhistory(); //display for the history command

		
};

//string tokenize(string, string);



//void TokenizeCommandLine(string, string); see example


// Function 1 COMMANDPROMT
char COMMANDPROMPT(int, string, string);

//Function 2 SETSHELLNAME     SETSHELLNAME <new_shell_name>
void SETSHELLNAME(string, string&);

//Function 3 SETTERMINATOR    SETTERMINATOR <new_terminator>
void SETTERMINATOR(string, string&);

//Function 4 HISTORY
void HISTORY(history);

//Function 5 HISTORYREPEAT    ! | <n>     (NOTE: <n> is stand in for a number)
string HISTORYREPEAT(int, history);

//Function 6 NEWNAME          <new_name> | <new_name> <old_name>
string NEWNAME(string, string); //adds new alias

//Function 7 ALIAS_SUB
string ALIAS_SUB(string, string);

//Function 8 NEWNAMES
void NEWNAMES(alias);//displays all aliases

//Function 9 SAVENEWNEAMES   SAVENEWNAMES <file_name>
void SAVENEWNEAMES(alias, string); //maybe have file as argument, to save

//Function 10 READNEWNAMES   READNEWNAMES <file_name>
void READNEWNAMES(); //maybe have file as argument, to read 

//Function 11 LINUX_CHECK
void LINUX_CHECK(); //take tokenized string are argument

//Function 12 SAVES_EXECUTE
void SAVES_EXECUTE(string);//maybe have file as argument, to read and run previous commands