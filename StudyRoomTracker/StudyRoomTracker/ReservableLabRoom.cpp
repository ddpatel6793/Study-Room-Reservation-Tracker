#include<iostream>
#include"ReservableLabRoom.h"
#include "Room.h"
#include<exception>
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
std::string ReservableLabRoom::cancelReservation(std::string name){
    if (name == this->getPersonName() &&  this->getIsReserved()==true){
        this->setPersonInfo("N/A", "N/A");
        this->setIsReserved(false);
        return "Room is canceled!";
    }
    else {
        throw std::invalid_argument("Invalid name or roomNumber");
        return "Invalid name or room number";
    }
   

}

