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

int n;
int a[310];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i];
    int i = 0;
    int k = 1;
    int cnt = 0;
    while (cnt<1000000) {
        if (a[i]) {
            a[i]--;
            cout<<"P";
            cnt++;
        }
        if (k==1) {
            i++;
            if (i==n) {
                if (!a[i-1]) {
                    i -= 2;
                    k = -1;
                    cout<<"L";
                    cnt++;
                }
                else {
                    cout<<"LRPL";
                    a[i-1]--;
                    i -= 2;
                    k = -1;
                    cnt += 4;
                }
            }
            else {
                cout<<"R";
                cnt++;
            }
        }
        else {
            i--;
            if (i==-1) {
                if (!a[i+1]) {
                    i += 2;
                    k = 1;
                    cout<<"R";
                    cnt++;
                }
                else {
                    cout<<"RLPR";
                    a[i+1]--;
                    i += 2;
                    k = +1;
                    cnt += 4;
                }
            }
            else {
                cout<<"L";
                cnt++;
            }
        }
    }

    return 0;

}
