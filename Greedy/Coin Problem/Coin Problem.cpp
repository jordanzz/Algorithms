#include <iostream>
#include <algorithm>

using namespace std;

int Total_Change, Amount_Type_Coins, Type_Coins[20];

int Result;

int main() {
    cin >> Total_Change >> Amount_Type_Coins;
    for(int i = 0; i < Amount_Type_Coins; i++) {
        cin >> Type_Coins[i];
    }
    sort(Type_Coins, Type_Coins + Amount_Type_Coins);
    for(int i = Amount_Type_Coins - 1; i >= 0; i--) {
        while(Total_Change - Type_Coins[i] >= 0) {
            Total_Change -= Type_Coins[i];
            Result++;
        }
    }

    cout << Result << "\n";
    return 0;
}
