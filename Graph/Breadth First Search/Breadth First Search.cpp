#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector < int > Graph[101];

queue < int > Queue;

int Amount_Nodes, Amount_Edges, Start_Node;

bool Marked_Nodes[101];


void Breadth_First_Search(vector < int > Current_Graph[]) {
    for(int i = 0, j = 1; !Queue.empty(); i = 0, j++) {
        for( ; i < Current_Graph[Queue.front()].size(); i++) {
            if(!Marked_Nodes[Current_Graph[Queue.front()][i]]){
                Marked_Nodes[Current_Graph[Queue.front()][i]] = true;
                Queue.push(Current_Graph[Queue.front()][i]);
            }
        }
        Queue.pop();
    }
}


int main() {
    cin >> Amount_Nodes >> Amount_Edges;
    for(int i = 0, j, k; i < Amount_Edges; i++) {
        cin >> j >> k;
        Graph[j].push_back(k);
        Graph[k].push_back(j);
    }
    cin >> Start_Node;
    Queue.push(Start_Node);
    Marked_Nodes[Start_Node] = true;
    Breadth_First_Search(Graph);
    return 0;
}
