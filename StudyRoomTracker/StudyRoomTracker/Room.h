#pragma once
#include<string>
#include "PersonInformation.h"
class Room { 
	private:
		int roomNumber;
		int capacity; 
		bool isReserved; 
		Person personInfo;
		int floor; 



	public:
		Room(int roomNumber, int floorNumber, int capacity,std::string name, std::string type); //Room class constructor
		Room(int roomNumber, int floorNumber, int capacity, bool isReserved);
		Room(int roomNumber, int floorNumber, int capacity);
		int getRoomNumber() const; 
		int getCapacity() const; 
		int getFloor() const; 
		bool getIsReserved() const; 
		virtual std::string reserve(std::string name, std::string type) = 0; 
		virtual std::string cancelReservation(std::string name) = 0;
		void setIsReserved(bool isAvailable); 
		void setPersonInfo(std::string name, std::string type);
		std::string getPersonName();
		std::string getPersonType();
		virtual ~Room(); 


};