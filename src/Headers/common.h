// CTE_Console common.h
// Copyright (C) 2025 SimonMihoyo
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

//All the common headers used in the project are included here.

#ifndef COMMON_H

//通用头文件
#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#include <vector>
#include <fstream>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>


//定义文件异常类型值
#define FILE_NOT_FOUND (-1)
#define FILE_READ_ERROR (-2)
#define FILE_WRITE_ERROR (-3)
#define FILE_FORMAT_ERROR (-4)
#define FILE_TOO_SMALL (-5)
#define JUST_SHOW_VERSION 2

//特定平台头文件

//Win32 平台
#ifdef _WIN32 || _WIN64
#include <windows.h>
#include <conio.h>

#include <ctime>
#define CLEAR_SCREEN system("cls")
#define PAUSE system("pause")

#endif

//Linux 平台
#ifdef __linux__
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#define CLEAR_SCREEN system("clear")
#define PAUSE system("read -n1 -s -p \"Press any key to continue...\"")
#endif

//Mac 平台
#ifdef __APPLE__
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>
#include <ncurses.h>
#define CLEAR_SCREEN system("clear")
#define PAUSE system("read -n1 -s -p \"Press any key to continue...\"")
#endif



#define COMMON_H

#endif //COMMON_H
