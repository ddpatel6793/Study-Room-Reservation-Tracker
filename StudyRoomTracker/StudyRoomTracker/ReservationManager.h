#pragma once
#include<vector>
#include"Room.h"
#include "ReservableRegRoom.h"
#include "ReservableLabRoom.h"
class ReservationManager {
private:
	std::vector<Room*>rooms;
	//objects of reservableRegRoom
	ReservableRegRoom room201{ 201, 2, 5 };
	ReservableRegRoom room202{ 202, 2, 10 };
	ReservableRegRoom room203{ 203, 2, 5 };
	ReservableRegRoom room204{ 204, 2, 10 };
	ReservableRegRoom room301{ 301, 3, 5 };
	ReservableRegRoom room302{ 302, 3, 5 };
	ReservableRegRoom room303{ 303, 3, 10 };
	ReservableRegRoom room304{ 304, 3, 5 };
	//objects of reservableLabRoom
	ReservableLabRoom room101{ 101,1,5 };
	ReservableLabRoom room102{ 102,1,10 };
	ReservableLabRoom room103{ 103,1,5 };
	ReservableLabRoom room104{ 104,1,10 };


public:
	std::vector<Room*> getRooms() const;
	ReservationManager();
	void viewAllRooms();
	Room* findRoom(int roomNum);
	std::string reserveRoom(int roomNumber, std::string name, std::string type);
	std::string cancelingReservation(std::string name, int roomNumber);


};