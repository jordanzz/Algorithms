#include <iostream>

using namespace std;

int Amount_Elements, Array[101], Heap[101];

void Heap_Sort() {
    for(int i = 0, j = 1; i < Amount_Elements; i++, j = i + 1) {
        Heap[j] = Array[i];
        while(j != 1) {
            if(Heap[j] >= Heap[j / 2]) {
                swap(Heap[j], Heap[j / 2]);
                j /= 2;
            }else{
                break;
            }
        }
    }
    for(int i = Amount_Elements, j = 1; (i > 1) && (Heap[j] > Heap[i]); i--, j = 1) {
        swap(Heap[j], Heap[i]);
        while(j < i) {
            if(((j * 2) < i) && ((Heap[j * 2] >= Heap[j * 2 + 1]) && (Heap[j] <= Heap[j * 2]))) {
                swap(Heap[j], Heap[j * 2]);
                j *= 2;
            }else if(((j * 2 + 1) < i) && ((Heap[j * 2 + 1] >= Heap[j * 2]) && (Heap[j] <= Heap[j * 2 + 1]))){
                swap(Heap[j], Heap[j * 2 + 1]);
                j *= 2;
                j++;
            }else{
                break;
            }
        }
    }
}

int main() {
    cin >> Amount_Elements;
    for(int i = 0; i < Amount_Elements; i++) {
        cin >> Array[i];
    }
    Heap_Sort();
    for(int i = 1; i <= Amount_Elements; i++) {
        cout << Heap[i] << " ";
    }
    return 0;
}
