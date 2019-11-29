#pragma once
#include "iostream"
#include "windows.h"
class Print {
private:
	int div;
	int menuNum;
	int start;
public:
	Print() {
		div = 3;
		menuNum = 2;
		start = 0;
	}
	/*
		int division() 返回的结果对应菜单1/2/3
	*/
	void Menu1() {
		system("cls");
		cout << endl;
		cout << endl;
		cout << "\t\t\t*********************************************************************" << endl;
		cout << "\t\t\t*                     最小生成树模拟程序                            *" << endl;
		cout << "\t\t\t*                                                                   *" << endl;
		cout << "\t\t\t*         这段区域可以显示出一个设计好的无向连通网络                *" << endl;
		cout << "\t\t\t*                                                                   *" << endl;
		cout << "\t\t\t*                                                                   *" << endl;
		cout << "\t\t\t*       1、普里姆（Prim）算法构造最小生成树                         *" << endl;
		cout << "\t\t\t*       2、克鲁斯卡尔（Kruscal）算法构造最小生成树                  *" << endl;
		cout << "\t\t\t*       3、退出											  *" << endl;
		cout << "\t\t\t*                                                                   *" << endl;
		cout << "\t\t\t*********************************************************************" << endl;
	}
	void solveExamine(int offset)
	{
		bool flag1 = true;
		while (flag1)
		{
			for (int i = 49; (i <= 49 + offset) && flag1; i++)
				if (GetAsyncKeyState(i) & 1== 1)
				{
					flag1 = false;
					div = i;
				}
			Sleep(20);
		}
	}

	int division() {
		while (1) {
			Menu1();
			solveExamine(menuNum);
			if ((div == '1')||(div == '2')||(div=='3')) {
				return div;
			}
		}
		return -1;
	}
};