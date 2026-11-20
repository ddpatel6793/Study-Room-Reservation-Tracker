#include"ReservableRegRoom.h"
#include "Room.h"
#include <iostream>
#include<string>
#include<exception>
ReservableRegRoom::ReservableRegRoom(int number, int floor, int capacity)
    : Room(number, floor, capacity) {
    // ReservableRegRoom class constructor body
}
std::string ReservableRegRoom::reserve(std::string name, std::string type) {
    if (this->getIsReserved() == true) {
        throw std::runtime_error("room not available");
    }
    else {
        setIsReserved(true);
        setPersonInfo(name, type);
        return "Room Reserved!\n";
    }
}
std::string ReservableRegRoom::cancelReservation(std::string name) {
    if (name == this->getPersonName() && this->getIsReserved() == true) {
        this->setPersonInfo("N/A", "N/A");
        this->setIsReserved(false);
        return "Room is canceled!";
    }
    else {
        throw std::invalid_argument("Invalid name or roomNumber");
        return "Invalid name or room number";
    }


}


/*
* std::string ReservableRegRoom::cancel(std::string name) {
    if (name == this->getName()) {
        if (this->getIsReserved() == true) {
            setIsReserved(false);
            setPersonInfo("N/A", "N/A");
            return "Reservation cancelled!\n";
        }
        else {
            throw std::runtime_error("This room wasn't previously reserved by you\n");
        }
    }
    else {
        throw std::runtime_error("You are not the person who made the reservation\n");
    }
}
*/