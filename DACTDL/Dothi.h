#define MAX 20
#define INF 1000000
typedef int MATRIX[MAX][MAX];
typedef MATRIX GRAPH;

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void LayDuLieuTuFile(char *File, GRAPH &G, int &n)
{
  FILE *f = fopen(File, "rt");
	if (f == NULL){
		printf("Khong the mo File !!!");
	}
	fscanf(f, "%d", &n);
	for (int i = 0; i<n; i++)	{
		for (int j = 0; j<n; j++){
			fscanf(f, "%d", &(G[i][j]));
		}
	}

	cout << "Ma tran ke: " << n <<" x " << n << endl;
	for (int i = 0; i<n; i++){
		for (int j = 0; j<n; j++) cout <<  setw(4) << G[i][j];
        cout << endl;
	}
}

void KiemTraLienThong(GRAPH G, int n)
{
  int i,j,k;
  GRAPH b;
  
  for (i=0; i<n; i++)
	 for (j=0; j<n; j++) b[i][j]=G[i][j];
  
  for (i=0; i<n; i++) b[i][i]=1;
  
  for (k=0; k<n-1; k++)
    for (i=0; i<n; i++)
      for (j=0; j<n; j++)       
        {
          b[i][j]=b[i][j]||b[i][k]&&b[k][j];       
        }
  

    
 int check;
  for (i=0; i<n; i++)
    for (j=0; j<n; j++)
    {
      if (!b[i][j]) check = 0; break;
    }
// cout << "Kiem tra lien thong: ";  
// if (check) cout << "\nDo thi da nhap lien thong.";    
// else cout << "\nDo thi da nhap khong lien thong.";
}
