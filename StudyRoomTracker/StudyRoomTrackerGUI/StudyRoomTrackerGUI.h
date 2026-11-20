#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_StudyRoomTrackerGUI.h"
#include "ReservationManager.h"

class StudyRoomTrackerGUI : public QMainWindow
{
    Q_OBJECT

public:
    StudyRoomTrackerGUI(QWidget *parent = nullptr);
    ~StudyRoomTrackerGUI();

private slots:
    void onViewAllRoomsClicked();
    void onReserveRoomClicked();
    void onCancelReservationClicked();

private:
    Ui::StudyRoomTrackerGUIClass ui;
    ReservationManager reservationManagerObject;
    
};

