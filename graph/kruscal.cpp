//
//// kruskal.cpp : This file contains the 'main' function. Program execution begins and ends there.
////
//
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
//
//
//using namespace std;
//typedef struct tagEdge {
//	int src;	//source
//	int des;	//destination vertex
//	int w;		//weight	
//	bool visited;
//} edge;
//typedef struct tagNode {
//	int vertex, w;
//	bool visited;
//} node;
//
//typedef vector <vector <edge> > graph;
////Pair is between the node and the distance
//typedef pair <int, edge> iPair;	//first: weight, second: edge
//
//
//bool comp(iPair a, iPair b) {
//	if (a.first == b.first)
//		return a.second.src < b.second.src;
//	else return a.first < b.first;
//}
//
////adjacent list - add edge of u, v with weight
//void addEdge(graph& a, int u, int v, int w) {
//	edge e = { u, v, w, false };
//	a[u].push_back(e);
//}
//
//void print(graph g) {
//	int w = 0;
//	for (int i = 0; i < g.size(); i++) {
//		for (int j = 0; j < g[i].size(); j++) {
//			cout << "Edge: (" << g[i][j].src << ", " << g[i][j].des << ")  " << g[i][j].w << endl;
//			w += g[i][j].w;
//		}
//	}
//	cout << "Min cost: " << w << endl;
//}
//
//void print(vector <node> mst) {
//	int dist = 0;
//
//	for (int i = 0; i < mst.size(); i++) {
//		cout << "Vertex: " << mst[i].vertex << " w: " << mst[i].w << endl;
//		dist += mst[i].w;
//	}
//	cout << "Min distance: " << dist << endl;
//}
//
//void print(vector <edge> mst) {
//	int dist = 0;
//	for (int i = 0; i < mst.size(); i++) {
//		cout << "Edge: " << i << '(' << mst[i].src << ", " << mst[i].des << ")" << " w: " << mst[i].w << endl;
//		dist += mst[i].w;
//	}
//	cout << "Min distance: " << dist << endl;
//}
//
//bool isDfsCycleDirected(graph a, int u, vector <bool>& visited, vector <bool>& stak) {
//	if (visited[u] == false) {
//
//		visited[u] = true;
//		stak[u] = true;
//		for (int i = 0; i < a[u].size(); i++) {
//			if (!visited[a[u][i].des] && isDfsCycleDirected(a, a[u][i].des, visited, stak))
//				return true;
//			else if (stak[a[u][i].des])
//				return true;
//
//		}
//	}
//	stak[u] = false;  // remove the vertex from recursion stack
//	return false;
//}
//
//bool isCycleDirected(graph a, int s) {
//	if (a.size() == 0)
//		return false;
//	vector <bool> visited(a.size(), false), stak(a.size(), false);
//	for (int i = 0; i < a[s].size(); i++) {
//
//		if (!visited[a[s][i].des] && isDfsCycleDirected(a, a[s][i].des, visited, stak))
//			return true;
//	}
//
//	return false; // no cycle present
//}
//
//bool isDfsCycleUndirected(graph g, int u, vector <bool>& visited, int parent) {
//	// Mark the current node as visited
//	visited[u] = true;
//	for (int i = 0; i < g[u].size(); i++) {
//		// If an adjacent vertex is not visited,
//		// then recur for that adjacent
//		if (!visited[g[u][i].des]) {
//			if (isDfsCycleUndirected(g, g[u][i].des, visited, u))
//				return true;
//		}
//		else if (parent != g[u][i].des) //there are 2 nodes: 
//			return true;				//parent and des v=g[u][i].des are moved to the same node.
//	}
//	return false;
//}
//
//bool isCycleUndirected(graph g) {
//	if (g.size() == 0)
//		return false;
//	vector <bool> visited(g.size(), false);
//	for (int i = 0; i < g.size(); i++) {
//		if (!visited[i]) {
//			if (isDfsCycleUndirected(g, i, visited, -1))
//				return true;
//		}
//	}
//	return false;
//}
//
//graph naiveKruskal(graph& g) {
//	graph mst(g.size());
//	int nEdgeinMst = 0;
//	vector <iPair> edges;
//
//
//	//convert adjacent list to list
//	for (int i = 0; i < g.size(); i++)
//		for (int j = 0; j < g[i].size(); j++)
//			edges.push_back({ g[i][j].w, g[i][j] });
//	//sort edges
//	sort(edges.begin(), edges.end(), comp);
//	vector <bool> visited(g.size(), false);
//
//	for (int i = 0; i < edges.size(); i++) {
//
//		addEdge(mst, edges[i].second.src, edges[i].second.des, edges[i].second.w);
//		if (isCycleUndirected(mst)) {
//			//remove added edge
//			mst[edges[i].second.src].pop_back();
//			continue;
//		}
//		nEdgeinMst++;
//		if (nEdgeinMst == g.size() - 1)
//			break;
//	}
//	return mst;
//}
//
//struct disjointSets {
//	vector <int> root;
//	vector <int> rank;
//
//	disjointSets(int size) {
//		root.resize(size);
//		rank.resize(size);
//
//		for (int i = 0; i < size; i++) {
//			root[i] = i;
//			rank[i] = 1;
//		}
//	}
//	int parent(int a)  //find the parent of the given node
//	{
//		while (root[a] != a)
//		{
//			root[a] = root[root[a]];
//			a = root[a];
//		}
//		return a;
//	}
//	//check if the given two vertices are in the same “union” or not
//	void unionFind(int a, int b)
//	{
//		int d = parent(a);
//		int e = parent(b);
//		root[d] = root[e];
//	}
//	int findSet(int u) {
//		if (u == root[u])
//			return u;
//		root[u] = findSet(root[u]);
//		return root[u];
//	}
//	void unionSet(int a, int b) {
//		a = findSet(a);
//		b = findSet(b);
//		if (a != b) {
//			// Make tree with smaller height a subtree of the other tree 
//			if (rank[a] < rank[b])
//				swap(a, b);
//			root[b] = a;
//			rank[a] += rank[b];
//		}
//	}
//};
//
//graph kruskalUsingUnionFind(graph g) {
//	graph mst(g.size());
//	vector <iPair> edges;
//	//convert adjacent list to list
//	for (int i = 0; i < g.size(); i++)
//		for (int j = 0; j < g[i].size(); j++)
//			edges.push_back({ g[i][j].w, g[i][j] });
//	//sort edges
//	sort(edges.begin(), edges.end(), comp);
//	disjointSets ds(g.size());
//
//	for (int i = 0; i < edges.size(); i++) {
//
//		int u = edges[i].second.src;
//		int v = edges[i].second.des;
//		int setU = ds.parent(u);
//		int setV = ds.parent(v);
//		// Check if the selected edge is creating
//		// a cycle or not (Cycle is created if u
//		// and v belong to same set)
//		if (setU != setV) {
//			addEdge(mst, edges[i].second.src, edges[i].second.des, edges[i].second.w);
//
//			// Merge two sets
//			ds.unionFind(setU, setV);
//		}
//	}
//
//	return mst;
//}
//
//int main()
//{
//	int numV = 9;
//
//	graph l;
//	l.resize(numV);
//
//	addEdge(l, 0, 1, 4);
//	addEdge(l, 0, 7, 8);
//	addEdge(l, 1, 2, 8);
//	addEdge(l, 1, 7, 11);
//	addEdge(l, 2, 3, 7);
//	addEdge(l, 2, 8, 2);
//	addEdge(l, 2, 5, 4);
//	addEdge(l, 3, 4, 9);
//	addEdge(l, 3, 5, 14);
//	addEdge(l, 4, 5, 10);
//	addEdge(l, 5, 6, 2);
//	addEdge(l, 6, 7, 1);
//	addEdge(l, 6, 8, 6);
//	addEdge(l, 7, 8, 7);
//	graph mst = naiveKruskal(l);
//	//	graph mst = kruskalUsingUnionFind(l);
//	print(mst);
//
//	return 0;
//}