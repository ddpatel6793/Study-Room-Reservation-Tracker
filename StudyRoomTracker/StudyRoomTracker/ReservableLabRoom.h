#pragma once
#include<iostream>
#include "Room.h"
class ReservableLabRoom :public Room {
public:
	ReservableLabRoom(int number, int floor, int capacity);
	std::string reserve(std::string name, std::string type) override;

};