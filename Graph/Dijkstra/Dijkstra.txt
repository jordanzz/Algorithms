#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

vector < int > Graph[101];

vector < pair < int , int > > Adder_Nodes;

priority_queue < pair < int , int >, vector < pair < int, int > >, greater < pair < int, int > > > Priority_Queue;

int Amount_Nodes, Amount_Edges, Starting_Node, Weight_Nodes[101][101];

bool Marked_Nodes[101];

void Dijkstra(vector < int > Current_Graph[]) {
    for(int i = 0; !Priority_Queue.empty(); i = 0) {
        for( ; i < Current_Graph[Priority_Queue.top().second].size(); i++) {
            if(!Marked_Nodes[Current_Graph[Priority_Queue.top().second][i]]) {
                Adder_Nodes.push_back(make_pair(Weight_Nodes[Priority_Queue.top().second][Priority_Queue.top().second] + Weight_Nodes[Priority_Queue.top().second][Current_Graph[Priority_Queue.top().second][i]], Current_Graph[Priority_Queue.top().second][i]));
                Weight_Nodes[Current_Graph[Priority_Queue.top().second][i]][Current_Graph[Priority_Queue.top().second][i]] = Weight_Nodes[Priority_Queue.top().second][Priority_Queue.top().second] + Weight_Nodes[Priority_Queue.top().second][Current_Graph[Priority_Queue.top().second][i]];
                Marked_Nodes[Current_Graph[Priority_Queue.top().second][i]] = true;
            }else{
                if(Weight_Nodes[Priority_Queue.top().second][Priority_Queue.top().second] + Weight_Nodes[Priority_Queue.top().second][Current_Graph[Priority_Queue.top().second][i]] < Weight_Nodes[Current_Graph[Priority_Queue.top().second][i]][Current_Graph[Priority_Queue.top().second][i]]) {
                    Weight_Nodes[Current_Graph[Priority_Queue.top().second][i]][Current_Graph[Priority_Queue.top().second][i]] = Weight_Nodes[Priority_Queue.top().second][Priority_Queue.top().second] + Weight_Nodes[Priority_Queue.top().second][Current_Graph[Priority_Queue.top().second][i]];
                }
            }
        }
        Priority_Queue.pop();
        while(Adder_Nodes.size() > 0) {
            Priority_Queue.push(Adder_Nodes.back());
            Adder_Nodes.pop_back();
        }
    }
}


int main() {
    cin >> Amount_Nodes >> Amount_Edges;
    for(int i = 0, j, k, l; i < Amount_Edges; i++) {
        cin >> j >> k >> l;
        Graph[j].push_back(k);
        Graph[k].push_back(j);
        Weight_Nodes[j][k] = l;
        Weight_Nodes[k][j] = l;
    }
    cin >> Starting_Node;
    Priority_Queue.push(make_pair(0, Starting_Node));
    Marked_Nodes[Starting_Node] = true;
    Dijkstra(Graph);
    for(int i = 0; i <= Amount_Nodes; i++) {
        cout << i << " " << Weight_Nodes[i][i] << "\n";
    }
    return 0;
}
