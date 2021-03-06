#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector < int > Graph[101];

stack < int > Stack;

int Amount_Nodes, Amount_Edges, Start_Node;

bool Marked_Nodes[101];

void Depth_First_Search(vector < int > Current_Graph[]){
    for(int i = 0; !Stack.empty(); i = 0) {
        if(!Marked_Nodes[Stack.top()]){
            Marked_Nodes[Stack.top()] = true;
        }
        for( ; i < Current_Graph[Stack.top()].size(); i++) {
            if(!Marked_Nodes[Current_Graph[Stack.top()][i]]){
                break;
            }
        }
        if(i != Current_Graph[Stack.top()].size()) {
            Stack.push(Current_Graph[Stack.top()][i]);
        }else{
            Stack.pop();
        }
    }
}

int main(){
    cin >> Amount_Nodes >> Amount_Edges;
    for(int i = 0, j, k; i < Amount_Edges; i++){
        cin >> j >> k;
        Graph[j].push_back(k);
        Graph[k].push_back(j);
    }
    cin >> Start_Node;
    Stack.push(Start_Node);
    Depth_First_Search(Graph);
    return 0;
}
