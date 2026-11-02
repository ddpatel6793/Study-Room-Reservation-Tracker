#pragma once
#include <string>

class Person {
private:
    std::string name;
    bool isTA;
public:
    Person();
    Person(std::string& m_name, bool m_isTA);
    std::string getName() const;
    bool checkTA() const ;
    void setName(std::string newName);
    void setTA(bool status);
};
