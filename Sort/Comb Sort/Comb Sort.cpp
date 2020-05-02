#include <iostream>

using namespace std;

int Amount_Elements, Array[101];

void Comb_Sort() {
    for(int i = Amount_Elements / 1.3; i >= 1; i /= 1.3) {
        for(int j = 0; j + i < Amount_Elements; j++) {
            if(Array[j] > Array[j + i]) {
                swap(Array[j], Array[j + i]);
            }
        }
    }
}

int main() {
    cin >> Amount_Elements;
    for(int i = 0; i < Amount_Elements; i++) {
        cin >> Array[i];
    }
    Comb_Sort();
    for(int i = 0; i < Amount_Elements; i++) {
        cout << Array[i] << " ";
    }
    return 0;
}
