#include "main.h"
#include "RoundRobin.h"


void executeRRWithoutPriority(vector<process> processVector, ofstream &fileOut)
{

	int timeTotal = 1, currentTime = 0, vectorSize = processVector.size();

	while (!processVector.empty())
  	{
			// printing the header
			if(currentTime < 9)
				fileOut <<  " " << currentTime << "- " << timeTotal << "   ";
			else if(currentTime == 9)
				fileOut << " " << currentTime << "-" << timeTotal << "   ";
			else
				fileOut << currentTime << "-" << timeTotal << "   ";

            // printing the current state of all processes
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


            //updating the current state
			processVector.front().duration -= 1;
			if(timeTotal%2 == 0)
				processVector.front().date += timeTotal;
			timeTotal+=1;
			currentTime++;

            // updating the process vector
			if(processVector.front().duration < 1)
			{
				stateProcess[processVector.front().id] = INT_MAX; // current state finish
				processVector.erase(processVector.begin());		  // removing the current process vector
			}

			// ordering the vector by creation date
			sort(processVector.begin(), processVector.end());

  	}

}
