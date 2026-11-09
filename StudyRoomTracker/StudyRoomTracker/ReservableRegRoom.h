#pragma once
#include "Room.h"
#include <string>
class ReservableRegRoom:public Room {
	public:
		ReservableRegRoom(int number, int floor, int capacity);
		std::string reserve(std::string name, std::string type) override;

};