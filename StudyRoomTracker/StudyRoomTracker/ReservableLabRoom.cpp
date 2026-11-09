#include<iostream>
#include"ReservableLabRoom.h"
#include "Room.h"
ReservableLabRoom::ReservableLabRoom(int number, int floor, int capacity)
: Room(number, floor, capacity) {
        // ReservableLabRoom class constructor body
}
std::string ReservableLabRoom::reserve(std::string name, std::string type) {
    if (type == "TA") {
        if (this->getIsReserved() == false) {
            setIsReserved(true);
            setPersonInfo(name, type);
            return "Room is reserved!\n";
        }
        else {
            throw std::runtime_error("room not available");
        }
    }
    else {
        throw std::runtime_error("room only for TA");
    }
}