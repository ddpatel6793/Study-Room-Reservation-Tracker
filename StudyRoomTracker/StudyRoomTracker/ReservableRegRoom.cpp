#include"ReservableRegRoom.h"
#include "Room.h"
ReservableRegRoom::ReservableRegRoom(int number, int floor, int capacity)
    : Room(number, floor, capacity) {
    // ReservableRegRoom class constructor body
}
std::string ReservableRegRoom::reserve(std::string name, std::string type) {
    if (this->getIsReserved() == true) {
        return "Sorry but room is unavailable unavailable";
    }
    else {
        setIsReserved(true);
        setPersonInfo(name, type);
        return "Room Reserved!";
    }
}
