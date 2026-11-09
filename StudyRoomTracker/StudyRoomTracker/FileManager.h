#pragma once
#include "PersonInformation.h"
class fileManager {
    private:
        int roomNumber;
        int capacity;
        bool isReserved;
        Person personInfo;
        int floor;
    public:
        fileManager(int roomNumber, int capacity, bool isReserved, Person personInfo, int floor);
        bool loadFromFile(const std::string& filename);
        bool saveToFile(const std::string& filename);



};
