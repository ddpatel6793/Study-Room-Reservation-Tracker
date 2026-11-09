#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_StudyRoomTrackerGUI.h"

class StudyRoomTrackerGUI : public QMainWindow
{
    Q_OBJECT

public:
    StudyRoomTrackerGUI(QWidget *parent = nullptr);
    ~StudyRoomTrackerGUI();

private:
    Ui::StudyRoomTrackerGUIClass ui;
};

