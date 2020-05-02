#include <iostream>

using namespace std;

int Amount_Elements, Array[101], Range_Array[497605208], Sorted_Array[101];

void Counting_Sort() {
    for(int i = 0; i < Amount_Elements; i++) {
        Range_Array[Array[i]]++;
    }
    for(int i = 0; i < 497605208; i++) {
        Range_Array[i + 1] += Range_Array[i];
    }
    for(int i = 0; i < Amount_Elements; i++) {
        Sorted_Array[Range_Array[Array[i]] - 1] = Array[i];
        --Range_Array[Array[i]];
    }
}

int main() {
    cin >> Amount_Elements;
    for(int i = 0; i < Amount_Elements; i++) {
        cin >> Array[i];
    }
    Counting_Sort();
    for(int i = 0; i < Amount_Elements; i++) {
        cout << Sorted_Array[i] << " ";
    }
    return 0;
}

