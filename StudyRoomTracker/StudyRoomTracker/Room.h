#pragma once
class Room { // Room abstract class , it has virtual methods
	private:
		int roomNumber; //stores 101, 102, 203, etc. 
		int floor; //stores floor numbers: 1,2,3
		int capacity; //how many students can it fit
		bool isReserved; //wther the room is occupied or reserved


	public:
		Room(int roomNumber, int floor, int capacity); //Room class constructor
		int getRoomNumber() const; //returns roomNumber
		int getFloor() const; //returns floor number
		int getCapacity() const; // returns capacity
		bool getIsReserved() const; // returns resrvation status
		virtual bool reserve() = 0; // virtual reservation function, with different rules in each derived class
		virtual void cancelReservation(); // cancels a valid reservation
		
		virtual ~Room(); // allows safe cleanup through a base pointer. 


};