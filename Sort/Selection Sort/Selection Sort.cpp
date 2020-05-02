#include <iostream>

using namespace std;

int Amount_Elements, Array[101];

void Selection_Sort() {
    for(int i = 0, k, l; i < Amount_Elements - 1; i++) {
        for(int j = i + 1, k = Array[i]; j < Amount_Elements; j++) {
            if(k > Array[j]) {
                k = Array[j];
                l = j;
            }
        }
        swap(Array[i], Array[l]);
    }
}

int main() {
    cin >> Amount_Elements;
    for(int i = 0; i < Amount_Elements; i++) {
        cin >> Array[i];
    }
    Selection_Sort();
    for(int i = 0; i < Amount_Elements; i++) {
        cout << Array[i] << " ";
    }
    return 0;
}
