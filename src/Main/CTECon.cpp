// CTE_Console CTECon.cpp
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

#include "../Headers/tinyxml2.h"
#include "../Headers/CTECon.h"
#include "../Headers/Functions.h"

using namespace std;

auto TestTinyXML() -> void
{
    tinyxml2::XMLDocument doc;
    doc.LoadFile("PathHere");
    const char* ChartName = doc.FirstChildElement("CTEChart") -> FirstChildElement("Info") -> FirstChildElement("ChartName") -> GetText();
    cout << ChartName << endl;
    cout << "1" << endl;
}

// 主函数.
int main(const int argc,char* argv[])
{
    // string XMLPath;
    // cin >> XMLPath;
    TestTinyXML(); // 测试tinyxml2库
    // ShowCopyleft(); // 显示版权信息
    // //为了测试其他功能，先注释掉
    // if (argc != 1) //如果有命令行参数
    // {
    //      ProcessArgument(argc,argv);
    //
    // }
    //
    // ShowMenu();// 显示菜单
    // //ToUseQueue();
    // //MainLoop();

    return 0;
}

// 处理命令行参数
auto ProcessArgument(const int ArgCountNum,char* ArgVector[]) -> int
{
    for (int i = 1;i < ArgCountNum;i++) // 遍历命令行参数
    {
        if (strcmp(ArgVector[i],"-h") == 0 )
        {

           cout << "Help" ;
        }
        // -s Safe Mode参数
        else if (strcmp(ArgVector[i],"-s") == 0)
        {

           cout << "Safe Mode" ;
        }
        // -v 显示版本信息参数
        else if (strcmp(ArgVector[i],"-v") == 0)
        {
            CLEAR_SCREEN;

           cout << "CirTrace Level Editor Console ,Version 1.0.0.0 " ;

            exit(JUST_SHOW_VERSION); //退出程序
        }
        //判断-l选项目前有重大问题，暂时不使用
        /*/ else if (strcmp(ArgVector[i],"-l") == 0)
        // {
        //     cout <<"now in -l option" );
        // #ifdef _WIN32
        //     ShellExecuteA(nullptr,"open","cmd.exe","/c echo Hello World!",nullptr,SW_SHOWNORMAL);
        // #endif
        // #ifdef __linux__
        //     pid_t pid = fork();
        //     if (pid == 0)
        //     {
        //         OpenNewTerminal(); //打开新的终端
        //     }
        //     else if (pid > 0)
        //     {
        //         wait (nullptr);
        //     }
        //     else
        //     {
        //         perror("fork");
        //     }
        // #endif
        // #ifdef __APPLE__
        //     system("echo Hello World!");
        // #endif
        //
        // } */
        // 未知命令
        else
        {
            string Argvi = ArgVector[i];
            string UnknownCommand = "Unknown Command: " + Argvi + ". Ignore.";
           cout << UnknownCommand.c_str() << endl;
        }

    }
    return  0;
}

// 主循环
auto MainLoop() -> int
{

    return 0;
}




// 处理文件
auto ProcessFile( const string& FilePath) -> int
{
    //检测文件是否存在
    ifstream File(FilePath);
    if (!File.is_open())
    {
        string ErrorMessage = "Error: File not found: " + FilePath;
       cout << ErrorMessage.c_str() << endl;

        return FILE_NOT_FOUND;
    }
    //关闭文件
    File.close();
    // 打开文件以二进制模式读取
    ifstream file(FilePath, ios::binary);
    // 假设文件头的大小为 5 字节
    constexpr size_t headerSize = 5;
    vector<char> header(headerSize);
    // 读取文件头
    file.read(header.data(), headerSize);
    // 检查是否成功读取
    if (file.gcount() < headerSize)
    {
        string ErrorMessage = "Error: File too small: " + FilePath;
       cout << ErrorMessage.c_str() << endl;

        return FILE_TOO_SMALL;
    }
    // 定义两个可能的文件头内容
    const vector<char> headerOption1 = {0x63, 0x74, 0x6a, 0x74, 0x2e};
    const vector<char> headerOption2 = {0x63, 0x74, 0x6a, 0x66, 0x2e};

    // 检查文件头内容
    if (header == headerOption1)
    {
       cout << "网络文件，文件将在安全模式下打开\n" ;

        // 启用安全模式
        //EnableSafeMode();
        string contentpart = ReadFileData(FilePath);
        string content = contentpart + "";
       cout <<  content.c_str() << endl;
    }
    else if (header == headerOption2)
    {
       cout << "本地文件，是否信任此文件？(y/n)(默认n)\n" ;
        char answer;
        string Input;//等待用户输入
        getline(cin, Input);
        if (Input.empty()) //如果用户没有输入，默认选择否
        {
            answer = 'n';
        }
        else //如果用户输入了，读取第一个字符
        {
            answer = Input[0];
        }
        if (answer == 'y' || answer == 'Y') //如果用户选择信任
        {
            string contentpart = ReadFileData(FilePath);
            string content = contentpart + "";
           cout <<  content.c_str() << endl;

        }
        else //如果用户选择不信任
        {
           cout << "文件不被信任，将在安全模式下打开\n" ;
            EnableSafeMode(); // 启用安全模式
            string contentpart = ReadFileData(FilePath);
            string content = contentpart + "";
           cout <<  content.c_str() << endl;

        }
    }
    else
    {
       cout << "未知的文件头内容"  << endl;
    }
    // 关闭文件
    file.close();
    return 0;
}

// 处理帮助信息
auto ProcessHelp() -> int
{
   cout << "Help" << endl;
    return 0;
}

// 处理安全模式
auto ProcessSafeMode() -> int
{
   cout << "Safe Mode" << endl;
    return  0;
}

// 读取文件数据
auto ReadFileData(const string& FilePath) -> string
{
    // 打开文件以二进制模式读取
    ifstream file(FilePath, ios::binary);
    // 检查文件是否成功打开
    if (!file)
    {
        string ErrorMessage = "Error: File not found: " + FilePath;
       cout << ErrorMessage.c_str() << endl;

        return {ErrorMessage};
    }
    // 完整文件头大小为 256 字节
    constexpr size_t FullHeaderSize = 5;
    // 跳过文件头
    file.seekg(FullHeaderSize, ios::beg);
    // 读取剩余的文件数据
    string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    // 关闭文件
    file.close();
    // 返回文件数据
    return content;
}

// 启用安全模式（暂时未实现）
auto EnableSafeMode() -> bool
{
    return true;
}

//打开新的终端（仅限Linux，目前有重大Bug，暂时不使用）
/*/ auto OpenNewTerminal() -> void
// {
//     const char* terminals[] = {
//         "/usr/bin/gnome-terminal",
//         "/usr/bin/xterm",
//         "/usr/bin/konsole"
//     };
//     const char* args[][6] = {
//         {"gnome-terminal", "--", "sh", "-c", "echo Hello world!", nullptr},
//         {"xterm", "-e", "sh", "-c", "echo Hello world!", nullptr},
//         {"konsole", "-e", "sh", "-c", "echo Hello world!", nullptr}
//     };
//
//     for (int i = 0; i < sizeof(terminals) / sizeof(terminals[0]); ++i) //遍历可用的终端
//     {
//         if (access(terminals[i], X_OK) == 0)//如果终端可执行
//         {
//             if (const pid_t pid = fork();pid == 0)
//             {
//                 execv(terminals[i], (char* const*)args[i]);
//                 perror("execv");
//                 _exit(EXIT_FAILURE);
//             }
//             else if (pid > 0) //如果fork成功
//             {
//                 wait(nullptr);
//                 return;
//             }
//             else //如果fork失败
//             {
//                 perror("fork");
//             }
//             break; //如果找到了可用终端，就退出循环
//         }
//     }
//     //如果没有找到可用终端
//     cerr << "No supported terminal found." );
// }*/

// 显示菜单
auto ShowMenu() -> bool
{

    CLEAR_SCREEN;
    cout << "File   Edit   View   Tools   Window   Help" << endl;
    return true;
}



