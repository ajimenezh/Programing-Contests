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

int a,b;
int m[21][21];
vector<string>  vs;

string f(int x, int y, int xx, int yy) {
    string s1,s2;
    for (int i=x; i<xx; i++) for (int j=y; j<yy; j++) s1 += m[i][j];
    for (int i=xx-1; i>=x; i--) for (int j=yy-1; j>=y; j--) s2 += m[i][j];
    if (s2<s1) s1 = s2;
    if ((xx-x)==(yy-y)) {
        s2 = "";
        for (int i=y; i<yy; i++) for (int j=xx-1; j>=x; j--) s2 += m[j][i];
        if (s2<s1) s1 = s2;
        s2 = "";
        for (int i=yy-1; i>=y; i--) for (int j=x; j<xx; j++) s2 += m[j][i];
        if (s2<s1) s1 = s2;
    }
    return s1;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>a>>b;
    for (int i=0; i<a; i++) {
        string s;
        cin>>s;
        for (int j=0; j<b; j++) m[i][j] = s[j];
    }

    int n = 0;
    int sx = a; int sy = b;
    for (int x=1; x<=a; x++) for (int y=1; y<=b; y++) if (a%x==0 && b%y==0) {
        vs.clear();
        for (int xx=0; xx<a/x; xx++) for (int yy=0; yy<b/y; yy++) vs.push_back(f(xx*x,yy*y,xx*x+x,yy*y+y));
        bool good = true;
        sort(vs.begin(),vs.end());
        //cout<<x<<" "<<y<<endl; for (int s=0; s<vs.size(); s++) cout<<vs[s]<<endl;
        for (int s=1; s<vs.size(); s++) if (vs[s-1]==vs[s]) good = false;
        //cout<<good<<endl;
        if (good) {
            n++;
            if (sx*sy>x*y) {sx = x; sy = y;}
        }
    }

    printf("%d\n%d %d\n",n,sx,sy);

    return 0;

}
