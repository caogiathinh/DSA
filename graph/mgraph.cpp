#include <iostream>
#include <random>
#include <iomanip>
#include <vector>
#include <fstream>
#include <sstream>
#include <queue>
#include <stack>


using namespace std;

struct ledge;
typedef vector<vector<ledge>>lgraph;
lgraph buildLgraph(int n);
void printLgraph(lgraph l);
void addLedge(lgraph& l, int u, ledge e);
lgraph createLgraph();
//-------------------------------------------/
typedef vector<vector<float>> mgraph;
mgraph buildMgraph(int numOfvertices);
void printMgraph(mgraph g);                   
void addMedge(mgraph& g, int u, int v, float w);
vector <string> getWord(string s);
mgraph createMgraph();
// ------------------------------------------/
vector <int>bfs(lgraph l, int start);
vector <int>dfs(lgraph l, int start); 
//-------------------------------------------/
typedef struct {
	int u;
	float w;
}vertex;

typedef struct  {
	vertex v;
	float w;
}dedge;
typedef struct vector<vector<dedge>>dgraph; 
struct cmp;
vector <float> dijkstra(lgraph l, int u, vector <int>& prev);
void printPath(vector <int> prev, vector <float> dist, int source, int destination);
vector <float> bellmanFord(lgraph l, int  u, vector <int>& prev); 
//------------------------------------------/
typedef struct {
	int u, v;
	float w;
} pedge;
typedef pair<pedge, vertex> iPair; // using priority queue

typedef vector<pedge> pgraph;
void printPrime(vector <pedge> mst);

vector <pedge> primUsingQueue(lgraph g, int u);
struct pairless {
	bool operator()(iPair a, iPair b) {
		if (a.first.w == b.first.w) {
			return a.first.u < b.first.u;
		}
		else {
			return a.first.w < b.first.w;
		}
	}
};
int main() {
	lgraph l;
	l = createLgraph(); 

	printLgraph(l); 

	/*int source, destination;
	do {
		cout << "\nEnter the source vertex and destination vertex to find the shortest path: ";
		cin >> source >> destination;
		if (source < 0 || source > l.size() || destination < 0 || destination > l.size()) {
			cout << "\nInvalid value. Please re-enter"; 
		}
	} while (source < 0 || source > l.size() || destination < 0 || destination > l.size());

	vector <float> bellman = bellmanFord(l, source, prev);
	printPath(prev,bellman,source,destination);*/
	/*vector<pedge> p = primUsingQueue(l, 0);
	printPrime(p); */


	return 0; 
}

struct ledge {
	int v;
	float w;
};

typedef vector<vector<ledge>>lgraph;
lgraph buildLgraph(int n) {
	// creat n rows
	lgraph l(n);
	for (int i = 0; i < n; i++) {
		l[i] = vector<ledge>(0, { 0 });
	}
	return l;
}

void printLgraph(lgraph l) {
	for (int i = 0; i < l.size(); i++) {
		cout << "[" << i << "]: ";
		for (int j = 0; j < l[i].size(); j++) {
			cout << "[" << l[i][j].v << " " << l[i][j].w << "]" << " ";
		}
		cout << endl;
	}
}

void addLedge(lgraph& l, int u, ledge e) {
	if (u < 0 || u > l.size() || e.v < 0 || e.v > l.size()) {
		return;
	}
	if (u == e.v) {
		return;
	}
	l[u].push_back(e);
	l[e.v].push_back({ u, e.w });
}

mgraph buildMgraph(int numOfvertices) {
	mgraph g(numOfvertices, vector<float>(numOfvertices, 0));
	return g;
}

void printMgraph(mgraph g) {
	for (int i = 0; i < g.size(); i++) {
		for (int j = 0; j < g[i].size(); j++) {
			cout << fixed << setprecision(1) << g[i][j] << " ";
		}
		cout << endl;
	}
}

void addMedge(mgraph& g, int u, int v, float w) {
	if (u < 0 || u > g.size() || v < 0 || v > g.size()) {
		return;
	}
	g[u][v] = w;
}

vector <string> getWord(string s) {
	stringstream ss(s);
	string word;
	vector <string> v;

	while (ss >> word) {
		v.push_back(word);
	}
	return v;
}

mgraph createMgraph() {
	ifstream f("graph.txt");
	string s;

	getline(f, s); // first containing list of vertices

	vector <string> vertices = getWord(s);
	mgraph g = buildMgraph(vertices.size());

	while (getline(f, s)) {
		vector <string> v = getWord(s);
		auto a = find(vertices.begin(), vertices.end(), v[0]);
		auto b = find(vertices.begin(), vertices.end(), v[1]);
		addMedge(g, distance(vertices.begin(), a), distance(vertices.begin(), b), 1);
	}
	f.close();
	return g;
}

lgraph createLgraph() {
	ifstream f("graph.txt");
	string s;

	getline(f, s); // first containing list of vertices

	vector <string> vertices = getWord(s);
	lgraph l = buildLgraph(vertices.size());

	// Get each pair on input
	while (getline(f, s)) {
		vector <string> v = getWord(s);
		
		addLedge(l, stoi(v[0]), {stoi(v[1]), stof(v[2])});
	}
	f.close();
	return l;
}

vector <int>bfs(lgraph l, int start) {
	vector<bool> visited(l.size(), false); 
	queue<int> q; 
	vector<int> tranversal; 

	visited[start] = true;
	q.push(start); 

	while (!q.empty()) {
		int current = q.front(); 
		q.pop(); 
		tranversal.push_back(current);

		for (int i = 0; i < l[current].size(); i++) {
			int w = l[current][i].v;
			if (!visited[w]) {
				visited[w] = true; 
				q.push(w); 
			}
		}	
	}
	return tranversal; 
}

vector <int>dfs(lgraph l, int start) {
	vector<bool> visited(l.size(), false);
	stack <int> st;
	vector<int> tranversal;

	visited[start] = true;
	st.push(start);

	while (!st.empty()) {
		int current = st.top();    
		st.pop();
		tranversal.push_back(current);

		for (int i = 0; i < l[current].size(); i++) {
			int w = l[current][i].v;
			if (!visited[w]) {
				visited[w] = true;
				st.push(w);
			}
		}
	}
	return tranversal;
}



struct cmp {
	bool operator ()(vertex a, vertex b) {
		if (a.w == b.w) {
			return a.u < b.u;
		}
		else {
			return a.w < b.w;
		}
	}
};

vector <float> dijkstra(lgraph l, int u, vector <int>& prev) {
	priority_queue <vertex, vector <vertex>, cmp > q;

	vector <bool> visited(l.size(), false); 
	q.push(vertex{ u,0. });
	visited[0] = true; 

	vector <float> dist(l.size(), INT_MAX);
	// distance from the source to itself is zero
	dist[u] = 0; 

	while (!q.empty()) {
		vertex b = q.top(); q.pop(); 
		// loop all neighbor of b
		float w = b.w; 
		for (auto e : l[b.u]) {
			if (dist[e.v] > w + e.w) {
				dist[e.v] = w + e.w; 
				q.push(vertex{ e.v, dist[e.v] });

				prev[e.v] = b.u;
			}
		}
	}
	return dist;
}

void printPath(vector <int> prev, vector <float> dist, int source, int destination) {
	if (destination < 0) {
		return; 
	}
	printPath(prev, dist, source, prev[destination]);
	if (destination != -1 && prev[destination] != -1) {
		cout << "(" << prev[destination] << ", " << destination << ") "; 
		cout << "Dist: " << dist[destination] - dist[prev[destination]] << endl;
	}
}

vector <float> bellmanFord(lgraph l, int  u, vector <int>& prev) {
	// set intial distance form the source to v as infinity
	vector <float> dist(l.size(), INT_MAX);
	dist[u] = 0;
	// all vertices
	for (int i = 1; i < l.size(); i++) {
		// for each vertex, get all edges
		for (int j = 0; j < l.size(); j++) {
			for (int k = 0; k < l[j].size(); k++) {
				int v = l[j][k].v;
				float w = l[j][k].w;
				if (dist[j] + w < dist[v]) {
					dist[v] = dist[j] + w;
					prev[v] = j;
				}
			}
		}
	}
	return dist;
}



vector <pedge> primUsingQueue(lgraph g, int u) {
	priority_queue <iPair, vector<iPair>, pairless> pq;
	vector <float> dist(g.size(), INT_MAX);
	vector <bool> selected(g.size());

	pq.push( iPair{ pedge{ u,u,0 }, vertex{ u,0 } });

	dist[u] = 0;

	vector <int> prev(g.size(), -1);
	vector<pedge> mst;
	// consider any node as the source node and the distance to other node
	while (!pq.empty()) {
		vertex s = pq.top().second;
		pedge e = pq.top().first;
		pq.pop(); 
		if (selected[s.u]) {
			continue; 
		}
		selected[s.u] = true;
		// for all edges from s.u
		for (ledge e : g[s.u]) {
			float w = e.w;
			if (w < dist[e.v]) {
				dist[e.v] = w;
				pq.push(make_pair(pedge{ s.u, e.v, w }, vertex{ e.v,w }));

				prev[e.v] = s.u;

			}
		}
	}
	for (int i = 0; i < selected.size(); i++) {
		mst.push_back(pedge{ prev[i], i , dist[i] });
	}
	return mst;
}

void printPrime(vector <pedge> mst) {
	for (int i = 1; i < mst.size(); i++) {
		cout << mst[i].u << "---" << mst[i].v << "---" << mst[i].w << endl;
 	}
}
