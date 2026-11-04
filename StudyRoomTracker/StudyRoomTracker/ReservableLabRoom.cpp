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
            return "Room is reserved!";
        }
        else {
            return "Sorry but the room is not available";
        }
    }
    else {
        return "Sorry this study room is only for teaching assistants";
    }
}