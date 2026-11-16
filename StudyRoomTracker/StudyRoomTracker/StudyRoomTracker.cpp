#include <iostream>
#include "ReservationManager.h"
#include <string>
#include<exception>
#include "FileManager.h"
#include "rapidcsv.h"

int main() {
	std::cout << "Welcome to study Room Reservation Tracker!\n\n";
	std::cout << "1. view All study Rooms\n";
	std::cout << "2. Reserve a study Room\n";
	std::cout << "3. Cancel a Reservation\n";
	std::cout << "4. Exit\n\n";
	int menuOption = 0;
	int roomNumber;
	std::string studentType;
	std::string name;
	ReservationManager reservationManagerObject;

	
	while (true) {
		try {
			std::cout << "Please enter the menu option: ";
			std::cin >> menuOption;
			std::cout << '\n';
			if (std::cin.fail()) {
				std::cin.clear(); // resets the error state so input can work again. 
				std::cin.ignore(1000, '\n'); // removes unwanted characters remaining in the input buffer. 
				throw std::invalid_argument("Invalid argument");
			}
			
			
			if (menuOption > 4 || menuOption < 1) {
				
				throw std::invalid_argument("You did not choose the valid menu option. Try it again!\n");
			}
			std::cout << "\n\n";
		}
		catch (const std::invalid_argument& e) {
			std::cout << e.what() << "\n";
			continue;
		}
		
		if (menuOption == 1) {
			reservationManagerObject.viewAllRooms();
		}
		else if (menuOption == 2) {
			std::cout << "What room would you like to reserve?: ";
			std::cin >> roomNumber;
			try {
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(1000, '\n');
					throw std::invalid_argument("cannot except that data type");

				}
			}
			catch (const std::invalid_argument& e) {
				std::cout << e.what() << "\n";
			}
			std::cout << "What is your name?: ";
			std::cin.ignore();
			std::getline(std::cin, name);
			std::cout << '\n';
			std::cout << "Are you a student or TA? (Type 'Student' or 'TA'): ";
			std::cin >> studentType;
			std::cout << '\n';
			try {
				reservationManagerObject.reserveRoom(roomNumber, name, studentType);
				std::cout << "Room successfully reserved!\n";
			}
			catch (const std::runtime_error& e) {
				std::cout << "Sorry, your room could not be found. Error: " << e.what() << std::endl;
			}
			catch (...) {
				std::cout << "Sorry, but your room could not be reserved. You either had invalid input or tried to reserve an unavailable room.\n";
			}

		}
		else if (menuOption == 3) {
			try {
				std::cin.ignore();
				std::cout << "Please enter your name that you used when reserving the room: ";
				std::getline(std::cin, name);
				std::cout << '\n';
				std::cout << "Please enter the room number you reserved for: ";
				std::cin >> roomNumber;
				std::cout << '\n';
				std::cout<<reservationManagerObject.cancelingReservation(name, roomNumber)<<"\n";
				std::cout << "\n";
			}
			catch (const std::runtime_error& e) {
				std::cout << e.what() << "\n";
			}
			catch (const std::invalid_argument& e) {
				std::cout << e.what() << '\n';
			}
			catch (...) {
				std::cout << "Something went wrong\n";
			}
		}
		else if(menuOption == 4) {
			std::cout << "Thank You for using our program. You have a wonderful rest of the day!\n";
			break;
		}
		
		try {
			FileManager fileManagerObject(reservationManagerObject);
			fileManagerObject.writingToFile();
		}
		catch (const std::runtime_error& e) {
			std::cout << e.what() << '\n';
		}

		
	}
	
	
	
	return 0;
}