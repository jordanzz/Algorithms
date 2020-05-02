#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int Total_Weight, Amount_Elements, Elements_Profits[20], Elements_Weights[20], j;

set < double > Profit_Weight_Ratios;

set < double > :: iterator Iterator;

double CurrentProfit, CurrentWeight, RatioProfitToWeight, Real_Profit_Weight_Ratios[20];

map <  double , vector < int > > Elements_By_Ratios;

bool Result[20];

int main() {
    cin >> Total_Weight >> Amount_Elements;
    for(int i = 1; i <= Amount_Elements; i++) {
        cin >> Elements_Profits[i] >> Elements_Weights[i];
    }

    for(int i = 1; i <= Amount_Elements; i++) {
        CurrentProfit = Elements_Profits[i];
        CurrentWeight = Elements_Weights[i];
        RatioProfitToWeight = CurrentProfit / CurrentWeight;
        Profit_Weight_Ratios.insert(RatioProfitToWeight);
        Iterator = Profit_Weight_Ratios.find(RatioProfitToWeight);
        Elements_By_Ratios[*Iterator].push_back(i);
    }

    j = Profit_Weight_Ratios.size();
    for(Iterator = Profit_Weight_Ratios.begin(); Iterator != Profit_Weight_Ratios.end(); Iterator++, j--) {
        Real_Profit_Weight_Ratios[j] = *Iterator;
    }

    for(int i = 1; i <= Profit_Weight_Ratios.size(); i++) {
        for( j = 0; j < Elements_By_Ratios[Real_Profit_Weight_Ratios[i]].size(); j++) {
            if(Total_Weight - Elements_Weights[Elements_By_Ratios[Real_Profit_Weight_Ratios[i]][j]] >= 0) {
                Result[Elements_By_Ratios[Real_Profit_Weight_Ratios[i]][j]] = true;
                Total_Weight -= Elements_Weights[Elements_By_Ratios[Real_Profit_Weight_Ratios[i]][j]];
            }
        }
    }

    for(int i = 1; i <= Amount_Elements; i++) {
        if(Result[i]) {
            cout << "1 ";
        }else{
            cout << "0 ";
        }
    }

    cout << "\n";
    return 0;
}
