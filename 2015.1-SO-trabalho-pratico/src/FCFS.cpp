#include "main.h"
#include "FCFS.h"

void executeFCFS(vector<process> processVector, ofstream &fileOut)
{
	int timeTotal = 1, currentTime = 0, vectorSize = processVector.size();

	while (!processVector.empty())
  	{ 
		// printing the current state of all processes
		if(currentTime < 9)
			fileOut <<  " " << currentTime << "- " << timeTotal << "   ";
		else if(currentTime == 9)
			fileOut << " " << currentTime << "-" << timeTotal << "   ";
		else
			fileOut << currentTime << "-" << timeTotal << "   ";
		for(int i = 1; i <= vectorSize; ++i)
		{
			if(processVector.front().id == i)
				fileOut << RUNNING << NOTHING;
			if(processVector.front().id != i && stateProcess.find(i)->second <= currentTime)
				fileOut << WAITING << NOTHING;
			if(processVector.front().id != i && stateProcess.find(i)->second > currentTime)
				fileOut << NOTHING << NOTHING;
		}
		fileOut << endl;

		processVector.front().duration -= 1;
		timeTotal+=1;
		currentTime++;

		if(processVector.front().duration < 1)
		{
			stateProcess[processVector.front().id] = INT_MAX; // current state finish
			processVector.erase(processVector.begin());		  // removing the current process vector 
		}
	}
}
