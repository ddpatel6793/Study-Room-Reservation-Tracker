#include "Room.h"
#include <iostream>
Room::Room(int roomNumber, int floorNumber, int capacity, std::string name, std::string type) :
	roomNumber{ roomNumber }, floor{ floorNumber }, capacity{ capacity }, isReserved{ false }, personInfo{ name, type } {
	//Room class constructor  (5 parameters)
}
Room::Room(int roomNumber, int floorNumber, int capacity, bool isReserved) : roomNumber{ roomNumber }, floor{ floorNumber }, capacity{ capacity }, isReserved{isReserved}
{
	// constructor overloaded (4 parameters)
}
Room::Room(int roomNumber, int floorNumber, int capacity) :
	roomNumber{ roomNumber }, floor{ floorNumber }, capacity{ capacity }, isReserved{ false } {
	//constructor overloaded (3 parameters + 1 isreserved initialized)
}

int Room::getRoomNumber() const {
	return roomNumber;
}
int Room::getCapacity() const {
	return capacity;
}
int Room::getFloor() const {
	return floor;
}
bool Room::getIsReserved() const {
	return isReserved;
}
void Room::setIsReserved(bool isAvailable) {
	isReserved = isAvailable;
}
Room::~Room() = default;
void Room::cancelReservation() {
	isReserved = false;
}
void Room::setPersonInfo(std::string name, std::string type) {
	personInfo.setName(name);
	personInfo.setStudentType(type);
}