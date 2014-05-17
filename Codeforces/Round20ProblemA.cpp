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

string s;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>s;
    bool found = 0;
    string str;

    for (int i=0; i<s.length(); i++) {
        if (s[i]=='/') {
            if (found);
            else {
                str += "/";
                found = 1;
            }
        }
        else {
            found = 0;
            str += s[i];
        }
    }

    int k = 0;
    int i = str.length()-1;
    while (i>0 && str[i]=='/') {
        i--; k++;
    }

    str = str.substr(0,str.length()-k);

    cout<<str<<endl;

    return 0;

}
