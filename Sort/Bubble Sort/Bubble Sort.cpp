#include <iostream>

using namespace std;

int Amount_Elements, Array[101];

void Bubble_Sort() {
    for(int i = 0; i < Amount_Elements - 1; i++) {
        for(int j = 0; j < Amount_Elements - i - 1; j++) {
            if(Array[j] > Array[j + 1]) {
                swap(Array[j], Array[j + 1]);
            }
        }
    }
}

int main() {
    cin >> Amount_Elements;
    for(int i = 0; i < Amount_Elements; i++) {
        cin >> Array[i];
    }
    Bubble_Sort();
    for(int i = 0; i < Amount_Elements; i++) {
        cout << Array[i] << " ";
    }
    return 0;
}
