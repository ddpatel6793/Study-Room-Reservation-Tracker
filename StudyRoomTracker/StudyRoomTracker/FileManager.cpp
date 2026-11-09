#include <iostream>
#include <fstream>
#include <string>
#include "ReservationManager.h"
#include<stdexcept>
#include<vector>
#include "FileManager.h"

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
   // std::string name; 
    //std::string personType;

    //bool input(const std::string& filename) {
       // std::ifstream inFile(filename);
       // if (!inFile.is_open()) {
          //  std::cerr << "Error: Could not open file for reading: " << filename << "\n";
           // return false;
       // }
        //if (inFile >> roomNumber >> capacity >> isReserved >> name>>personType >> floor) {
           // return true;
       // }
        //else {
           // std::cerr << "Error: File format is invalid or reading failed.\n";
           // return false;
        //}
 //   }

