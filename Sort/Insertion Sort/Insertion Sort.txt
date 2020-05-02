#include <iostream>

using namespace std;

int Amount_Elements, Array[101];

void Insertion_Sort(){
    for(int i = 1; i < Amount_Elements; i++) {
        for(int j = i; Array[j] < Array[j - 1] && j > 0; j--) {
            swap(Array[j], Array[j - 1]);
        }
    }
}

int main() {
    cin >> Amount_Elements;
    for(int i = 0; i < Amount_Elements; i++) {
        cin >> Array[i];
    }
    Insertion_Sort();
    for(int i = 0; i < Amount_Elements; i++) {
        cout << Array[i] << " ";
    }
    return 0;
}
