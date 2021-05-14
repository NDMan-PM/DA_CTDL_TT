#define MAX 20
#define INF 1000000
typedef int MATRIX[MAX][MAX];
typedef MATRIX GRAPH;

#include <iostream>
using namespace std;

void Dijkstra(GRAPH G, int n,int startnode)

{
	int cost[MAX][MAX], distance[MAX], pred[MAX];
	int visited[MAX], count, mindistance, nextnode, i, j;
    fstream f;
    f.open("output_Dij.txt", ios::out);

	//pred[] luu cac dinh ma khoang cach ngan nhat tu no den dinh nguon
	//count dem so nut ma di qua den den dich
	//Tao ma tran trong so
	for (i = 0; i<n; i++)
		for (j = 0; j<n; j++)
			if (G[i][j] == 0)
				cost[i][j] = INF;
			else
				cost[i][j] = G[i][j];

	//Khoi tao mang pred[],distance[] and visited[]
	for (i = 0; i<n; i++)
	{
		distance[i] = cost[startnode][i];
		pred[i] = startnode;
		visited[i] = 0;
	}

	distance[startnode] = 0;
	visited[startnode] = 1;
	count = 1;

	while (count<n - 1)
	{
		mindistance = INF;

		//Nut ke tiep co khoang cach nho nhat
		for (i = 0; i<n; i++)
		{
			if (distance[i]<mindistance && !visited[i])
			{
				mindistance = distance[i];
				nextnode = i;
			}
		}

		//Kiem tra neu co duong dan tot hon: tinh lai khoang cach cac nut chua duoc tham      
		visited[nextnode] = 1;
		for (i = 0; i<n; i++)
			if (!visited[i])
				if (mindistance + cost[nextnode][i]<distance[i])
				{
					distance[i] = mindistance + cost[nextnode][i];
					pred[i] = nextnode;
				}
		count++;
	}

	//In ra duong di va khoang cach den moi nut
	// cout << "Cach di" << setw(10)<< "Chi phi";
	for (i = 0; i<n; i++)
		if (i != startnode)
		{
			cout <<"\nChi phi toi nut "<< i+1 << ": " << distance[i]; 
            f<< endl << distance[i] <<endl;
			cout <<"\nCach di: "<< i+1;;
            f << i+1 << " ";
			j = i;
			do
			{
				j = pred[j];
				cout <<"<--" << j+1;
                f << j+1 << " ";
			} while (j != (startnode));
		}
    cout << "\n\nKet qua da luu vao file output_Dij.txt\n";
    f.close();
}

void Dijkstra_p(GRAPH G, int n,int startnode)

{
	int cost[MAX][MAX], distance[MAX], pred[MAX];
	int visited[MAX], count, mindistance, nextnode, i, j;
    fstream f;
    f.open("output1_Dij.txt", ios::out);

	//pred[] luu cac dinh ma khoang cach ngan nhat tu no den dinh nguon
	//count dem so nut ma di qua den den dich
	//Tao ma tran trong so
	for (i = 0; i<n; i++)
		for (j = 0; j<n; j++)
			if (G[i][j] == 0)
				cost[i][j] = INF;
			else
				cost[i][j] = G[i][j];

	//Khoi tao mang pred[],distance[] and visited[]
	for (i = 0; i<n; i++)
	{
		distance[i] = cost[startnode][i];
		pred[i] = startnode;
		visited[i] = 0;
	}

	distance[startnode] = 0;
	visited[startnode] = 1;
	count = 1;

	while (count<n - 1)
	{
		mindistance = INF;

		//Nut ke tiep co khoang cach nho nhat
		for (i = 0; i<n; i++)
			if (distance[i]<mindistance && !visited[i])
			{

				mindistance = distance[i];
				nextnode = i;
			}

		//Kiem tra neu co duong dan tot hon: tinh lai khoang cach cac nut chua duoc tham      
		visited[nextnode] = 1;
		for (i = 0; i<n; i++)
			if (!visited[i])
				if (mindistance + cost[nextnode][i]<distance[i])
				{
					distance[i] = mindistance + cost[nextnode][i];
					pred[i] = nextnode;
				}
		count++;

}

	cout << "Nhap vao vi tri cuoi cung (1.."<< n << "): "; cin >> i; i--;
		if (i == startnode) cout << "Chi phi tu "<<i+1<<" den "<<i+1<< " la: 0";
		else
		{
			cout <<"\nChi phi toi nut "<< i+1 << ": " << distance[i]; 
            f<< endl << distance[i] <<endl;
			cout <<"\nCach di: " << i+1;
            f << i+1 << " ";
			j = i;
			do
			{
				j = pred[j];
				cout <<"<--" << j+1;
                f << j+1 << " ";
			} while (j != (startnode));
		}

    cout << "\n\nKet qua da luu vao file output1_Dij.txt\n";
    f.close();
}


void BellmanFord(int startnode,GRAPH G, int n)
{
    fstream f;
    f.open("output_BF.txt", ios::out);

	int P[MAX], L[MAX];
	for (int i=1; i<=n; i++)
	{
		P[i] = -1; // dinh ke truoc la rong khi khoi tao
		L[i] = INF; // khoi tao chuong trinh duong di ngan nhat den cac dinh la vo cung
	}

	L[startnode] = 0; // s la dinh ban dau
	for(int i=0; i <n;i++)
	{
		for (int u=0; u<n;u++)
		{ 
			for (int v=0; v<n; v++)
			{
				if(G[u][v] != 0 && L[u]+G[u][v] < L[v])
				{
					L[v]=L[u]+G[u][v];
					P[v] = u; 
				}
			}
		}
	}

	for(int v=0;v<n;v++)
	{
		if(v!=startnode)
		{
			if(L[v]==INF)
			{
				cout << "Khong ton tai duong di tu dinh " << startnode << " den dinh " << v <<endl;
			}
			else 
			{
				cout << "Chi phi den nut " << v << ": " << L[v] << endl;
				f <<endl<< L[v]<< endl;
				cout << "Cach di: " << v+1 << "<--";
				f << v+1 << " ";
				int k = P[v];
				while(k!= startnode)
				{	
					cout << k+1 << "<--";
					f << k+1 << " ";
					k = P[k];
				}
				cout << startnode+1 << endl << endl;
				f << startnode+1;
			}
		}
	}
	cout << "\nKet qua da luu vao file output_BF.txt\n";
}