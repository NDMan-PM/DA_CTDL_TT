#define MAX 20
#define INF 1000000
typedef int MATRIX[MAX][MAX];
typedef MATRIX GRAPH;
typedef int VECTOR[MAX];
typedef VECTOR ARRAY;

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




void BellmanFord(int startnode,GRAPH G, int n)
//Tim ddnn tu dinh u den moi dinh khac
//p[j] la dinh truoc j tren ddnn
{
    fstream f;
    f.open("output_BF.txt", ios::out);
	int i,j,k,done;
	ARRAY p,D;
  for (i=0; i<n; i++) D[i]=INF; D[startnode]=0;
  for (i=0; i<n; i++) p[i]=i; 
  
  for (k=0; k<n; k++){
  	done=1;
  	for (i=0; i<n; i++) if (D[i]<INF)
  	  for (j=0; j<n; j++) if (G[i][j])
  	  	if (D[i]+G[i][j]<D[j]){
  	  	  D[j]=D[i]+G[i][j]; 
  	  	  p[j]=i;
  	  	  done=0;
	  }
	if (done)  break;
  }
	cout << "\nCac duong di:\n";
	for (int k=0; k<n; k++) if (k!=startnode)
    {
		i=k;
        cout << "Chi phi den nut "<< i+1 << ": " << D[k] << endl;
        f << D[k] << endl;
        cout << "Cach di: ";
		cout << i+1 <<"<--";
        f<< i+1 << " ";
		while (p[i]!=startnode){
		i=p[i];
		cout << i+1 << "<--";
        f << i+1 << " ";
		}
	cout << startnode+1 << endl;
    f << startnode+1 << endl;
    }
    cout << "\nKet qua da luu vao file output_BF.txt\n";    
}