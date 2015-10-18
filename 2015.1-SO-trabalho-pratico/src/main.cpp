#include "main.h"
#include "FCFS.h"
#include "RoundRobin.h"

// global variables
process p;
map<int,int> stateProcess; // key = process id, value = process date

//global functions
// external function for use sort
//bool dateCompare(a lhs, a rhs) { return lhs.num1 < rhs.num1; }
//bool durationCompare(a lhs, a rhs) { return lhs.num1 < rhs.num1; }


// function that reading input file data
vector<process> readingInputFileData(fstream &fileIn)
{

    int cont = 0, i = 1;
    vector<process> processVector;
    char caracter;

    // reading a text file
    while (fileIn.get(caracter))
    {

        if(caracter != 32 && cont < 3)      // reading the caracters: different of newline and space
        {
            // inserting the data of the current process
            if(cont==0) p.date = caracter-'0';
            if(cont==1) p.duration = caracter-'0';
            if(cont==2) p.priority = caracter-'0';
			cont++;
        }
        else if(caracter == '\n')           // reading the different caracters of newline and space
        {
			processVector.push_back(p);	// inserting the process in vector
            cont = 0;
        }
    }

	sort(processVector.begin(), processVector.end());

    // inserting in map
    for(vector<process>::iterator it = processVector.begin(); it != processVector.end(); it++ )
    {
        it->id = i;
        stateProcess[i] = it->date;
        i++;
    }

    return processVector;
}


int main(int argc, char* argv[])
{

    // rules
    if(argv[1] == NULL || argv[2] == NULL)
    {
        cout << ERROR1;
        cout << ERROR2;
        return 0;
    }

    // declaration of local variables
    string schedulingAlgorithm = argv[2];
	fstream fileIn;
	ofstream fileOut;

    fileIn.open(argv[1]);            // opening the input file
    fileOut.open("output.txt");      // creating the output file

    // open the file and running the algorithm chosen
    if(fileIn.is_open())
    {
        fileOut << "tempo   P1  P2  P3  P4" << endl;
        if(schedulingAlgorithm == FCFS)
            executeFCFS(readingInputFileData(fileIn), fileOut);	// function that runs the FCFS algorithm  (First Come, First Served)
        else if(schedulingAlgorithm == RR)
            executeRRWithoutPriority(readingInputFileData(fileIn), fileOut);	// function that runs the Round-Robin algorithm with quantum = 2s
        else
            cout << ERROR2;
        fileIn.close();
		fileOut.close();
    }
    else cout << ERROR3;

    return 0;
}
