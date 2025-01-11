// CTE_Console CTECon.h
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

#pragma once

#ifndef CTECON_H
#define CTECON_H

#include "common.h"


//命名空间(主要是懒得写std::前缀）
using namespace std;

//函数声明

//主循环
auto MainLoop () -> int;

//显示版权信息


//显示帮助信息
auto ProcessArgument(int ArgCount,char* ArgVector[]) -> int;

//处理命令行参数
auto ProcessSafeMode() -> int;

//处理帮助信息
auto ProcessHelp() -> int;

//处理文件
auto ProcessFile(const string& FilePath) -> int;

//检查文件头已被合并到ProcessFile中

//读取文件数据
auto ReadFileData(const string& FilePath) -> string;

//启用安全模式
auto EnableSafeMode() -> bool;

auto ShowMenu() -> bool;

//打开新的终端
//目前存在严重问题，暂时不使用
//auto OpenNewTerminal() -> void;



#endif //CTECON_H