#include <iostream>
#include "ReservationManager.h"
#include <string>

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
			std::cout << "What room would you like to reserve?: ";
			int room;
			std::cin >> room;
			std::cout << "What is your name?: ";
			std::string name;
			std::cin >> name;
			std::cout << "Are you a student or TA? (Type 'Student' or 'TA'): ";
			std::string studentType;
			std::cin >> studentType;
			try {
				reservationManagerObject.reserveRoom(room, name, studentType);
				std::cout << "Room successfully reserved";
			}
			catch (const std::runtime_error& e) {
				std::cout << "Sorry, your room could not be found. Error: " << e.what() << std::endl;
			}
			catch (...) {
				std::cout << "Sorry, but your room could not be reserved. You either had invalid input or tried to reserve an unavailable room.\n";
			}

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