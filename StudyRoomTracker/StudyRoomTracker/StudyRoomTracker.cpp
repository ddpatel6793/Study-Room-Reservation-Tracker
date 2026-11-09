#include <iostream>
#include "ReservationManager.h"
#include <string>
#include<exception>
#include "FileManager.h"

int main() {
	std::cout << "Welcome to study Room Reservation Tracker!\n\n";
	std::cout << "1. view All study Rooms\n";
	std::cout << "2. Reserve a study Room\n";
	std::cout << "3. Cancel a Reservation\n";
	std::cout << "4. Exit\n\n";
	int menuOption = 0;
	
	ReservationManager reservationManagerObject;
	try {
		std::cout << "Please enter the menu option: ";
		std::cin >> menuOption;
		if (menuOption > 4 || menuOption < 1) {
			throw std::invalid_argument("You did not choose the valid menu option. Try it again!\n");
		}
		std::cout << "\n\n";
	}
	catch (const std::invalid_argument& e) {
		std::cout << e.what() << "\n";
	}
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
		else if (menuOption == 3) {
			std::cout << " Sorry but we did not implement the 3rd task yet, which is cancel Reservation\n\n";
			break; //for now, after we implement for cancelReservation() method,
			// we need to delete that line... 
		}
		else if(menuOption == 4) {
			std::cout << "Thank You for using our program. You have a wonderful rest of the day!\n";
			break;
		}
		std::cout << "\nEnter the menu option: \n";
		std::cin >> menuOption;


		
	}
	try {
		FileManager fileManagerObject(reservationManagerObject);
		fileManagerObject.writingToFile();
	}
	catch (const std::runtime_error& e) {
		std::cout << e.what() << '\n';
	}
	
	return 0;
}