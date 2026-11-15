#include "ReservationManager.h"
#include <iostream>
#include <fstream>
#include<algorithm>
#include "Room.h"
#include "ReservableRegRoom.h"
#include "ReservableLabRoom.h"
#include "PersonInformation.h"

ReservationManager::ReservationManager() {
	rooms.push_back(&room201);
	rooms.push_back(&room202);
	rooms.push_back(&room203);
	rooms.push_back(&room204);
	rooms.push_back(&room301);
	rooms.push_back(&room302);
	rooms.push_back(&room303);
	rooms.push_back(&room304);
	rooms.push_back(&room101);
	rooms.push_back(&room102);
	rooms.push_back(&room103);
	rooms.push_back(&room104);
}
std::vector<Room*> ReservationManager::getRooms() const {
	return rooms;
}
// VIEWALLROOMS FUNCTION (TASK-1)
void ReservationManager::viewAllRooms() {
	std::cout << "VIEW ALL STUDY ROOMS\n";
	std::cout << "=======================\n";
	for (int i = 0; i < rooms.size(); i++) {
		std::cout << "Room Number: " << rooms[i]->getRoomNumber() << "\n";
		std::cout << "Floor Number: " << rooms[i]->getFloor() << "\n";
		std::cout << "Capacity: " << rooms[i]->getCapacity() << "\n";
		if (rooms[i]->getRoomNumber() == 101 || rooms[i]->getRoomNumber() == 102 || rooms[i]->getRoomNumber() == 103 || rooms[i]->getRoomNumber() == 104) {
			std::cout << "Room Type: Teacher Assistant study room\n";
		}
		else {
			std::cout << "Room Type: Regular study room\n";
		}
		if (rooms[i]->getIsReserved() == false) {
			std::cout << "Availability: Available\n";
		}
		else {
			std::cout << "Availability: Unavailable\n";
		}
		std::cout << "\n\n";
	}
}

// RESERVEROOM() (METHOD FOR TASK-2)
std::string ReservationManager::reserveRoom(int roomNumber, std::string name, std::string type) {
	Room* objectOfRoom = findRoom(roomNumber);
	if (objectOfRoom != nullptr) {
		std::string reservationMessage = objectOfRoom->reserve(name, type);
		return reservationMessage;
	}
	else {
		throw std::runtime_error("Room not found");

	}
}

// Cancel method
std::string ReservationManager::cancelRoom(int roomNumber, std::string name) {
	Room* objectOfRoom = findRoom(roomNumber);
	if (objectOfRoom != nullptr) {
		std::string reservationMessage = objectOfRoom->cancel(name, type);
		return reservationMessage;
	}
	else {
		throw std::runtime_error("Room not found");

	}
}

//findRoom() method:
Room* ReservationManager::findRoom(int roomNum) {

	auto findingRoom = std::find_if(rooms.begin(), rooms.end(), [roomNum](Room* room) {
		return room->getRoomNumber() == roomNum;
		});
	if (findingRoom != rooms.end()) {
		return *findingRoom;
	}
	else {
		return nullptr;
	}
}




