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

char buf[50];
string s;
int tab[8][8];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    getline(cin,s);

    int x,y;
    for (int i=0; i<8; i++) for (int j=0; j<8; j++) tab[i][j] = 0;

    x = s[0]-'a';
    y = s[1]-'1';

    tab[x][y] = 2;

    for (int i=0; i<8; i++) tab[i][y] = 1;
    for (int i=0; i<8; i++) tab[x][i] = 1;

    tab[x][y] = 2;

    x = s[3]-'a';
    y = s[4]-'1';

    tab[x][y] = 2;

    for (int i=0; i<8; i++) if (!tab[i][y]) tab[i][y] = 1;
    for (int i=0; i<8; i++) if (!tab[x][i]) tab[x][i] = 1;

    x = s[6]-'a';
    y = s[7]-'1';


    for (int i=-1; i<2; i++) for (int j=-1; j<2; j++) {
        if (i+x<0 || j+y<0) continue;
        if (i+x>=8 || y+j>=8) continue;
        if (!tab[i+x][j+y]) tab[i+x][j+y] = 1;
    }

    x = s[9]-'a';
    y = s[10]-'1';

    bool check = true;

    for (int i=0; i<8; i++) {for (int j=0; j<8; j++) cout<<tab[i][j]; cout<<endl;}

    for (int i=-1; i<2; i++) for (int j=-1; j<2; j++) {
        if (i+x<0 || j+y<0) continue;
        if (i+x>=8 || y+j>=8) continue;
        if (!tab[i+x][j+y]) check = false;
        if (tab[i+x][j+y]==2) {

            bool good = false;

            x = s[0]-'a';
            y = s[1]-'1';

            if (x!=i+x || y!=j+y) {

                for (int ii=0; ii<8; ii++) if (x+i==i && ii==j+y) good = true;
                for (int ii=0; ii<8; ii++) if (y+j==j && ii==i+x) good = true;
            }

            x = s[3]-'a';
            y = s[4]-'1';

            if (x!=i+x || y!=j+y) {

                for (int ii=0; ii<8; ii++) if (x+i==i && ii==j+y) good = true;
                for (int ii=0; ii<8; ii++) if (y+j==j && ii==i+x) good = true;
            }

            if (!good) check = false;
            cout<<good<<endl;
        }
    }

    if (check) {
        cout<<"CHECKMATE";
    }
    else{
        cout<<"OTHER";
    }

    return 0;

}
