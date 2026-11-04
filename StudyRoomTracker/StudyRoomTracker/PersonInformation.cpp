// PersonInformationClass: class for composition relationship

#include <iostream>
#include <string>
#include "PersonInformation.h"

Person::Person(std::string name, std::string type) :
	name{ name }, studentType{ type } {
}
Person::Person() : name{ "" }, studentType{ "" } {}
std::string Person::getName() const{
	return name;
}
std::string Person::getStudentType() const {
	return studentType;
}
void Person::setName(std::string newname) {
	name = newname;
}
void Person::setStudentType(std::string newType) {
	studentType = newType;
}
