#include <iostream>
#include <iomanip>
#include "Dothi.h"
#include "ThuatToan.h"

using namespace std;

int main()
{   
    int n,s;
    char  A[20] = "Test.inp";
    GRAPH G;
    LayDuLieuTuFile(A,G,n);
    KiemTraLienThong(G,n);
    cout << "\nNhap vi tri bat dau (1.." << n<< "): "; 
    cin >> s;
    Dijkstra(G,n,s);
}