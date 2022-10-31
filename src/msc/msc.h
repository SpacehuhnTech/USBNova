/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#pragma once

#include <cstdint> // uint8_t
#include <cstddef> // size_t

namespace msc {
    bool init();
    bool format(const char* drive_name = "USB Nova");
    void print();

    void setID(const char* vid, const char* pid, const char* rev);
    void enableDrive();

    bool changed();
    bool exists(const char* filename);

    bool open(const char* path, bool add_to_stack = true);
    bool openNextFile();
    
    void close();

    uint32_t getPosition();
    void gotoPosition(uint32_t pos);

    size_t read(char* buffer, size_t len);
    size_t readLine(char* buffer, size_t len);
    bool getInLine();

    size_t write(const char* path, const char* buffer, size_t len);
}