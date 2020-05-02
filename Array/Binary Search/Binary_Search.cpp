#include <iostream>
#include "Binary_Search.h"

using namespace std;

int t_Amount_Elements, t_Searched_Element, t_Array[101];

int main() {
    cin >> t_Amount_Elements >> t_Searched_Element;
    for(int Counter = 0; Counter < t_Amount_Elements; Counter++) {
        cin >> t_Array[Counter];
    }
    cout << Binary_Search(t_Array, t_Amount_Elements, t_Searched_Element);
    return 0;
}
