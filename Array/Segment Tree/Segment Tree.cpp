#include <iostream>

using namespace std;

int Amount_Elements, Segment_Tree[101][101];

void Build_Segment_Tree(int i, int j) {
    if(i != j) {
        int m = (i + j) / 2;
        Build_Segment_Tree(i, m);
        Build_Segment_Tree(m + 1, j);
        Segment_Tree[i][j] = Segment_Tree[i][m] + Segment_Tree[m + 1][j];
    }
}

int Calculate_Segment_Tree(int i, int j, int ci, int cj) {
    int m = (ci + cj) / 2;

    if(i <= ci && cj <= j) {
        return Segment_Tree[ci][cj];
    }else if(((i > ci && cj <= j) && (cj >= i)) || ((i <= ci && cj > j) && (ci <= j)) || ((ci <= i) && (j <= cj))) {
        return Calculate_Segment_Tree(i, j, ci, m) + Calculate_Segment_Tree(i, j, m + 1, cj);
    }
    return 0;
}

void Update_Segment_Tree(int ei, int v) {
    int m, i = 1, j = 8;
    while(i != j) {
        Segment_Tree[i][j] += v;
        m = (i + j) / 2;
        if(i <= ei && ei <= m) {
            j = m;
        }else{
            i = m + 1;
        }
    }
    Segment_Tree[i][j] += v;
}

void Print_Segment_Tree(int i, int j) {
    cout << i << " : " << j << " = " << Segment_Tree[i][j] << "\n";
    int m = (i + j) /  2;

    if(i != m) {
        Print_Segment_Tree(i, m);
    }
    if(m + 1 != j) {
        Print_Segment_Tree(m + 1, j);
    }
}

int main() {
    cin >> Amount_Elements;

    for(int i = 1; i <= Amount_Elements; i++) {
        cin >> Segment_Tree[i][i];
    }

    Build_Segment_Tree(1, Amount_Elements);
    return 0;
}
