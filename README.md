# CirTrace

## Languages
- English
- [中文（简体）](README/README_zh-CN.md)


## Introduction
This brunch is in charge of SimonMihoyo and will be built by C++ and CMake.
My goal is to make a cross-platform CirTrace Level Editor in console mode.

## Build
1. Clone the repository.
```
git clone https://github.com/SimonMihoyo/CTE_Console.git
```
2. Build the project using CMake.
```
mkdir build
cd build
cmake ..
```

## Usage
To run the program,you can simply execute the binary file in the build directory.
```
./CTEConsole.exe
```
or
```
./CTEConsole
```
To Exit the program,press "ALT" + "F" and then "X".The Program will automatically save the level file unless you directly close the program.

Some command line options are available:

```
-h                     Show help message and exit.
-v                     Show version information and exit.
-l                     Enable logging to file.
-s                     Start in SAFE MODE.
-p                     Start in PLAYER MODE.
```

>SAFE MODE:
> - You can only view the level and interact with the level objects.
> - You CANNOT modify, save or delete any objects in the level.
> - The Program will Automatically recognize the level file downloaded form Internet and open them in SAFE MODE to prevent your computer form getting virus or hacked.

>PLAYER MODE:
> - If you want to start in PLAYER MODE,you need to have a level file specified with the -f option.
> - The level editor will automatically play the level as if you were playing it in the game.
> - You CAN ONLY modify some simple arguments such as offset, sound, screen size, etc.



## Supported Platforms
- Windows (10 or later)
- Linux (Only Tested on Ubuntu 24.04)
- macOS (11.3 or higher,and now tested and passed on M3 MacBook Air with macOS Sequoia 15.3.1)

## Least Compiler Requirements
C++ 20.

Visual Studio 2022 or gcc 11 or Xcode 13.

## For Old Systems
To Support some older versions of systems,you can go to following GitHub release page to look for Pre-built binaries for:(Although now the page is not exist.)
- Dos 6.22/7.10
- Windows 3/NT3
- Windows 95/98/ME/NT4
- Windows 2000/XP
- Windows vista/7/8/8.1
- Windows RT
- Mac OS X 10.0 - 10.5 (PPC)
- Mac OS X/OS X/macOS 10.6 - 11 (Intel)

## Third-Party Libraries
- *TinyXML2* : Copyright (c) 2000-2025, by Lee Thomason (www.grinninglizard.com). Licensed under the zlib license.