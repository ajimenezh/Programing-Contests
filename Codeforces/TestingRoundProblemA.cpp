#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <stdio.h>

using namespace std;

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    string s;
    getline(cin,s);
    stringstream ss(s);
    string str;
    while (ss>>s) {
        for (int i=0; i<s.length()-1; i++) if (s[i]=='.' ||s[i]==',' ||s[i]=='?' ||s[i]=='!') {
            s = s.substr(0,i+1) + " " + s.substr(i+1,s.length()-i-1);
        }
        if (s[0]=='.' ||s[0]==',' ||s[0]=='?' ||s[0]=='!') str = str.substr(0,str.length()-1) + s + " ";
        else str = str + s + " ";
    }
    str = str.substr(0,str.length()-1);
    cout<<str<<endl;

    return 0;

}
