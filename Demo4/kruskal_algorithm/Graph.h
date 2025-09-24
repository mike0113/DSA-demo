#ifndef GRAPH_H
#define GRAPH_H

#include <bits/stdc++.h>
using namespace std;

// C++ program for the above approach

// DSU data structure
// path compression + rank by union
class DSU {

public:

    vector<int> parent;
    vector<int> rank;

    DSU(int n)
    {
        //cout << "n:" << n << std::endl;

        //parent = new int[n];
        //rank = new int[n];

        for (int i = 0; i <= n; i++) {
            parent.push_back(-1);
            rank.push_back(1);
            //parent[i] = -1;
            //rank[i] = 1;
        }
    }

    // Find function
    int find(int i)
    {
        if (parent[i] == -1)
            return i;

        return parent[i] = find(parent[i]);
    }

    // Union function
    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
            }
            else if (rank[s1] > rank[s2]) {
                parent[s2] = s1;
            }
            else {
                parent[s2] = s1;
                rank[s1] += 1;
            }
        }
    }
};

class Graph {
public:
    vector<vector<int> > edgelist;
    int V;

    Graph(int V) { this->V = V; }

    // Function to add edge in a graph
    void addEdge(int x, int y, int w)
    {
        edgelist.push_back({ w, x, y });
        //cout << w << " " << x << " " << y << std::endl;
    }

    void kruskals_mst(vector<vector<int>> &kruskalOrder)
    {
        // Sort all edges
        sort(edgelist.begin(), edgelist.end()); //先排序邊的大小

        // Initialize the DSU
        DSU s(V);
        int ans = 0;
        cout << "Following are the edges in the "
                "constructed MST"
             << std::endl;
        for (auto edge : edgelist) {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            // Take this edge in MST if it does
            // not forms a cycle
            if (s.find(x) != s.find(y)) {   //不是為同一個集合
                s.unite(x, y);  //聯集
                ans += w;
                cout << x << " -- " << y << " == " << w
                     << std::endl;
                kruskalOrder.push_back(vector<int> ({ x, y, w }));
            }
        }
        cout << "Minimum Cost Spanning Tree: " << ans << std::endl;
    }
};



#endif // GRAPH_H
