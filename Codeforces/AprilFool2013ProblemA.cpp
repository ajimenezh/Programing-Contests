#include <iostream>
#include <sstream>
#include <vector>
#include <string>
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

    string s = "Washington Adams Jefferson Madison Monroe Adams Jackson Van Buren Harrison Tyler Polk Taylor Fillmore Pierce Buchanan Lincoln Johnson Grant Hayes Garfield Arthur Cleveland Harrison Cleveland McKinley Roosevelt Taft Wilson Harding Coolidge Hoover Roosevelt Truman Eisenhower Kennedy Johnson Nixon Ford Carter Reagan";

    stringstream ss(s);

    string str;
    vector<string> pres;
    while (ss>>str) pres.push_back(str);

    int a;
    cin>>a;
    if (a<8) cout<<pres[a-1]<<endl;
    else if (a==8) cout<<pres[a-1]<<" "<<pres[a]<<endl;
    else cout<<pres[a]<<endl;

    return 0;

}
