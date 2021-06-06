//============================================================================
// Name        : Assignment_5.cpp
// Author      : Aditya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define inf 999999

class node {
	string data;
	node* next;
public:
	node(string s) {
		data = s;
		next = NULL;
	}
	friend class Graph;
};

class Graph {
	int **G;
	int n;
	node* head;
public:
	Graph() {
		head = NULL;
		cout << "Enter number of vertices: ";
		cin >> n;
		G = new int*[n];
		for (int i = 0; i < n; i++) {
			G[i] = new int[n];
		}
	}
	void read();
	int posn(string);
	void add(string);
	void prim();
	void temp();
};

int Graph::posn(string s) {
	node* p = head;
	int cnt = 0;
	while (p != NULL && p->data != s) {
		cnt++;
		p = p->next;
	}
	return cnt;
}

void Graph::add(string s) {
	if (head == NULL) {
		head = new node(s);
		return;
	}
	node* p = head;
	node* q;
	int flag = 0;
	while (p != NULL && p->data != s) {
		q = p;
		flag = 1;
		p = p->next;
	}
	if (flag = 1) {
		q->next = new node(s);
	}
}

void Graph::read() {
	string u, v;
	int w;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			G[i][j] = 0;
		}
	}
	while (1) {
		cout << "Source: ";
		cin.ignore(1);
		getline(cin, u);
		if (u == "stop") {
			return;
		}
		add(u);
		cout << "Target: ";
		getline(cin, v);
		add(v);
		cout << "Cost: ";
		cin >> w;
		G[posn(u)][posn(v)] = w;
		G[posn(v)][posn(u)] = w;
	}
}

void Graph::prim() {
	int mincost = 0;
	int *visited, *dist, *from;
	visited = new int[n];
	dist = new int[n];
	from = new int[n];
	visited[0] = 1;
	dist[0] = inf;
	from[0] = 0;
	int **cost = new int*[n];
	for (int i = 0; i < n; i++) {
		cost[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (G[i][j] == 0) {
				cost[i][j] = inf;
			} else {
				cost[i][j] = G[i][j];
			}
		}
	}
	for (int i = 1; i < n; i++) {
		visited[i] = 0;
		dist[i] = cost[0][i];
		from[i] = 0;
	}
	int mindist;
	int ne = n - 1;
	int v;
	while (ne > 0) {
		mindist = inf;
		for (int i = 0; i < n; i++) {
			if (visited[i] == 0 && mindist > dist[i]) {
				mindist = dist[i];
				v = i;
			}
		}
		visited[v] = 1;
		int u = from[v];
		cout << u << "->" << v << endl;
		mincost += cost[u][v];
		for (int i = 0; i < n; i++) {
			if (visited[i] == 0 && dist[i] > cost[v][i]) {
				dist[i] = cost[v][i];
				from[i] = v;
			}
		}
		ne--;
	}
	cout << "Minimum cost: " << mincost;
}

int main() {
	Graph a;
	a.read();
	//a.temp();
	a.prim();
}
