#include <iostream>
#include <fstream>
#include <string>
#include "ReservationManager.h"
#include<stdexcept>
#include<vector>
#include "FileManager.h"
#include "rapidcsv.h"
#include "ReservableLabRoom.h"

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

void FileManager::readingFromFile() {
    try {
        rapidcsv::Document doc("Study_room_tracker_data.csv");
        rooms.clear(); //Prevent duplicates
        size_t rowCount = doc.GetRowCount();
        for (size_t i = 0; i < rowCount; ++i) {
            // Get individual info stuff
            int roomNumber = std::stoi(doc.GetCell<std::string>("RoomNumber", i));
            int floor = doc.GetCell<int>("Floor", i);
            int capacity = doc.GetCell<int>("Capacity", i);
            bool isReserved = doc.GetCell<bool>("IsReserved", i);
            std::string studentName = doc.GetCell<std::string>("StudentName", i);
            std::string studentType = doc.GetCell<std::string>("StudentType", i);
            Room* room = nullptr;
            if (floor == 1) {  //Must be a lab room
                room = new ReservableLabRoom(roomNumber, floor, capacity);
            }
            else { //All other rooms are regular
                room = new ReservableRegRoom(roomNumber, floor, capacity);
            }
            rooms.push_back(room);
        }
    }
    catch (const std::exception& e) {
        throw std::runtime_error(std::string("Reading from file failed: ") + e.what());
    }
}

// reading from the file
int roomNumber;
int floorNumber;
int capacity;
bool isReserved;
std::string studentName;
std::string studentType;

   

