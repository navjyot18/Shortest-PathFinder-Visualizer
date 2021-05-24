#include<graphics.h>
#include<iostream>
#include<bits/stdc++.h>
#include <algorithm>

using namespace std;
struct Node 
{
	vector<char> path;
	int weight;
};

void ListOfHospitals();
void PrepareCityArea();                          //It shows Graph of city
void ShortestPathAlgo();
void HighlightedShortestPath(vector<pair<int,int> >);
void result(char,char);

	vector<Node> CityArea[6];
	map<char,pair<int,int> > Coordinates;
	map<char,int> HospitalCode;

int main()
{
	
	std::cout<<"\n\t\t\t***********************************";
	std::cout<<"\n\t\t\t !!  Shortest PathFinder Visualizer   !!";
	std::cout<<"\n\t\t\t***********************************";
	std::cout<<"\n\n\t\t System built for quicker oxygen supply by following the shortest path  !!";
	std::cout<<"\n\n\n\n\n\t\t\t\t\tPress any key to continue....!!";

//	getch();

	
	initwindow(800,800,"The Window");
	
	settextstyle(20,0,10);
	//Edge weights
	outtextxy (30, 320, "Oxygen Supply");
	outtextxy (30, 340, "Center");
	outtextxy (650, 200, "8");
	outtextxy (150, 280, "30");
	outtextxy (150, 500, "40");
	outtextxy (450, 570, "50");
	outtextxy (450, 180, "45");
	outtextxy (280, 330, "75");
	outtextxy (410, 330, "70");
	outtextxy (500, 300, "60");
	outtextxy (570, 330, "11");
	
	//Designation of hospitals
	outtextxy (280, 130, "Hospital-A");
	outtextxy (580, 130, "Hospital-B");
	outtextxy (700, 340, "Hospital-C");
	outtextxy (580, 650,  "Hospital-D");
	outtextxy (280, 650,  "Hospital-E");
	
	//lines forming the graph
	
	line(300,200,600,600);
	line(600,200,300,600);
	line(50,400,300,200);
	line(50,400,300,600);
	line(300,200,600,200);
	line(300,600,600,600);
	line(300,200,300,600);
	line(600,200,600,600);
	line(600,200,750,300);
	setcolor(RED);
	setfillstyle(SOLID_FILL,BLUE);
	//printf("asdcfvgbh");
	
	circle(50,400,30);
	circle(300,200,30);
	circle(600,200,30);
	circle(300,600,30);
	circle(600,600,30);
	circle(750,300,30);

	floodfill(50,400,RED);
	floodfill(300,200,RED);
	floodfill(600,200,RED);
	floodfill(300,600,RED);
	floodfill(600,600,RED);
	floodfill(750,300,RED);


	

	int x1;
	std::cout<<"Press 1 to continue";
	std::cin>>x1;
	setcolor(GREEN);


	PrepareCityArea();
	ShortestPathAlgo();
	ListOfHospitals();

//	vector<pair<int,int> > v;
//	HighlightedShortestPath(v);
	getch();
	return 0;
}

void ShortestPathAlgo()
{
	// K no of vertices can be included from source i to destination j
	
	for(int k=0;k<6;k++)
	{
		// Pick all vertices as source one by one
		
		for(int i=0;i<6;i++)
		{
			// Pick all vertices as destination for the above picked source
			
			for(int j=0;j<6;j++)
			{
				// If vertex k is on the shortest path from i to j, then update the value of CityArea[i][j]
				
				if((CityArea[i][j].weight > CityArea[i][k].weight + CityArea[k][j].weight) && CityArea[i][k].weight!=INT_MAX && CityArea[k][j].weight!=INT_MAX)
				{
					CityArea[i][j].weight = CityArea[i][k].weight + CityArea[k][j].weight;
					
					int size= CityArea[i][j].path.size();
					
					CityArea[i][j].path.clear();
					CityArea[i][j].path=CityArea[i][k].path;
					CityArea[i][j].path.pop_back();
					CityArea[i][j].path.insert(CityArea[i][j].path.end(),CityArea[k][j].path.begin(),CityArea[k][j].path.end());
					
				} 
			}
		}		
	}
		
}
void PrepareCityArea()
{
	
	Coordinates['O']={50,400};
	Coordinates['A']={300,200};
	Coordinates['B']={600,200};
	Coordinates['C']={750,300};
	Coordinates['D']={600,600};
	Coordinates['E']={300,600};
	
	HospitalCode['O'] = 0;
	HospitalCode['A'] = 1;
	HospitalCode['B'] = 2;
	HospitalCode['C'] = 3;
	HospitalCode['D'] = 4;
	HospitalCode['E'] = 5;
	
	
	for(int i=0;i<6;i++)
	 CityArea[i].resize(6);
	
	CityArea[0][0].path={'O','O'};       CityArea[0][0].weight=0;
	CityArea[0][1].path={'O','A'};       CityArea[0][1].weight=30;
	CityArea[0][2].path={'O','B'};       CityArea[0][2].weight=INT_MAX;
	CityArea[0][3].path={'O','C'};       CityArea[0][3].weight=INT_MAX;
	CityArea[0][4].path={'O','D'};       CityArea[0][4].weight=INT_MAX;
	CityArea[0][5].path={'O','E'};       CityArea[0][5].weight=40;
	
	
	CityArea[1][0].path={'A','O'};       CityArea[1][0].weight=30;
	CityArea[1][1].path={'A','A'};       CityArea[1][1].weight=0;
	CityArea[1][2].path={'A','B'};       CityArea[1][2].weight=45;
	CityArea[1][3].path={'A','C'};       CityArea[1][3].weight=INT_MAX;
	CityArea[1][4].path={'A','D'};       CityArea[1][4].weight=70;
	CityArea[1][5].path={'A','E'};       CityArea[1][5].weight=75;
	
	
	CityArea[2][0].path={'B','O'};       CityArea[2][0].weight=INT_MAX;
	CityArea[2][1].path={'B','A'};       CityArea[2][1].weight=45;
	CityArea[2][2].path={'B','B'};       CityArea[2][2].weight=0;
	CityArea[2][3].path={'B','C'};       CityArea[2][3].weight=8;
	CityArea[2][4].path={'B','D'};       CityArea[2][4].weight=11;
	CityArea[2][5].path={'B','E'};       CityArea[2][5].weight=60;
	
	
	CityArea[3][0].path={'C','O'};       CityArea[3][0].weight=INT_MAX;
	CityArea[3][1].path={'C','A'};       CityArea[3][1].weight=INT_MAX;
	CityArea[3][2].path={'C','B'};       CityArea[3][2].weight=8;
	CityArea[3][3].path={'C','C'};       CityArea[3][3].weight=0;
	CityArea[3][4].path={'C','D'};       CityArea[3][4].weight=INT_MAX;
	CityArea[3][5].path={'C','E'};       CityArea[3][5].weight=INT_MAX; 
	
	
	CityArea[4][0].path={'D','O'};       CityArea[4][0].weight=INT_MAX;
	CityArea[4][1].path={'D','A'};       CityArea[4][1].weight=70;
	CityArea[4][2].path={'D','B'};       CityArea[4][2].weight=11;
	CityArea[4][3].path={'D','C'};       CityArea[4][3].weight=INT_MAX;
	CityArea[4][4].path={'D','D'};       CityArea[4][4].weight=0;
	CityArea[4][5].path={'D','E'};       CityArea[4][5].weight=50;
	
	
	CityArea[5][0].path={'E','O'};       CityArea[5][0].weight=40;
	CityArea[5][1].path={'E','A'};       CityArea[5][1].weight=75;
	CityArea[5][2].path={'E','B'};       CityArea[5][2].weight=60;
	CityArea[5][3].path={'E','C'};       CityArea[5][3].weight=INT_MAX;
	CityArea[5][4].path={'E','D'};       CityArea[5][4].weight=50;
	CityArea[5][5].path={'E','E'};       CityArea[5][5].weight=0;
	
	
	
}

void ListOfHospitals()
{
		
	//while(1)
	//{
		system("cls");
		
		cout<<"\n\n\tList of Centers : \n";
		cout<<"\t---------------------";
		cout<<"\n\n\t1. Oxygen Supply Center - O";
		cout<<"\n\t2. Hospital - A";
		cout<<"\n\t3. Hospital - B";
		cout<<"\n\t4. Hospital - C";
		cout<<"\n\t5. Hospital - D";
		cout<<"\n\t6. Hospital - E";
		
		char ch;
		char source,dest;
		cout<<"\n\n Do you want to continue further..?(Y/N)";
		cin>>ch;
		if(ch=='Y')
		{
			cout<<"\n\n\tEnter the source : ";
			cin>>source;
			cout<<"\tEnter the destination : ";
			cin>>dest;
			result(source,dest);
		}
		else
		 return;
	//}
}

void result(char source,char dest)
{
	
	int s=HospitalCode[source];
	int d=HospitalCode[dest];
	vector<char> v;
	v=CityArea[s][d].path;
	int size=v.size();

	vector<pair<int,int> > res;
	
	for(int i=0;i<size;i++)
	{
		res.push_back(Coordinates[v[i]]);
	}
	
	system("cls");
	cout<<size;
	//cout<<v;
	cout<<"\n\t\tThe shortest path from Hospital - "<<source<<" to Hospital - "<<dest<<" is as follow : \n";
	cout<<"\t\t";
	for(int i=0;i<size;i++)
	{
		cout<<v[i];
		if(i!=size-1)
		 cout<<" = > ";
	}
//	cout<<res;
//	getch();
	HighlightedShortestPath(res);
}

void HighlightedShortestPath(vector<pair<int,int> > res)
{
	
}
