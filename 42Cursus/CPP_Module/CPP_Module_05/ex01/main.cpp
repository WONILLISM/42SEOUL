#include "Form.hpp"

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
	Bureaucrat* IU = newBureaucrat("IU", 5);
	Bureaucrat* jieun = newBureaucrat("jieun", 2);
	Form form("application", false, 7, 15);
	Form copyForm = form;

	std::cout << "=============== FORM ===============\n";
	std::cout << copyForm << std::endl;
	
	std::cout << "============= IU FORM =============\n";
	std::cout << *IU;
	IU->signForm(copyForm);
	std::cout << copyForm;

	std::cout << "============= jieun FORM =============\n";
	std::cout << *jieun;
	jieun->signForm(copyForm);
	std::cout << copyForm;

	delete IU;
	delete jieun;

	return (0);
}