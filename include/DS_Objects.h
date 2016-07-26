/*
 * The Driver Station Library (LibDS)
 * Copyright (C) 2015-2016 Alex Spataru <alex_spataru@outlook>
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the Software
 * is furnished to do so, subject to the following conditions:
 *
 *  1. The above copyright notice and this permission notice shall be included in
 *     all copies or substantial portions of the Software.
 *
 *  2. THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 *     OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *     FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 *     THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *     LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *     FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 *     DEALINGS IN THE SOFTWARE.
 */

#ifndef _LIB_DS_OBJECTS_H
#define _LIB_DS_OBJECTS_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int socket;
    unsigned long address;
    unsigned short int type;
    unsigned short int input_port;
    unsigned short int output_port;
} DS_Socket;

typedef struct {
    char* (*fmsAddress)();
    char* (*radioAddress)();
    char* (*robotAddress)();

    char* (*fmsPacket)();
    char* (*radioPacket)();
    char* (*robotPacket)();

    bool (*readFmsPacket) (char* const data);
    bool (*readRadioPacket) (char* const data);
    bool (*readRadioPacket) (char* const data);

    void (*resetFMS)();
    void (*resetRadio)();
    void (*resetRobot)();

    void (*rebootRobot)();
    void (*restartRobotCode)();

    DS_Socket fmsSocket;
    DS_Socket radioSocket;
    DS_Socket robotSocket;
    DS_Socket netconsoleSocket;
} DS_Protocol;

#ifdef __cplusplus
}
#endif

#endif