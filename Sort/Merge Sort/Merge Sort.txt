#include <iostream>

using namespace std;

int Amount_Elements, Array[101];

void Merge_Sort(int Start_Index, int End_Index) {
    int Middle_Index = (Start_Index + End_Index) / 2;
    if((Start_Index + 1 == End_Index) || (Start_Index == End_Index)) {
        if(Array[Start_Index] > Array[End_Index]) {
            swap(Array[Start_Index], Array[End_Index]);
        }
    }else{
        Merge_Sort(Start_Index, Middle_Index);
        Merge_Sort(Middle_Index + 1, End_Index);
        for(int X = Start_Index, First_Index = Start_Index, Second_Index = Middle_Index + 1; X < End_Index; X++) {
            if((Array[X] <= Array[First_Index]) && (Array[X] <= Array[Second_Index])) {
                if(First_Index == X) {
                    First_Index++;
                }
            }else if((Array[First_Index] <= Array[Second_Index]) && (Array[First_Index] <= Array[X])) {
                if(First_Index == X){
                    First_Index++;
                }else{
                    swap(Array[X], Array[First_Index]);
                    if((X + 1) == First_Index) {
                        First_Index++;
                    }
                }
            }else{
                if(First_Index == X) {
                    swap(Array[X], Array[Second_Index]);
                    First_Index = Second_Index;
                    if(Second_Index + 1 <= End_Index) {
                        Second_Index++;
                    }
                }else{
                    swap(Array[X], Array[Second_Index]);
                    if(Second_Index + 1 <= End_Index) {
                        Second_Index++;
                    }
                }
            }
        }
    }
}

int main() {
    cin >> Amount_Elements;
    for(int i = 0; i < Amount_Elements; i++) {
        cin >> Array[i];
    }
    Merge_Sort(0, Amount_Elements - 1);
    for(int i = 0; i < Amount_Elements; i++) {
        cout << Array[i] << " ";
    }
    return 0;
}
