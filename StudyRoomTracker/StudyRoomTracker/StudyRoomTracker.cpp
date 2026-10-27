#include <iostream>
#include "ReservableRegRoom.h"



int main() {
	std::cout << "Welcome to study Room Reservation Tracker!\n";
	std::cout << "Floor 1 - Room 101 - Available\n";
	std::cout << "Floor 2 - Room 201 - Available\n";
	std::cout << "Floor 3 - Room 301 - Available\n";
	std::cout << "Wingless was here\n";

	std::cout << "Dhrusha: GitHub collaboration test successful!\n";

	ReservableRegRoom room101(101, 1, 5);
	std::cout << "Room Number: " << room101.getRoomNumber();


	return 0;
}