#include "Room.h"
#include <iostream>
Room::Room(int roomNumber, int floorNumber, int capacity) :
	roomNumber{ roomNumber }, floor{floorNumber}, capacity {capacity}, isReserved{ false } {
	//Room class constructor body

}

int Room::getRoomNumber() const {
	return roomNumber;
}
int Room::getCapacity() const {
	return capacity;
}
bool Room::getIsReserved() const {
	return isReserved;
}
Room::~Room() {
	std::cout << "Room object destroyed\n";
}
void Room::cancelReservation() {
	isReserved = false;
}