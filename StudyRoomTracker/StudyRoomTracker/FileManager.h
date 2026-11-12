#pragma once
#include "PersonInformation.h"
class FileManager {
private:
    ReservationManager& object;
    std::vector<Room*> rooms = object.getRooms();

    public:
        FileManager(ReservationManager& reservation_manager_object);
        void writingToFile();
        void readingFromFile();

        //bool loadFromFile(const std::string& filename);
        //bool saveToFile(const std::string& filename);



};
