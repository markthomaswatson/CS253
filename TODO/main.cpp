#include "TodoList.h"
#include "TodoListInterface.h"
#include <string>
#include <iostream>
#include <algorithm>

string DAYS[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

int main(int argc, char **argv) {
    string args[argc];
// 	cout << argc << endl;
// 	for (int i = 0; i < argc; ++i) {
// 		cout << "argv[" << i << "] = " << argv[i] << endl;
// 	}
	TodoList td;
	for(unsigned int i = 0; i < argc; ++i){
	    string s(argv[i]);
	    args[i] = s;
	}
	if (argc == 4 && args[1] == "add" && find(DAYS, DAYS+7, args[2]) != end(DAYS)) {
		td.add(args[2], args[3]);
	}
	else if (argc == 3 && args[1] == "remove") {
		td.remove(argv[2]);
	}
	else if (argc == 2 && args[1] == "printList") {
		td.printTodoList();
	}
	else if (argc == 3 && args[1] == "printDay" && find(DAYS, DAYS + 7, args[2]) != end(DAYS)) {
		td.printDaysTasks(args[2]);
	}
	else {
		cout << "Invalid selection of arguments. Try again." << endl;
	}
	return 0;
}