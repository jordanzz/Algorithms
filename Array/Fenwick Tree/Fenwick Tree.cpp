#include <iostream>

using namespace std;

int Amount_Elements, All_Elements[101], Fenwick_Tree[101];

void Update_Fenwick_Tree(int i, int j) {
    while(i <= Amount_Elements) {
        Fenwick_Tree[i] += j;
        i+=i&(-i);
    }
}

int Calculate_Fenwick_Tree(int i) {
    int j = 0;
    while(i >= 1) {
        j += Fenwick_Tree[i];
        i-=i&(-i);
    }
    return j;
}

void Print_Fenwick_Tree() {
    for(int i = 1; i <= Amount_Elements; i++) {
        cout << i << " ";
    }
    cout << "\n";
    for(int i = 1; i <= Amount_Elements; i++) {
        cout << Fenwick_Tree[i] << " ";
    }
}

int main() {
    cin >> Amount_Elements;
    for(int i = 1; i <= Amount_Elements; i++) {
        cin >> All_Elements[i];
    }

    for(int i = 1; i <= Amount_Elements; i++) {
        Update_Fenwick_Tree(i, All_Elements[i]);
    }
    return 0;
}
