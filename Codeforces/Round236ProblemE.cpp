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
#include <bitset>

using namespace std;

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

int n;
int a[2000][2000];
bool f[2000][2000];
bitset<2000> row[2000], column[2000], tmp;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) scanf("%d", &a[i][j]);
    //n = 2000;
    //for (int i=0; i<n; i++) for (int j=0; j<n; j++) a[i][j] = 1;
    for (int i=n-1; i>=0; --i) for (int j=n-1; j>=0; --j) f[i][j] = (a[i][j]>0);
    for (int i=n-1; i>=0; --i) for (int j=n-1; j>=0; --j) {
        if (f[i][j]) row[i].set(j);
        if (f[i][j]) column[j].set(i);
    }

    for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
        if (!f[i][j]) {
            tmp = row[i] & column[j];
            if (tmp.any()) {
                row[i].set(j);
                column[j].set(i);
                row[i] |= row[j];
                column[j] |= column[i];
            }
        }
        else {
            row[i] |= row[j];
            column[j] |= column[i];
        }
    }
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) if (!row[i][j] && !column[j][i]) {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES"<<endl;


    return 0;

}
