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

string s[2001];
int n;
int res;
bool changed[2001][2001];

void change1(int a, int b, bool flag) {

    if (flag) {
        s[a-1][b]=='1'?s[a-1][b]='0':s[a-1][b]='1';
        s[a][b-1]=='1'?s[a][b-1]='0':s[a][b-1]='1';
    }
    else {
        s[a+1][b]=='1'?s[a+1][b]='0':s[a+1][b]='1';
        s[a][b+1]=='1'?s[a][b+1]='0':s[a][b+1]='1';
    }
    res++;
}

void change2(int a, int b, bool flag) {

    if (flag) {
        changed[a-1][b]=!changed[a-1][b];
        changed[a][b-1]=!changed[a][b-1];
    }
    else{
        changed[a+1][b]=!changed[a+1][b];
        changed[a][b+1]=!changed[a][b+1];
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) cin>>s[i];

    int k=0;

    for (int k=0; k<n; k++) {
        for (int j=0; j<=k; j++) {
            if (changed[j][n-1-k+j]) change1(j,n-1-k+j,1);
            if (changed[n-1-k+j][j]) change1(n-1-k+j,j,0);
            if (s[j][n-1-k+j]=='1') change2(j,n-1-k+j,1);
            if (s[n-1-k+j][j]=='1') change2(n-1-k+j,j,0);
            if (s[j][n-1-k+j]=='1') change1(j,n-1-k+j,1);
            if (s[n-1-k+j][j]=='1') change1(n-1-k+j,j,0);

            //cout<<endl;
            //for (int i=0; i<n; i++) cout<<s[i]<<endl;
        }
    }

    cout<<res<<endl;

    return 0;

}
