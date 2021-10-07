#include "Bureaucrat.hpp"

Bureaucrat* newBureaucrat(std::string name, int grade) {
	try {
		return new Bureaucrat(name, grade);
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return NULL;
	}
}
int main(){
	Bureaucrat* inctest = newBureaucrat("inctest", 2);
	Bureaucrat* dectest = newBureaucrat("dectest", 147);
	Bureaucrat me(*inctest);

	std::cout << "===========INCREMENT TEST===========\n";
	try {
		me.incGrade();
		std::cout << me;
		me.incGrade();
		std::cout << me;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << me;
	std::cout << "===========DECREMENT TEST===========\n";
	try {
		dectest->decGrade();
		std::cout << *dectest;
		dectest->decGrade();
		std::cout << *dectest;
		dectest->decGrade();
		std::cout << *dectest;
		dectest->decGrade();
		std::cout << *dectest;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	delete inctest;
	delete dectest;

	std::cout << "\n\n";
	
	return (0);
}