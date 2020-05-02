#include <iostream>

using namespace std;

string Text, Searched_Pattern, Start_Text;

long long Rolling_Hash, Searched_Hash, Result;

long long Power_Function(long long Power) {
    long long result = 1;
    for(long long i = 0; i < Power; i++) {
        result *= 3;
    }
    return result;
}

long long Hash_Function(string Hashed_String) {
    long long result = 0;
    for(long long i = Hashed_String.size() - 1, j = 0; i >= 0; i--, j++) {
        result += (Hashed_String[j] * Power_Function(i));
    }
    return result;
}

int main() {
    cin >> Text >> Searched_Pattern;
    for(int i = 0; i < Searched_Pattern.size(); i++) {
        Start_Text.push_back(Text[i]);
    }

    Searched_Hash = Hash_Function(Searched_Pattern);
    Rolling_Hash = Hash_Function(Start_Text);

    if(Searched_Hash == Rolling_Hash) {
        Result++;
    }

    for(int i = Searched_Pattern.size(); i < Text.size(); i++) {
        Rolling_Hash -= (Text[i - Searched_Pattern.size()] * Power_Function(Searched_Pattern.size() - 1));
        Rolling_Hash *= 3;
        Rolling_Hash += Text[i];
        if(Searched_Hash == Rolling_Hash) {
            Result++;
        }
    }

    cout << Result << "\n";
    return 0;
}
