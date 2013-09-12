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

int n,m;
int xs,ys;
string s;

bool up[100010];
bool down[100010];
bool l[100010];
bool r[100010];

long long t = 0;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    cin>>xs>>ys>>s;

    while (true) {
        if (s=="UR") {
            if (xs-1<m-ys) {
                t += xs-1;
                xs = 1;
                ys -= xs-1;
                s = "DR";
                if (up[ys]) break;
                up[ys] = 1;
            }
            else if (xs-1>m-ys) {
                t += m-ys;
                ys = m;
                xs += m-ys;
                s = "UL";
                if (r[xs]) break;
                r[xs] = 1;
            }
            else {
                t += xs-1;
                break;
            }
        }
        else if (s=="UL") {
            if (xs-1<ys-1) {
                t += xs-1;
                xs = 1;
                ys -= xs-1;
                s = "DL";
                if (up[ys]) break;
                up[ys] = 1;
            }
            else if (xs-1>ys-1) {
                t += ys-1;
                ys = 1;
                xs += ys-1;
                if (l[xs]) break;
                l[xs] = 1;
                s = "UR";
            }
            else {
                t += xs-1;
                break;
            }
        }
        else if (s=="DL") {
            if (n-xs<ys-1) {
                t += n-xs;
                xs = n;
                ys -= n-xs;
                if (down[ys]) break;
                down[ys] = 1;
                s = "UL";
            }
            else if (n-xs>ys-1) {
                t += ys-1;
                ys = 1;
                xs += ys-1;
                if (l[xs]) break;
                l[xs] = 1;
                s = "DR";
            }
            else {
                t += n-xs;
                break;
            }
        }
        else if (s=="DR") {
            if (n-xs<m-ys) {
                t += n-xs;
                xs = n;
                ys += n-xs;
                if (down[ys]) break;
                down[ys] = 1;
                s = "UR";
            }
            else if (n-xs>m-ys) {
                t += m-ys;
                ys = m;
                xs += m-ys;
                if (r[xs]) break;
                r[xs] = 1;
                s = "DL";
            }
            else {
                t += m-ys;
                break;
            }
        }
    }

    return 0;

}
