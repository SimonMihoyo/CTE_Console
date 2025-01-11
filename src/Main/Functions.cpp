// CTE_Console Functions.cpp
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

#include "../Headers/Functions.h"

using namespace  std;

// 打印版权信息
// 已完成，可以不动这个函数了
auto ShowCopyleft() -> void
{
    cout << "CirTrace Editor(Console) Copyright (C) 2024 SimonMihoyo.\n";
    cout << "This program comes with ABSOLUTELY NO WARRANTY; for details type `sw'.\n";
    cout << "This is free software, and you are welcome to redistribute it under certain conditions; type `sc' for details.\n";

    // 刷新屏幕
    const int sleep_milliseconds = 1000;
    this_thread::sleep_for(chrono::milliseconds(sleep_milliseconds));
}

