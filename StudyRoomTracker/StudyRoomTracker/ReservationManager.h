#pragma once
#include<vector>
#include"Room.h"
class ReservationManager {
	private:
		std::vector<Room*>rooms;
	public:
		ReservationManager() = default;
		void intalizeRooms();
};