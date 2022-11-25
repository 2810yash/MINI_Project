#include <iostream>
#include <graphics.h>
#include <windows.h>
#include <dos.h>
#include <conio.h>
#include <math.h>
#define MAX_DIGITS 10
using namespace std;

class Mini_project
{
public:
	void Intro();
	void Menu();
	void OR();
	void AND();
	void NOT();
	void NOR();
	void NAND();
	void Position();
	void Exit();
	void GetData();
	int DecBinary(int);
	int DecBinarya(int);
	// int main();
	void Converter(int, int, int, int, int, int, int);
	void Converter(int, int, int, int);
};

void Mini_project::GetData()
{
	POINT pos;
	int n, x1, y1;
	GetCursorPos(&pos);
	setbkcolor(COLOR(59, 58, 61));
	setcolor(WHITE);
	settextstyle(8, HORIZ_DIR, 5);
	outtextxy(300, 780, "Next");
	while (1)
	{
		GetCursorPos(&pos);
		if (GetAsyncKeyState(VK_LBUTTON))
		{
			x1 = pos.x;
			y1 = pos.y;
			if ((x1 > 308 && x1 < 412) && (y1 > 804 && y1 < 841))
			{
				Menu();
				break;
			}
		}
		else
		{
			n = 0;
		}
	}
};

void Mini_project::Intro() //	498	356
{
	cleardevice();
	readimagefile("Img/Intro.jpg", 0, 0, 700, 830);
	// outtextxy(10,780,"Next");
	GetData();
};

void Mini_project::Menu()
{
	cleardevice();
	readimagefile("Img/Menu.jpg", 0, 0, 700, 830);
	setbkcolor(COLOR(59, 58, 61));
	setcolor(WHITE);
	settextstyle(8, HORIZ_DIR, 5);
	outtextxy(10, 760, "Back");
	settextstyle(3, HORIZ_DIR, 1);
	outtextxy(15, 800, "(R_Button)");
	settextstyle(8, HORIZ_DIR, 5);
	Position();
};

void Mini_project::Converter(int n1, int n2, int ans, int num1, int num2, int bin, int ad)
{

	char n1_char[MAX_DIGITS + sizeof(char)];
	char n2_char[MAX_DIGITS + sizeof(char)];
	char ans_char[MAX_DIGITS + sizeof(char)];
	char num1_char[MAX_DIGITS + sizeof(char)];
	char num2_char[MAX_DIGITS + sizeof(char)];
	char bin_char[MAX_DIGITS + sizeof(char)];

	setbkcolor(COLOR(59, 58, 61));
	setcolor(WHITE);
	settextstyle(8, HORIZ_DIR, 5);
	outtextxy(245, 419, ":");
	settextstyle(8, HORIZ_DIR, 5);

	sprintf(n1_char, "%d", n1);
	sprintf(n2_char, "%d", n2);
	sprintf(ans_char, "%d", ans); // 1010
	sprintf(num1_char, "%d", num1);
	sprintf(num2_char, "%d", num2);
	sprintf(bin_char, "%d", bin);

	outtextxy(190, 245, n1_char); // 1010
	outtextxy(475, 245, n2_char); // 1010
	outtextxy(200, 420, ans_char);
	outtextxy(60, 560, num1_char);
	outtextxy(60, 640, num2_char);
	outtextxy(530, 595 + ad, bin_char);
	outtextxy(265, 420, bin_char);
	cout << "Operation is: " << ans_char << endl;

	// delay(1000);
};

void Mini_project::Converter(int n1, int ans, int num1, int bin)
{
	char n1_char[MAX_DIGITS + sizeof(char)];
	char ans_char[MAX_DIGITS + sizeof(char)];
	char num1_char[MAX_DIGITS + sizeof(char)];
	char bin_char[MAX_DIGITS + sizeof(char)];

	sprintf(n1_char, "%d", n1);
	sprintf(ans_char, "%d", ans);
	sprintf(num1_char, "%d", num1);
	sprintf(bin_char, "%d", bin);

	setbkcolor(COLOR(59, 58, 61));
	setcolor(WHITE);
	settextstyle(8, HORIZ_DIR, 5);

	outtextxy(190, 247, n1_char);
	outtextxy(170, 285, num1_char);
	outtextxy(475, 247, ans_char);
	outtextxy(455, 285, bin_char);
	outtextxy(60, 546, num1_char);
	outtextxy(530, 549, bin_char);
}

int Mini_project::DecBinary(int n)
{
	long long bin = 0;
	int rem, i = 1;

	while (n != 0)
	{
		rem = n % 2;
		n /= 2;
		bin += rem * i;
		i *= 10;
	}
	return bin;
	// delay(1000);
};

int Mini_project::DecBinarya(int num1)
{
	int binaryNum[32];
	int bn[32];
	int i, contnum = 0;
	i = 0;
	while (num1 > 0)
	{
		binaryNum[i] = num1 % 2;
		num1 = num1 / 2;
		// cout<<binaryNum[i];
		i++;
	}
	// cout<<endl;
	int p = 0;
	for (int a = i - 1; a >= 0; a--)
	{
		bn[p] = binaryNum[a];
		// cout<<bn[p];
		p++;
	}
	p = 0;
	// cout<<endl;
	for (int a = i - 1; a >= 0; a--)
	{
		if (bn[p] == 0)
		{
			bn[p] = 1;
		}
		else
		{
			bn[p] = 0;
		}
		// cout<<bn[p];
		p++;
	}
	for (int x = 0; x < i; x++)
	{
		contnum = contnum + (pow(10, i - x - 1) * bn[x]);
	}
	return (contnum);
};

void Mini_project::Position()
{
	POINT pos;
	int x1, y1;
	while (1)
	{
		GetCursorPos(&pos);
		if ((GetAsyncKeyState(VK_LBUTTON)))
		{
			x1 = pos.x;
			y1 = pos.y;
			if ((x1 > 216 && x1 < 500) && (y1 > 378 && y1 < 777))
			{
				break;
			}
		}
		else if (GetAsyncKeyState(VK_RBUTTON))
		{
			x1 = pos.x;
			y1 = pos.y;
			if ((x1 > 10 && x1 < 120) && (y1 > 787 && y1 < 818))
			{
				cout << "Back\n";
				Intro();
			}
		}
	}
	if ((x1 > 252 && x1 < 450) && (y1 > 396 && y1 < 438))
	{
		cout << "OR\n";
		cleardevice();
		readimagefile("Img/OR.jpg", 0, 0, 700, 830);
		outtextxy(10, 760, "Back");
		OR();
		Menu();
	}
	else if ((x1 > 231 && x1 < 470) && (y1 > 458 && y1 < 510))
	{
		cout << "AND\n";
		cleardevice();
		readimagefile("Img/AND.jpg", 0, 0, 700, 830);
		outtextxy(10, 760, "Back");
		AND();
		Menu();
	}
	else if ((x1 > 237 && x1 < 469) && (y1 > 523 && y1 < 577))
	{
		cout << "NOT\n";
		cleardevice();
		readimagefile("Img/NOT.jpg", 0, 0, 700, 830);
		outtextxy(10, 760, "Back");
		NOT();
		Menu();
	}
	else if ((x1 > 232 && x1 < 472) && (y1 > 595 && y1 < 639))
	{
		cout << "NOR\n";
		cleardevice();
		readimagefile("Img/NOR.jpg", 0, 0, 700, 830);
		outtextxy(10, 760, "Back");
		NOR();
		Menu();
	}
	else if ((x1 > 222 && x1 < 483) && (y1 > 656 && y1 < 704))
	{
		cout << "NAND\n";
		cleardevice();
		readimagefile("Img/NAND.jpg", 0, 0, 700, 830);
		outtextxy(10, 760, "Back");
		NAND();
		Menu();
	}
	else if ((x1 > 304 && x1 < 402) && (y1 > 726 && y1 < 767))
	{
		cout << "Exit\n";
		// readimagefile("Img/Intro.jpg", 0, 0, 700, 830);
		//	x1=0;
		//	y1=0;
		Exit();
		// delay(1000);
	}
};

void Mini_project::OR()
{
	int n1, n2, num1, num2, binans, ans = 0, x2, y2;
	POINT pos;
back:
	while (1)
	{
		GetCursorPos(&pos);
		if (GetAsyncKeyState(VK_LBUTTON))
		{
			x2 = pos.x;
			y2 = pos.y;
			if ((x2 > 10 && x2 < 120) && (y2 > 787 && y2 < 818))
			{
				Menu();
			}
			else
			{
				cout << "Enter number 1: ";
				cin >> n1;
				num1 = DecBinary(n1);
				cout << "Enter number 2: ";
				cin >> n2;
				num2 = DecBinary(n2);
				if (n1 > n2)
				{
					ans = n2 | n1;
					binans = DecBinary(ans);
				}
				else
				{
					ans = n1 | n2;
					binans = DecBinary(ans);
				}
				Converter(n1, n2, ans, num1, num2, binans, 0);
				// cout<<"OR operation is: "<<ans<<endl;
				// //delay(10000);
				goto back;
			}
		}
	}
};

void Mini_project::AND()
{
	int n1, n2, num1, num2, binans, ans = 0, x2, y2;
	POINT pos;
back:
	while (1)
	{
		GetCursorPos(&pos);
		if (GetAsyncKeyState(VK_LBUTTON))
		{
			x2 = pos.x;
			y2 = pos.y;
			if ((x2 > 10 && x2 < 120) && (y2 > 787 && y2 < 818))
			{
				Menu();
			}
			else
			{
				cout << "Enter number 1: ";
				cin >> n1;
				num1 = DecBinary(n1);
				cout << "Enter number 2: ";
				cin >> n2;
				num2 = DecBinary(n2);
				if (n1 > n2)
				{
					ans = n1 & n2;
					binans = DecBinary(ans);
				}
				else
				{
					ans = n2 & n1;
					binans = DecBinary(ans);
				}
				Converter(n1, n2, ans, num1, num2, binans, 0);
				goto back;
			}
		}
	}
};

void Mini_project::NOT()
{
	int num, ans, binnum, binans, bin, i, d;
	int x2, y2;
	POINT pos;
back:
	while (1)
	{
		GetCursorPos(&pos);
		if (GetAsyncKeyState(VK_LBUTTON))
		{
			x2 = pos.x;
			y2 = pos.y;
			if ((x2 > 10 && x2 < 120) && (y2 > 787 && y2 < 818))
			{
				Menu();
			}
			else
			{
				cout << "Enter a number: ";
				cin >> num;
				binnum = DecBinary(num);
				bin = DecBinarya(num);
				binans = bin;
				ans = 0;
				for (i = 0; bin != 0; ++i)
				{
					d = bin % 10;
					ans = (d) * (pow(2, i)) + ans;
					bin = bin / 10;
				}
				Converter(num, ans, binnum, binans);
				// delay(10000);
				goto back;
			}
		}
	}
};

void Mini_project::NOR()
{
	int n1, n2, num1, num2, binans, ans = 0, binnum, bin, i, d;
	int x2, y2;
	POINT pos;
back:
	while (1)
	{
		GetCursorPos(&pos);
		if (GetAsyncKeyState(VK_LBUTTON))
		{
			x2 = pos.x;
			y2 = pos.y;
			if ((x2 > 10 && x2 < 120) && (y2 > 787 && y2 < 818))
			{
				Menu();
			}
			else
			{
				cout << "Enter number 1: ";
				cin >> n1;
				num1 = DecBinary(n1);
				cout << "Enter number 2: ";
				cin >> n2;
				num2 = DecBinary(n2);
				if (n1 > n2)
				{
					ans = n2 | n1;
					binans = DecBinary(ans);
				}
				else
				{
					ans = n1 | n2;
					binans = DecBinary(ans);
				}
				binnum = binans;
				bin = DecBinarya(ans);
				binans = bin;
				ans = 0;
				for (i = 0; bin != 0; ++i)
				{
					d = bin % 10;
					ans = (d) * (pow(2, i)) + ans;
					bin = bin / 10;
				}
				Converter(n1, n2, ans, num1, num2, binans, 10);
				// delay(10000);
				goto back;
			}
		}
	}
};

void Mini_project::NAND()
{
	int n1, n2, num1, num2, binans, ans = 0, binnum, bin, i, d;
	int x2, y2;
	POINT pos;
back:
	while (1)
	{
		GetCursorPos(&pos);
		if (GetAsyncKeyState(VK_LBUTTON))
		{
			x2 = pos.x;
			y2 = pos.y;
			if ((x2 > 10 && x2 < 120) && (y2 > 787 && y2 < 818))
			{
				Menu();
			}
			else
			{
				cout << "Enter number 1: ";
				cin >> n1;
				num1 = DecBinary(n1);
				cout << "Enter number 2: ";
				cin >> n2;
				num2 = DecBinary(n2);
				if (n1 > n2)
				{
					ans = n1 & n2;
					binans = DecBinary(ans);
				}
				else
				{
					ans = n2 & n1;
					binans = DecBinary(ans);
				}
				binnum = binans;
				bin = DecBinarya(ans);
				binans = bin;
				ans = 0;
				for (i = 0; bin != 0; ++i)
				{
					d = bin % 10;
					ans = (d) * (pow(2, i)) + ans;
					bin = bin / 10;
				}
				Converter(n1, n2, ans, num1, num2, binans, 10);
				// delay(10000);
				goto back;
			}
		}
	}
};

void Mini_project::Exit()
{
	int exit=1;
	for (int i = 0; i < 830; i++)
	{
		readimagefile("Img/Intro.jpg", 0, 0 - i, 700, 827 - i);
		setfillstyle(SOLID_FILL, COLOR(59, 58, 61));
		bar(0, 830 - i, 700, 2000 - i);
		// i++;
	}
	settextstyle(6, HORIZ_DIR, 3);
	outtextxy(100, 415, "Press SPACE_BAR to exit the code");
	throw exit;
};

int main()
{
	Mini_project p;
	initwindow(700, 830, "Project", 0, 0);
	try{
		p.Intro();	
	}
	catch(int exit){
		getch();
		closegraph();
		cout<<"Thank You!"<<endl;			
	}

	return 0;
}
