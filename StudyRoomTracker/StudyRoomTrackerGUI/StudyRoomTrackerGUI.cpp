#include "StudyRoomTrackerGUI.h"
#include<QMessageBox>
#include <vector>
#include<iostream>
#include "ReservationManager.h"
StudyRoomTrackerGUI::StudyRoomTrackerGUI(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.viewAllRoomsButton, &QPushButton::clicked,
        this, &StudyRoomTrackerGUI::onViewAllRoomsClicked);
}

StudyRoomTrackerGUI::~StudyRoomTrackerGUI()
{}
void StudyRoomTrackerGUI::onViewAllRoomsClicked()
{
    std::vector<Room*> rooms = reservationManagerObject.getRooms();
    QString roomInformation;
    for (int i = 0; i < 12; i++) {
        auto roomNumber = QString::number(rooms[i]->getRoomNumber());
        auto floorNumber = QString::number(rooms[i]->getFloor());
        auto capacity = QString::number(rooms[i]->getCapacity());
        QString avability;
        if (rooms[i]->getIsReserved() == 1) {
            avability = "Not available";
        }
        else {
            avability = "available";
        }
        
        roomInformation = roomInformation + "Room Number: " + roomNumber + "\n"  + "FloorNumber: " + floorNumber + "\n" +  "Capacity: " + capacity + "\n" + "Avability: "+ avability + "\n";

        roomInformation=roomInformation+ "================================================\n";


        
    }
    
    
    QMessageBox::information(this, "Study Room Tracker", roomInformation);
}

