#pragma once
#include "iostream"
#include "windows.h"
class Print {
private:
	int div;
	int menuNum;
	int start;
	Print() {
		div = 3;
		menuNum = 3;
		start = 0;
	}
public:
	/*
		int division() ���صĽ����Ӧ�˵�1/2/3
	*/
	void Menu1() {
		system("cls");
		cout << endl;
		cout << endl;
		cout << "\t\t\t*********************************************************************" << endl;
		cout << "\t\t\t*                     ��С������ģ�����                            *" << endl;
		cout << "\t\t\t*                                                                   *" << endl;
		cout << "\t\t\t*         ������������ʾ��һ����ƺõ�������ͨ����                *" << endl;
		cout << "\t\t\t*                                                                   *" << endl;
		cout << "\t\t\t*                                                                   *" << endl;
		cout << "\t\t\t*       1������ķ��Prim���㷨������С������                         *" << endl;
		cout << "\t\t\t*       2����³˹������Kruscal���㷨������С������                  *" << endl;
		cout << "\t\t\t*       3���˳�                                         *" << endl;
		cout << "\t\t\t*                                                                   *" << endl;
		cout << "\t\t\t*********************************************************************" << endl;
	}
	void Menu2() {
		cout << "\t\t\t*********************************************************************" << endl;
		cout << "\t\t\t*                     ��С������ģ�����                            *" << endl;
		cout << "\t\t\t*                                                                   *" << endl;
		cout << "\t\t\t*       ������ʼ�ص�                                       *" << endl;
		cout << "\t\t\t*                                                  *" << endl;
		cout << "\t\t\t*                                                                   *" << endl;
		cout << "\t\t\t*********************************************************************" << endl;
	}
	void solveExamine(int offset)
	{
		bool flag1 = true;
		while (flag1)
		{
			for (int i = 49; (i <= 49 + offset) && flag1; i++)
				if (GetAsyncKeyState(i) & 1 == 1)
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
			if (div == 1) {
				Menu2();
				cin >> start;
				cout << "\t\tstart ==" << start << endl;
			}
			else if (div == 2) {
				;
			}
			else if (div == 3) {
				exit(1);
			}
			else return -1;
			return div;
		}
	}
};