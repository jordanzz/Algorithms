#include <iostream>

using namespace std;

int Total_Change, Amount_Type_Coins, Type_Coins[20];

int Dynamic_Table[20][101];

int main() {
    cin >> Total_Change >> Amount_Type_Coins;
    for(int i = 1; i <= Amount_Type_Coins; i++) {
        cin >> Type_Coins[i];
    }

    for(int i = 0; i <= Total_Change; i++) {
        Dynamic_Table[0][i] = i;
    }

    for(int i = 1; i <= Amount_Type_Coins; i++) {
        for(int j = 1; j <= Total_Change; j++) {
            if(j - Type_Coins[i] >= 0) {
                Dynamic_Table[i][j] = min(Dynamic_Table[i][j - Type_Coins[i]] + 1, Dynamic_Table[i - 1][j]);
            }else{
                Dynamic_Table[i][j] = Dynamic_Table[i - 1][j];
            }
        }
    }

    cout << Dynamic_Table[Amount_Type_Coins][Total_Change] << "\n";
    return 0;
}
