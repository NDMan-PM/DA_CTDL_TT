#include "DoThi.h"
#include "ThuatToan.h"
#include <iomanip>
#include <conio.h>
#include <iostream>
using namespace std;
typedef char thaotac[100];
thaotac tt[4] =
{
	" 1. Tim duong di ngan nhat bang Dijkstra ",
	" 2. Tim duong di ngan nhat bang Bellman-Ford  ",
	" 3. Thoat"

};
void chon(int chon);
void menu();

char  A[20] = "Test.inp";


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
		for (int i = 0; i < 3; i++)
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
			if (pos == 0) pos = 2; else pos--; break;
		}
		case 80:
		{
			if (pos == 2) pos = 0; else pos++; break;
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
    	cout << "\nNhap vi tri bat dau (1.." << n<< "): "; 
    	cin >> s; s--;
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
		cout <<"\n\nThuat toan Bellman-Ford:\n";
		cout << "Chon dinh xuat phat  (1.. "<< n <<"):";
		cin >>s; s--;
		BellmanFord(s,G,n);	
		getchar();	
		cout << "\nNhan phim Enter de tiep tuc lua chon!";
		break;
	}

	case 2:
	{
		cout << " DA THOAT !!!" << endl;
		exit(1);
		break;
	}
}
}
