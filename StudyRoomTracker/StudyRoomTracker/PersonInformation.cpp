// PersonInformationClass: Composition class

#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    bool isTA;
public:
    Person() { //Non-parametric constructor. Assumes the person is not a TA
        name = "FGCUGuest";
        isTA = false;
    }

    Person(std::string& m_name, bool m_isTA) : name(m_name), isTA(m_isTA) {} //Create person. User-defined constructor

    //Get functions
    std::string getName() const { return name; }
    bool checkTA() const { return isTA; }

    //Set functions
    void setName(std::string& newName) { name = newName; }
    void setTA(bool status) { isTA = status; }

};
