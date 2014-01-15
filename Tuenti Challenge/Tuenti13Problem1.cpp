#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int t,n;
string s;
long long bestBudget;
pair<long long,long long> bestBitcoin;

int main() {
    getline(cin,s);t = atoi(s.c_str());
    for (int tt=0; tt<t; tt++) {
        getline(cin,s);n = atoi(s.c_str());
        bestBudget = n;
        bestBitcoin = make_pair(0,0);
        getline(cin,s);
        stringstream ss(s);
        while (ss>>s && s!="\n") {
            int a = atoi(s.c_str());
            bestBudget = max(bestBudget,bestBitcoin.first*a);
            bestBitcoin = max(bestBitcoin,make_pair(bestBudget/a,bestBudget%a));
        }
        cout<<bestBudget<<"\n";
    }

    return 0;

}
