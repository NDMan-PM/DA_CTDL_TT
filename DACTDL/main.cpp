#include "DoThi.h"
#include "Thuattoan.h"
#include <iomanip>
#include <conio.h>
#include <iostream>
#include <fstream> 
using namespace std;
typedef char thaotac[100];
thaotac tt[5] =
{
	" 1. Tim duong di ngan nhat bang Dijkstra ",
	" 2. Tim duong di ngan nhat bang Bellman-Ford  ",
	" 3. Tim duong di ngan nhat giua hai nut dung Dijkstra",
	" 4. Thoat"

};
void chon(int chon);
void menu();

char  A[20] = "Test1.inp";
char  B[20] = "Test2.inp";
int main()
{

	menu();
	return 0;

}
void menu()
{
	int pos = 0;
	while (1)
	{
		system("cls");
		static_cast<char> (3);
		cout << " \t//----------//----------//----------//----------//----------//----------//----------//----------//" << endl << endl;
		cout << "                                  DO AN MON HOC CAU TRUC DU LIEU VA THUAT TOAN                       " << endl;
		cout << "Lop: 18PFIEV3 " << endl;
		cout << "Ten sinh vien : NGUYEN DINH MAN  " << endl;
		cout << "                TRAN THE NAM  " << endl;
		for (int i = 0; i < 60; i++)     cout << "*";
		cout << "\n";
		cout << "   -----------   LUA CHON   -----------" << endl;
		cout << "(Su dung phim mui ten de dieu khien) " << endl;
		for (int i = 0; i < 4; i++)
		{
			if (i == pos) cout << tt[i] << "   <--- " << endl;
			else cout << tt[i] << endl;
		}
		int c;
		c = getch();
		switch (c)
		{
		case 72:
		{
			if (pos == 0) pos = 3; else pos--; break;
		}
		case 80:
		{
			if (pos == 3) pos = 0; else pos++; break;
		}
		case 13:
		{
			chon(pos);
			getch();
			 break;
		}
		}
	}
}
void chon(int chon)
{
	system("cls");
	switch (chon)
	{
	case 0:
	{
    	int n,s;
    	GRAPH G;

    	LayDuLieuTuFile(A,G,n);
    	KiemTraLienThong(G,n);
    	cout << "\nChon dinh xuat phat (1.." << n<< "): "; 
    	cin >> s;s--;
    	Dijkstra(G,n,s);
		cout << "\nNhan phim Enter de tiep tuc lua chon!";
		break;

	}
	case 1:
	{
		int i,n,s;
    	GRAPH G;
    	LayDuLieuTuFile(A,G,n);
    	KiemTraLienThong(G,n);
		cout << "Chon dinh xuat phat (1.."<< n <<"): ";
		cin >>s; s--;
		BellmanFord(s,G,n);	
		getchar();	
		cout << "\nNhan phim Enter de tiep tuc lua chon!";
		break;
	}

	case 2:
	{
    	int n,s;
    	GRAPH G;

    	LayDuLieuTuFile(B,G,n);
    	KiemTraLienThong(G,n);
    	cout << "\nNhap vi tri bat dau (1.." << n<< "): ";
		
		do {
			cin >> s;s--;
			if(s>=n) cout << "Vi tri bat dau khong hop le!" << "\nNhap lai vi tri bat dau (1.." << n<< "): ";		
		}
    	while(s>=n);

    	Dijkstra_p(G,n,s);
		cout << "\nNhan phim Enter de tiep tuc lua chon!";
		break;
	}
	case 3: 
	{
		cout << " DA THOAT !!!" << endl;
		exit(1);
		break;
	}
}
}
