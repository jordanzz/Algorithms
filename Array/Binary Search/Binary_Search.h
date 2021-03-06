#pragma once

int Binary_Search(int Array[], int Amount_Elements, int Searched_Element) {
    int Left_Element, Right_Element, Middle_Element;

    for(Left_Element = 0, Right_Element = Amount_Elements - 1, Middle_Element = (Left_Element + Right_Element) / 2; Left_Element != Right_Element; Middle_Element = (Left_Element + Right_Element) / 2) {
        if(Array[Middle_Element] == Searched_Element) {
            return Middle_Element + 1;
        }

        if(Array[Middle_Element] < Searched_Element) {
            Left_Element = Middle_Element + 1;
        }

        if(Array[Middle_Element] > Searched_Element) {
            Right_Element = Middle_Element - 1;
        }
    }

    if(Array[Middle_Element] == Searched_Element) {
        return Middle_Element + 1;
    }else{
        return -1;
    }
}
