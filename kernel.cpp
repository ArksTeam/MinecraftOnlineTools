#include <iostream>
/*
多玩我的世界盒子 2nd 项目组.
多玩我的世界联机盒子 C++ 核心模块.
*/
using namespace std;
const string IP = "154.12.37.196";
const string port = "9622";
const string DHCPport = "2032";
const bool DHCP = false;
// 当无法自动获取组IP的时候请将此项设为真
string url = IP + port;
string cmd;
string DHCPR = IP + DHCPport;

string returnCommand() {
// 制作N2N启动指令
	if (DHCP) {
		cmd = "edge -d edge0 -r -a " + DHCPR + " -c minecraft -k 1024 -l " + url + " -v -f";
	} else {
		cmd = "edge -d edge0 -c minecraft -k 1024 -l " + url + " -v -f";
	}
	return cmd;
}

void nextLine(int max) {
	for (int i = 0; i < max; i++) {
		cout << endl;
	}
}

int main() {
	string commands = returnCommand();
	system("color 3e&title Onlinebox Core.");
	cout << "多玩我的世界联机盒子 C++ Core 基于n2n." << endl;
	cout << "By: BlocksTeam, Github:https://github.com/VoxelsTeam" << endl;
	nextLine(2);
	system(commands.c_str()); // 使用 c_str() 函数将 string 转换为 const char*
	nextLine(2);
	cout << "客户端已结束运行,按回车键关闭。" << endl;
	system("pause>nul");
	return 0;
}
// Make minecraft great again!
