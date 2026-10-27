#pragma once
#include "Room.h"
class ReservableRegRoom:public Room {
	public:
		ReservableRegRoom(int number, int floor, int capacity);
		bool reserve() override;

};