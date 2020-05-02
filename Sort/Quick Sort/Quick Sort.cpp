#include <iostream>

using namespace std;

int Amount_Elements, Array[101];

void Quick_Sort(int First, int Last) {
    if(First < Last) {
        int i = First - 1;
        for(int j = First; j < Last; j++) {
            if(Array[j] <= Array[Last]) {
                i++;
                swap(Array[j], Array[i]);
            }
        }
        i++;
        swap(Array[Last], Array[i]);
        Quick_Sort(First, i - 1);
        Quick_Sort(i + 1, Last);
    }
}

int main() {
    cin >> Amount_Elements;
    for(int i = 0; i < Amount_Elements; i++) {
        cin >> Array[i];
    }
    Quick_Sort(0, Amount_Elements - 1);
    for(int i = 0; i < Amount_Elements; i++) {
        cout << Array[i] << " ";
    }
    return 0;
}
