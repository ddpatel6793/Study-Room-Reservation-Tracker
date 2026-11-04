#include <iostream>
#include "ReservationManager.h"

int main() {
	std::cout << "Welcome to study Room Reservation Tracker!\n\n";
	std::cout << "1. view All study Rooms\n";
	std::cout << "2. Reserve a study Room\n";
	std::cout << "3. Cancel a Reservation\n";
	std::cout << "4. Exit\n\n";
	std::cout << "Please enter the menu option: ";
	int menuOption;
	std::cin >> menuOption;
	std::cout << "\n\n";
	ReservationManager reservationManagerObject;
	while (menuOption != 4) {
		if (menuOption == 1) {
			reservationManagerObject.viewAllRooms();
		}
		else if (menuOption == 2) {
			std::cout << reservationManagerObject.reserveRoom(101, "Dhrusha", "TA") << "\n\n";
			std::cout << reservationManagerObject.reserveRoom(101, "Kirill", "TA") << "\n\n";
			std::cout << reservationManagerObject.reserveRoom(103, "Kirill", "Student") << "\n\n";

		}
		else {
			std::cout << " Sorry but we did not implement the 3rd task yet, which is cancel Reservation\n\n";
			break; //for now, after we implement for cancelReservation() method,
			          // we need to delete that line... 
		}
		std::cout << "Please enter the menu option: ";
		int menuOption;
		std::cin >> menuOption;
		std::cout << "\n\n";
	}
	
	return 0;
}