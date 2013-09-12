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

int mem[10][10];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n;
    cin>>n;

    for (int i=0; i<=9; i++) {
        if (i==0) {
            for (int j=0; j<=9; j++) {
                mem[i][j] = 1;
            }
        }
        else {
            for (int j=0; j<=9; j++) {
                for (int k=0; k<=9; k++) {
                    mem[i][j] += mem[i-1][k];
                }
                mem[i][j] += mem[i-1][j]*9;
            }
        }
    }

    int f = 1000000000;
    int k = 9;
    int sol[10];
    for (int i=0; i<10; i++) sol[i] = 0;
    bool done = 0;
    while (n>0) {
        int t = n/f;
        n -= t*f;
        f /= 10;
        k--;
        if (t==0 && !done) continue;
        if (t>0 && done) sol[0] += mem[k+1][0];
        done = 1;
        for (int j=1; j<t; j++) {
            sol[j] += mem[k+1][j];
        }
        if (n!=0) sol[t] +=  n;
        else sol[t] ++;
    }

    for (int i=0; i<10; i++) cout<<sol[i]<<endl;

    return 0;

}
