#pragma once
#include<string>
#include "PersonInformation.h"
class Room { // Room abstract class , it has virtual methods
	private:
		int roomNumber; //stores 101, 102, 203, etc. 
		int capacity; //how many students can it fit
		bool isReserved; //wther the room is occupied or reserved
		Person personInfo;
		int floor; 


	public:
		Room(int roomNumber, int floor, int capacity,std::string name, std::string T); //Room class constructor
		int getRoomNumber() const; //returns roomNumber
		int getCapacity() const; // returns capacity
		int getFloor() const; 
		bool getIsReserved() const; // returns resrvation status
		virtual bool reserve() = 0; // virtual reservation function, with different rules in each derived class
		virtual void cancelReservation(); // cancels a valid reservation

		
		virtual ~Room(); // allows safe cleanup through a base pointer. 


};