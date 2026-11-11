#include <iostream>
#include <fstream>
#include <string>
#include "ReservationManager.h"
#include<stdexcept>
#include<vector>
#include "FileManager.h"
#include "rapidcsv.h"

FileManager::FileManager(ReservationManager& reservation_manager_object) :object{ reservation_manager_object } {
    //constructor body
}
void FileManager::writingToFile() {
    std::ofstream out("Study_room_tracker_data.csv", std::ios::trunc);
    if (!out) {
        throw std::runtime_error("Opening the file failed");
    }
    else {
        out << "RoomNumber,Floor,Capacity,IsReserved,StudentName,StudentType\n";
        for (int i = 0; i < rooms.size(); i++) {
            out << rooms[i]->getRoomNumber() << ", " << rooms[i]->getFloor() << ", " << rooms[i]->getCapacity() << ", " << rooms[i]->getIsReserved() << ", " << rooms[i]->getPersonName() << ", " << rooms[i]->getPersonType() << "\n";
            if (!out) {
                throw std::runtime_error("Writing Failure");
            }
        }
    }
    out.close();
}



// reading from the file
int roomNumber;
int floorNumber;
int capacity;
bool isReserved;
std::string studentName;
std::string studentType;

   

