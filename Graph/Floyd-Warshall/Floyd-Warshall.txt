#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector < int > Graph[101];

int Amount_Nodes, Amount_Edges, Start_Node, Weight_Nodes[101][101];

bool Marked_Ways[101][101];

void Floyd_Warshall(vector < int > Current_Graph[]) {
    for(int k = 0; k < Amount_Nodes; k++) {
        for(int i = 0; i < Amount_Nodes; i++) {
            for(int j = 0; j < Amount_Nodes; j++) {
                if((Marked_Ways[i][j] && (Marked_Ways[i][k] && Marked_Ways[k][j])) && ((Weight_Nodes[i][k] + Weight_Nodes[k][j]) < Weight_Nodes[i][j])){
                    Weight_Nodes[i][j] = Weight_Nodes[i][k] + Weight_Nodes[k][j];
                }
                if(!Marked_Ways[i][j] && (Marked_Ways[i][k] && Marked_Ways[k][j])){
                    Weight_Nodes[i][j] = Weight_Nodes[i][k] + Weight_Nodes[k][j];
                    Marked_Ways[i][j] = true;
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
        Marked_Ways[j][k] = true;
    }
    for(int i = 0; i < Amount_Nodes; i++) {
        Marked_Ways[i][i] = true;
    }
    cin >> Start_Node;
    Floyd_Warshall(Graph);
    for(int i = 0; i < Amount_Nodes; i++) {
        for(int j = 0; j < Amount_Nodes; j++) {
            if(i != j) {
                cout << i << "-" << j <<  " = " << Weight_Nodes[i][j] << "\n";
            }
        }
        cout << "\n";
    }
    return 0;
}
