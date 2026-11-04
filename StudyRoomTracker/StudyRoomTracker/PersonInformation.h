#pragma once
#include <string>

class Person {
private:
    std::string name;
    std::string studentType;
public:
    Person();
    Person(std::string m_name, std::string studentType);
    std::string getName() const;
    std::string getStudentType() const ;
    void setName(std::string newName);
    void setStudentType(std::string newType);
};
