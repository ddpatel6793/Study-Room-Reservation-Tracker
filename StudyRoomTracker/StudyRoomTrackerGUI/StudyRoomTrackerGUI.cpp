#include "StudyRoomTrackerGUI.h"
#include<QMessageBox>
#include <vector>
#include<iostream>
#include "ReservationManager.h"
#include<QInputDialog>
#include<string>
StudyRoomTrackerGUI::StudyRoomTrackerGUI(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.viewAllRoomsButton, &QPushButton::clicked,
        this, &StudyRoomTrackerGUI::onViewAllRoomsClicked);
    connect(ui.reserveRoomButton, &QPushButton::clicked, this, &StudyRoomTrackerGUI::onReserveRoomClicked);
    connect(ui.CancelReservationButton, &QPushButton::clicked, this, &StudyRoomTrackerGUI::onCancelReservationClicked);
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

void StudyRoomTrackerGUI::onReserveRoomClicked() {
    bool ok;
    int roomNumber = QInputDialog::getInt(this, "Reserve Room", "Enter the room number: ", 0, -2147483647, 2147483647, 1, &ok);
    if (!ok) {
        return;
    }
    //drop down choices instead of typing:
    QStringList studentTypes = { "Student", "TA" };
    QString studentType = QInputDialog::getItem(this, "Reserve Room", "Are you a Student or TA?", studentTypes, 0, false, &ok);
    if (!ok) {
        return;
    }
    QString studentName = QInputDialog::getText(this, "Reserve Room", "Enter your name: ", QLineEdit::Normal, "", &ok);
    if (!ok) {
        return;
    }
    std::string name = studentName.toStdString();
    std::string studenttype = studentType.toStdString();
    try {
        reservationManagerObject.reserveRoom(roomNumber, name, studenttype);
        QMessageBox::information(this, "Reservation Successful", "Room successfully reserved!");
    }
    catch (const std::exception& e) {
        QMessageBox::warning(this, "Reservation Failed", e.what());
       
    }
}
void StudyRoomTrackerGUI::onCancelReservationClicked() {
    bool ok;
    QString studentName = QInputDialog::getText(this, "Cancel Reservation", "Enter your name: ", QLineEdit::Normal, "", &ok);
    if (!ok) {
        return;
    }
    int roomNumber = QInputDialog::getInt(this, "Cancel Room", "Enter the room number: ", 0, -2147483647, 2147483647, 1, &ok);
    if (!ok) {
        return;
    }
    std::string regularName = studentName.toStdString();
    try {
        reservationManagerObject.cancelingReservation(regularName, roomNumber);
        QMessageBox::information(this, "Room reservation", "Cancelled Successfully");

    }
    catch (const std::exception& e) {
        QMessageBox::warning(this, "Reservation Failed", e.what());
    }
}
 
    


