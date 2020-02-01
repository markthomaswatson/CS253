#include "TodoList.h"
#include <vector>
#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
TodoList::TodoList() {
	string filelocation = "list.txt";
	ifstream myfile;
	myfile.open(filelocation);
	if (myfile.is_open()) // If it worked write out the values
	{
		string day;
		string task;
		while (!myfile.eof()) {
			getline(myfile, day);
			getline(myfile, task);
			todoList.push_back(make_pair(day, task));
			//istringstream tempstream(line);
		}
		myfile.close();
	}
	else {
		// If the file open didnt work, print out an error
		cout << "Unable to open file \"" << filelocation << "\". Plase make sure that the file is in the correct location.";
	}
}
TodoList::~TodoList() {
	ofstream myfile;
	myfile.open("list.txt");
	for (unsigned int i = 0; i < todoList.size(); ++i) {
		myfile << todoList.at(i).first << endl << todoList.at(i).second;
		if (i != todoList.size() - 1) {
			myfile << endl;
		}
	}
	myfile.close();
}
void TodoList::add(string _duedate, string _task) {
	todoList.push_back(make_pair(_duedate, _task));
}
int TodoList::remove(string _task) {
	int count = 0;
	for (unsigned int i = 0; i < todoList.size(); ++i) {
		if (todoList.at(i).second == _task) {
			todoList.erase(todoList.begin() + i);
			count++;
		}
	}
	if (count > 0) {
		cout << "All instances of \"" << _task << "\" have been femoved from your TODO list." << endl;
		return 1;
	}
	else {
		cout << "\"" << _task << "\" is not an item in your TODO list. Nothing has been changed." << endl;
		return 0;
	}
}
void TodoList::printTodoList() {
	cout << "___TODO LIST ___" << endl;
	for (unsigned int i = 0; i < todoList.size(); ++i) {
		cout << todoList.at(i).first << endl;
		cout << todoList.at(i).second << endl;
	}
}
void TodoList::printDaysTasks(string _date) {
	cout << "TODO items for " << _date << ":" << endl;
	for (unsigned int i = 0; i < todoList.size(); ++i) {
		if (todoList.at(i).first == _date) {
			cout << todoList.at(i).second << endl;
		}
	}
}