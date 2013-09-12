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

int t;
int a,b;
char c;

void swap(int &p, int &q) {
    int tmp = p;
    p = q;
    q = tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>t;
    for (int tt=0; tt<t; tt++) {
        cin>>a>>c>>b;
        while (a!=1 || b!=1) {
            if (a<b) {
                cout<<"L";
                b -= a;
            }
            else {
                cout<<"R";
                a -= b;
            }
            swap(a,b);
            //cout<<a<<" "<<b<<endl;
        }
        cout<<endl;
    }

    return 0;

}
