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

map<int,int> id;
int n;

int par[2000010];
int rk[2000010];

int find(int a) {
    if (a==par[a]) return a;
    par[a] = find(par[a]);
    return par[a];
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a==b) return;

    if (rk[a]<rk[b]) {
        par[a] = b;
    }
    else if (rk[a]>rk[b]) {
        par[b] = a;
    }
    else {
        rk[a]++;
        par[b] = a;
    }
}

int main() {

    int a,b;
    cin>>a>>b;

    for (int i=0; i<2000010; i++) {
        par[i] = i;
        rk[i] = 0;
    }

    id[a] = n++;
    id[b] = n++;

    //freopen("input.txt","r",stdin);
    freopen("phone_call.log","r",stdin);

    int x, y;
    int k = 0;
    int res = -1;
    while (cin>>x>>y) {
        if (id.find(x)==id.end()) id[x] = n++;
        if (id.find(y)==id.end()) id[y] = n++;

        //cout<<x<<" "<<id[x]<<endl;

        merge(id[x], id[y]);

        if (find(0)==find(1)) {
            res = k;
            //cout<<"hola"<<endl;
            break;
        }
        k++;
    }

    //cout<<n<<endl;

    if (res==-1) cout<<"Not connected"<<endl;
    else cout<<"Connected at "<<res<<endl;

    return 0;

}
