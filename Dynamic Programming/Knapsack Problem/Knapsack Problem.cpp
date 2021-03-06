#include <iostream>

using namespace std;

int Total_Weight, Amount_Elements, Elements_Profits[20], Elements_Weights[20];

int Dynamic_Table[20][101];

int main() {
    cin >> Total_Weight >> Amount_Elements;
    for(int i = 1; i <= Amount_Elements; i++) {
        cin >> Elements_Profits[i] >> Elements_Weights[i];
    }

    for(int i = 1; i <= Amount_Elements; i++) {
        for(int j = 1; j <= Total_Weight; j++) {
            if(j - Elements_Weights[i] >= 0) {
                Dynamic_Table[i][j] = max(Dynamic_Table[i - 1][j - Elements_Weights[i]] + Elements_Profits[i], Dynamic_Table[i - 1][j]);
            }else{
                Dynamic_Table[i][j] = Dynamic_Table[i - 1][j];
            }
        }
    }

    cout << Dynamic_Table[Amount_Elements][Total_Weight] << "\n";
    return 0;
}
