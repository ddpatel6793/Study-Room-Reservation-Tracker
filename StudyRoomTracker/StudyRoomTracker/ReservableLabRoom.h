#pragma once
#include<iostream>
#include "Room.h"
#include<string>
class ReservableLabRoom :public Room {
public:
	ReservableLabRoom(int number, int floor, int capacity);
	std::string reserve(std::string name, std::string type) override;
	std::string cancelReservation(std::string name)override;
	
        

};