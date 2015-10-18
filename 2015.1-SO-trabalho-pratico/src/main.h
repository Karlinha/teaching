#ifndef _MAIN_H_
#define _MAIN_H_

#include<iostream>
#include<fstream>
#include<queue>
#include<algorithm>
#include<map>
#include<climits>


#define FCFS "fcfs"
#define RR "rr"

#define ERROR1 "Write the FILE NAME in the first argument and\n"
#define ERROR2 "Write 'fcfs' or 'rr' in the second argument\n"
#define ERROR3 "Unable to open file\n"

#define RUNNING "##"
#define WAITING "--"
#define NOTHING "  "

using namespace std;


// struct that defines the process

struct process
{
	int date;
	int duration;
	int priority;
	int id;

	bool operator<(const process &p) const
	{
		return (date < p.date);
	}
};
extern process p;  
extern map<int,int> stateProcess;
#endif
