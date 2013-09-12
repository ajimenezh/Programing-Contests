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

int n,k;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>k;
    string s;

    if (k>n) {
        cout<<-1;
    }
    else if (k>=2) {
        for (int i=0; i<(n-(k-2)); i++) {
            s += "a";
            i++;
            if (i<(n-(k-2))) s += "b";
        }
        for (int i=2; i<k; i++) {
            s = s + char('a'+i);
        }
        cout<<s;
    }
    else {
        if (k==1&&n==1) {
            cout<<"a";
        }
        else cout<<-1;
    }

    return 0;

}
