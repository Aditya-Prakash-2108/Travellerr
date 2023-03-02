#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
class Graph
{
	// used for adjacency list
	unordered_map<string, vector<pair<string, int>>> g;

	int p = 0;

public:
	// Adding edges in the adjacency list
	void addEdge(string start, string end, int wt)
	{
		g[start].push_back({end, wt});
		g[end].push_back({start, wt});
	}

	int ShortestPath(string dep, string des)
	{
		string s = dep;

		unordered_map<string, int> dist;

		for (auto x : g)
			dist[x.first] = INT_MAX;

		unordered_map<string, bool> visited;

		for (auto x : g)
			visited[x.first] = false;

		dist[s] = 0;

		priority_queue<pair<int, string>> q;

		q.push({0, s});

		while (!q.empty())
		{

			string a = q.top().second;

			q.pop();

			if (visited[a])
				continue;

			visited[a] = true;

			for (auto u : g[a])
			{
				string b = u.first;
				int w = u.second;

				if (dist[a] + w < dist[b])
				{
					dist[b] = dist[a] + w;
					q.push({-1 * dist[b], b}); // multiply by -1 because default priority queue finds max distance and we need to find shortest path
				}
			}
		}

		return p = dist[des];
	}
	void Display(char d)
	{
		for (auto x : g)
		{
			string s = x.first;
			if (toupper(d) == s[0])
				cout << s << '\n';
		}
	}
	int Price(int sp, int ch)
	{
		if (ch == 1)
			return sp * 10;
		if (ch == 2)
			return sp * 15;
		if (ch == 3)
			return sp * 5;
		if (ch == 4)
			return sp * 3;
		return 0;
	}
};

int main()
{

	Graph g;
	string a, b;
	int w;
	// File Management
	ifstream infile;
	infile.open("data.txt"); //"demo.txt" is smaller file to check correctness of code
	if (infile.is_open())
	{
		cout << "File Successfully openned" << endl;
	}
	else
		cout << "Failed" << endl;
	string line, word;
	istringstream iss;
	while (!infile.eof())
	{
		int cnt = 0;
		// read line by line
		getline(infile, line);

		// read word by word
		iss.clear();
		iss.str(line);
		while (iss.good())
		{
			cnt++;
			iss >> word;
			if (cnt == 1)
				a = word;
			if (cnt == 2)
				b = word;
			if (cnt == 3)
			{
				stringstream s(word);
				s >> w;
				// w = word;
			}
		}
		g.addEdge(a, b, w);
	}
	infile.close();
	cout << "\t\t\t\t\t__________________________________________________________________\n";
	cout << "\t\t\t\t\t                     WELCOME TO goTrip\n";
	cout << "\t\t\t\t\t__________________________________________________________________";
	cout << "\n\n";
	cout << "Prese any key to continue...";
	getch();
	system("cls");
	cout << "\n------------------------------------------\n";
	cout << "  Enter First letter of Departure City";
	cout << "\n-------------------------------------------\n";
	char fde;
	cin >> fde;
	cout << "\n--------------------------------\n";
	cout << "\tList of all cities:" << '\n';
	g.Display(fde);
	cout << "--------------------------------\n\n";
	cout << "\n--------------------------------\n";
	cout << "   Enter Departure City: ";
	cout << "\n--------------------------------\n";
	string dep;
	cin >> dep;

	cout << "\n------------------------------------------\n";
	cout << "  Enter First letter of Destination City";
	cout << "\n------------------------------------------\n";
	char dest;
	cin >> dest;

	cout << "\n--------------------------------\n";
	cout << "\tList of all cities:" << '\n';
	g.Display(dest);
	cout << "\n--------------------------------\n\n";

	cout << "\n--------------------------------\n";
	cout << "   Enter Destination : ";
	cout << "\n--------------------------------\n";
	string des;
	cin >> des;

	int sp = g.ShortestPath(dep, des);

	cout << "Select choice of transport" << endl;
	cout << "\n--------------------------------\n";
	cout << "1. Bike\n";
	cout << "2. Cab\n";
	cout << "3. Train\n";
	cout << "4. Aeroplane\n";
	cout << "\n--------------------------------\n";

	int choice;
	cin >> choice;
	system("cls");
	
	cout << "\t\t-----------------YOUR goTrip TICKET----------------\n";
	cout << "\t===============================================================\n";
	cout << "\t\t\t    Booking Date: 23-05-2022\n";
	cout << "\t\t\t    	Best Route: " << sp << " Km" << endl;
	cout << "\t\t\t    	Total Fare: Rs." << g.Price(sp, choice) << endl;
	cout << "\t===============================================================\n";
	return 0;
}
// Graph to check correctness of code
// Graph-
//  		6     		2
//  chennai---------delhi--------goa
//  	|		    |	           |
//   2  |	       4|  	           |  9
//      |      	    | 	           |
//  indore---------mumbai--------hyderabad
//      	5	   	            2
