//结伴作业 魔方 李奕辰 2016011331	黄可钊 2016011332	 
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
char F[3][3], B[3][3], L[3][3], R[3][3], U[3][3], D[3][3];
char m;
fstream fin;
void show_1(char array[3][3])//输出一个面的中心块的颜色和将读入的信息再以3 行 3 列的形式输出
{
	if (array[1][1] == '0' || array[1][1] == 'R') cout << "RED" << endl;
	else if (array[1][1] == '1' || array[1][1] == 'G') cout << "GREEN" << endl;
	else if (array[1][1] == '2' || array[1][1] == 'B') cout << "BLUE" << endl;
	else if (array[1][1] == '3' || array[1][1] == 'O') cout << "ORANGE" << endl;
	else if (array[1][1] == '4' || array[1][1] == 'W') cout << "WHITE" << endl;
	else if (array[1][1] == '5' || array[1][1] == 'Y') cout << "YELLOW" << endl;
	else cout << "文件并未打开" << endl;
	for (int i = 0; i <= 2; ++i)
		for(int j=0;j<=2;++j)
		{
			cout << array[i][j] << ' ';
			if (j == 2) cout << endl;
		 }
}
void show()//输出六个面的情况（前后左右上下）
{
	show_1(F);
	show_1(B);
	show_1(L);
	show_1(R);
	show_1(U);
	show_1(D);
}
void shuru_1(char array[3][3])//输入一个面的情况
{
	for (int i = 0; i <= 2; ++i)
		for (int j = 0; j <= 2; ++j)
		{
			fin >> array[i][j];
		}
}
void shuru()//输入六个面的情况（前后左右上下）
{
	shuru_1(F);
	shuru_1(B);
	shuru_1(L);
	shuru_1(R);
	shuru_1(U);
	shuru_1(D);
}
//12种转法
//********************************************************************************************
void R_()
{
	char f=R[0][1];
	R[0][1]=R[1][0];
	R[1][0]=R[2][1];
	R[2][1]=R[1][2];
	R[1][2]=f;
	char m=R[0][0];
	R[0][0]=R[2][0];
	R[2][0]=R[2][2];
	R[2][2]=R[0][2];
	R[0][2]=m;
	char x=U[1][2];
	U[1][2]=F[1][2];
	F[1][2]=D[1][2];
	D[1][2]=B[1][0];
	B[1][0]=x;
	char p=F[0][2];
	char q=F[2][2];
	F[0][2]=D[0][2];
	F[2][2]=D[2][2];
	D[2][2]=B[0][0];
	D[0][2]=B[2][0];
	B[2][0]=U[0][2];
	B[0][0]=U[2][2];
	U[0][2]=p;
	U[2][2]=q;		
}
void Ri_()
{
	for (int i = 1; i <= 3; ++i) R_();
}
void L_()
{
	char m = L[0][1];
	L[0][1] = L[1][0];
	L[1][0] = L[2][1];
	L[2][1] = L[1][2];
	L[1][2] = m;
	m = L[0][0];
	L[0][0] = L[2][0];
	L[2][0] = L[2][2];
	L[2][2] = L[0][2];
	L[0][2] = m;
	m = U[1][0];
	U[1][0] = B[1][2];
	B[1][2] = D[1][0];
	D[1][0] = F[1][0];
	F[1][0] = m;
	m = U[0][0];
	char n = U[2][0];
	U[0][0] = B[2][2];
	U[2][0] = B[0][2];
	B[2][2] = D[0][0];
	B[0][2] = D[2][0];
	D[0][0] = F[0][0];
	D[2][0] = F[2][0];
	F[0][0] = m;
	F[2][0] = n;
}
void Li_()
{
	for (int i = 1; i <= 3; ++i) L_();
}
void B_()
{
	m = U[0][2];
	U[0][2] = R[2][2];
	R[2][2] = D[2][0];
	D[2][0] = L[0][0];
	L[0][0] = m;
	m = U[0][1];
	U[0][1] = R[1][2];
	R[1][2] = D[2][1];
	D[2][1] = L[1][0];
	L[1][0] = m;
	m = U[0][0];
	U[0][0] = R[0][2];
	R[0][2] = D[2][2];
	D[2][2] = L[2][0];
	L[2][0] = m;
	m = B[0][2];
	B[0][2] = B[0][0];
	B[0][0] = B[2][0];
	B[2][0] = B[2][2];
	B[2][2] = m;
	m = B[0][1];
	B[0][1] = B[1][0];
	B[1][0] = B[2][1];
	B[2][1] = B[1][2];
	B[1][2] = m;
}
void Bi_()
{
	for (int i = 1; i <= 3; ++i) B_();
}
void D_()
{
	char _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20;
	_1 = F[2][0]; _2 = F[2][1]; _3 = F[2][2]; _4 = B[2][0]; _5 = B[2][1];
	_6 = B[2][2]; _7 = L[2][0]; _8 = L[2][1]; _9 = L[2][2]; _10 = R[2][0];
	_11 = R[2][1]; _12 = R[2][2]; _13 = D[0][0]; _14 = D[0][1]; _15 = D[0][2];
	_16 = D[1][0]; _17 = D[1][2]; _18 = D[2][0]; _19 = D[2][1]; _20 = D[2][2];
	F[2][0] = _7; F[2][1] = _8; F[2][2] = _9; B[2][0] = _10; B[2][1] = _11;
	B[2][2] = _12; L[2][0] = _4; L[2][1] = _5; L[2][2] = _6; R[2][0] = _1;
	R[2][1] = _2; R[2][2] = _3; D[0][0] = _18; D[0][1] = _16; D[0][2] = _13;
	D[1][0] = _19; D[1][2] = _14; D[2][0] = _20; D[2][1] = _17; D[2][2] = _15;
}
void Di_()
{
	for (int i = 1; i <= 3; ++i) D_();
}
void F_()
{
	m = U[2][0];
	U[2][0] = L[2][2];
	L[2][2] = D[0][2];
	D[0][2] = R[0][0];
	R[0][0] = m;
	m = U[2][1];
	U[2][1] = L[1][2];
	L[1][2] = D[0][1];
	D[0][1] = R[1][0];
	R[1][0] = m;
	m = U[2][2];
	U[2][2] = L[0][2];
	L[0][2] = D[0][0];
	D[0][0] = R[2][0];
	R[2][0] = m;
	m = F[0][1];
	F[0][1] = F[1][0];
	F[1][0] = F[2][1];
	F[2][1] = F[1][2];
	F[1][2] = m;
	m = F[0][0];
	F[0][0] = F[2][0];
	F[2][0] = F[2][2];
	F[2][2] = F[0][2];
	F[0][2] = m;
}
void Fi_()
{
	for (int i = 1; i <= 3; ++i) F_();
}
void U_()
{
	char _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20;
	_1 = F[0][0]; _2 = F[0][1]; _3 = F[0][2]; _4 = L[0][0]; _5 = L[0][1];
	_6 = L[0][2]; _7 = B[0][0]; _8 = B[0][1]; _9 = B[0][2]; _10 = R[0][0];
	_11 = R[0][1]; _12 = R[0][2]; _13 = U[0][0]; _14 = U[0][1]; _15 = U[0][2];
	_16 = U[1][0]; _17 = U[1][2]; _18 = U[2][0]; _19 = U[2][1]; _20 = U[2][2];
	F[0][0] = _10; F[0][1] = _11; F[0][2] = _12; L[0][0] = _1; L[0][1] = _2;
	L[0][2] = _3; B[0][0] = _4; B[0][1] = _5; B[0][2] = _6; R[0][0] = _7;
	R[0][1] = _8; R[0][2] = _9; U[0][0] = _18; U[0][1] = _16; U[0][2] = _13;
	U[1][0] = _19; U[1][2] = _14; U[2][0] = _20; U[2][1] = _17; U[2][2] = _15;
}
void Ui_()
{
	for (int i = 1; i <= 3; ++i) U_();
}
//**********************************************************************************************
int main()
{
	//读取配置文件
	fin.open("config.ini");
	if (!fin)
	{
		cout << "配置文件有问题" << endl;
		return 0;
	}
	string a;
	int num;
	int version = 999;
	//读取输入格式是digit 还是 ascii
	while (fin >> a)
	{
		if (a == "NAME")
		{
			num = 3;
		}
		--num;
		if (num == 0)
		{
			if (a == "digit")
				version = 1;
			else if (a == "ascii")
				version = 2;
			break;
		}
	}
	fin.close();
	fin.open("config.ini");
	string b;
	int sum=-99;
	int way = 999;
	//读取格式是一整行（9个）还是3*3
	while (fin >> b)
	{
		if (b == "DIM") sum = 3;
		--sum;
		if (sum == 0)
		{
			if (b == "1") way = 1;
			else if (b == "2") way = 2;
			break;
		}
	}
	fin.close();
	cout << "采用的是" << a << "的第" << b << "套方案" << endl;
	//读取输入文件并展示状态
	string c;
	cout << "请输入文件名" << endl;
	cin >> c;
	fin.open(c);
	if (!fin) cout << "输入文件打开失败" << endl;
	shuru();
	fin.close();
	show();
	string cm;
	//开始用户的操作
	while (true)
	{
		cout << "请输入指令 R Ri L Li B Bi D Di F Fi U Ui" << endl;
		cout << "或者输入非指令的字符来退出" << endl;
		cin >> cm;
		if (cm == "R") R_();
		else if (cm == "Ri")Ri_();
		else if (cm == "L")L_();
		else if (cm == "Li")Li_();
		else if (cm == "B")B_();
		else if (cm == "Bi")Bi_();
		else if (cm == "D")D_();
		else if (cm == "Di")Di_();
		else if (cm == "F")F_();
		else if (cm == "Fi")Fi_();
		else if (cm == "U")U_();
		else if (cm == "Ui")Ui_();
		else return 1;
		show();
	}
	return 0;
}
