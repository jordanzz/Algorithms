#include <iostream>
#include <vector>

using namespace std;

vector < int > Graph[101];

int Amount_Nodes, Amount_Edges, Start_Node, Weight_Nodes[101][101];

bool Marked_Nodes[101];

void Bellman_Ford(vector < int > Current_Graph[]) {
    for(int i = 0; i < Amount_Nodes - 1; i++) {
        for(int j = 0; j < Amount_Nodes; j++) {
            for(int k = 0; k < Current_Graph[j].size(); k++) {
                if(Marked_Nodes[j]) {
                    if(!Marked_Nodes[Current_Graph[j][k]]) {
                        Weight_Nodes[Current_Graph[j][k]][Current_Graph[j][k]] = Weight_Nodes[j][j] + Weight_Nodes[j][Current_Graph[j][k]];
                        Marked_Nodes[Current_Graph[j][k]] = true;
                    }else{
                        if(Weight_Nodes[j][j] + Weight_Nodes[j][Current_Graph[j][k]] < Weight_Nodes[Current_Graph[j][k]][Current_Graph[j][k]]) {
                            Weight_Nodes[Current_Graph[j][k]][Current_Graph[j][k]] = Weight_Nodes[j][j] + Weight_Nodes[j][Current_Graph[j][k]];
                        }
                    }
                }
            }
        }
    }
}

int main() {
    cin >> Amount_Nodes >> Amount_Edges;
    for(int i = 0, j, k, l; i < Amount_Edges; i++) {
        cin >> j >> k >> l;
        Graph[j].push_back(k);
        Weight_Nodes[j][k] = l;
    }
    cin >> Start_Node;
    Marked_Nodes[Start_Node] = true;
    Bellman_Ford(Graph);
    for(int i = 0; i <= Amount_Nodes; i++) {
        cout << i << " " << Weight_Nodes[i][i] << "\n";
    }
    return 0;
}
