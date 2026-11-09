#include <iostream>
#include <fstream>
#include <string>
#include "PersonInformation.h"
#include "Room.h"

//TODO LATER: i know the file handling can be more robust and handle more specific errors in the future but im too lazy to implement that rn

class fileManager {
    private:
        int roomNumber;
        int capacity;
        bool isReserved;
        Person personInfo;
        int floor;

    public:
        // File constructor
        fileManager(int roomNumber, int capacity, bool isReserved, Person personInfo, int floor)
            : roomNumber(roomNumber), capacity(capacity), isReserved(isReserved), personInfo(personInfo), floor(floor) { }


        // Self explanatory name
        bool saveToFile(const std::string& filename) const {
            std::ofstream outFile(filename);
            if (!outFile.is_open()) {
                std::cerr << "Error: Could not open file for writing: " << filename << "\n";
                return false;
            }

            // writing le data
            outFile << roomNumber << "\n";
            outFile << capacity << "\n";
            outFile << isReserved << "\n";
            outFile << personInfo.getName() << "\n";
            outFile << personInfo.getStudentType() << "\n";
            outFile << floor << "\n";

            return true;
        }

        // again self explanatory lmao.
        bool loadFromFile(const std::string& filename) {
            std::ifstream inFile(filename);
            if (!inFile.is_open()) {
                std::cerr << "Error: Could not open file for reading: " << filename << "\n";
                return false;
            }
            if (inFile >> roomNumber >> capacity >> isReserved >> personInfo >> floor) {
                return true;
            }
            else {
                std::cerr << "Error: File format is invalid or reading failed.\n";
                return false;
            }
        }

};