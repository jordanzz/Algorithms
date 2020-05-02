#include <iostream>

using namespace std;

int Amount_Elements, All_Elements[101];

int Kadane(int Current_Elements[]) {
    int Current_Biggest_Sum = 0, Biggest_Sum = 0;

    for(int i = 0; i < Amount_Elements; i++) {
        Current_Biggest_Sum += Current_Elements[i];

        if(Current_Biggest_Sum < 0) {
            Current_Biggest_Sum = 0;
        }

        if(Biggest_Sum < Current_Biggest_Sum) {
            Biggest_Sum = Current_Biggest_Sum;
        }
    }
    return Biggest_Sum;
}

int main() {
    cin >> Amount_Elements;
    for(int i = 0; i < Amount_Elements; i++) {
        cin >> All_Elements[i];
    }
    cout << Kadane(All_Elements) << "\n";
    return 0;
}
