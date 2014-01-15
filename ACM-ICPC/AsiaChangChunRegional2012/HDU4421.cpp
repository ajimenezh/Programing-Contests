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
#include <stack>
#include <cstdio>
#include <cstring>

using namespace std;

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

#define clause pair<int,int>
#define makecl make_pair<int,int>

int n, m;
char Pattern[502][502];

const int NN = 1000000;

/*** Strongly connected components ***/

int teller, vlowlink[NN], vlink[NN];
stack<int> S;
int situatie[NN]; // 0 = not seen yet, 1 = in stack, 2 = processed
vector<int> adj[NN];
int sccnr[NN], cur;

void sccrec (int v) {
    vlink[v] = vlowlink[v] = teller++;
    S.push(v);
    situatie[v] = 1;
    int j, buur;
    for (j = adj[v].size()-1; j >= 0; j--)
        if (situatie[buur = adj[v][j]] < 2) {
            if (situatie[buur] == 0)
                sccrec(buur);
        vlowlink[v] = min(vlowlink[v], vlowlink[buur]);
    }
    if (vlowlink[v] == vlink[v]) {
        int w;
        do {
            sccnr[w = S.top()] = cur;
            situatie[w] = 2;
            S.pop();
        }
        while (w != v);
        cur++;
    }
}

void strongly_connected_components (int n) {
    memset(situatie, 0, sizeof(situatie));
    teller = cur = 0;
    for (int i = 0; i < n; i++)
        if (situatie[i] < 2)
            sccrec(i);
}

/*** 2SAT ***/

// Returns whether there is a solution to an equation of the form:
// true = (A1 || A2) && (B1 || B2) && ...
// where Xi and Yj can be equal statements or each others negation
// K = number of statements (1 t/m K), C = number of clauses

clause Cl[NN]; // The clauses: Cl[i].first || Cl[i].second (-a = !a)

bool twosat (int K, int C) {
    for (int i = 0; i <= 2*K; i++)
        adj[i].clear();
    for (int i = 0; i < C; i++) {
        //adj[K - Cl[i].first].push_back(K + Cl[i].second);
        //adj[K - Cl[i].second].push_back(K + Cl[i].first);
        adj[Cl[i].first].push_back(Cl[i].second);
    }
    strongly_connected_components(2 * K);
    for (int i = 0; i < K; i++)
        if (sccnr[i] == sccnr[i+K])
        return false;
    return true;
}

int b[510][510];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n;
    while (scanf("%d",&n)!=EOF) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                scanf("%d",&b[i][j]);
            }
        }
        bool good = 1;
        for (int t=0; t<31; t++) {
            int k = 0;
            for (int i=0; i<n; i++) {
                for (int j=i+1; j<n; j++) {
                    if (i%2!=0 && j%2!=0) {
                        if (b[i][j]&(1<<t)) {

                            // A | B == 1

                            Cl[k++] = make_pair(i,j+n);
                            Cl[k++] = make_pair(j,i+n);
                        }
                        else {

                            // A | B == 0

                            Cl[k++] = make_pair(i+n,i);
                            Cl[k++] = make_pair(j+n,j);
                        }
                    }
                    else if (i%2==0 && j%2==0) {
                        if (b[i][j]&(1<<t)) {

                            // A & B == 1

                            Cl[k++] = make_pair(i,i+n);
                            Cl[k++] = make_pair(j,j+n);
                        }
                        else {

                            // A & B == 0

                            Cl[k++] = make_pair(i+n,j);
                            Cl[k++] = make_pair(j+n,i);
                        }
                    }
                    else {
                        if(b[i][j] & (1<<t)){

                            // A ^ B == 1

                            Cl[k++] = make_pair(i,j+n);
                            Cl[k++] = make_pair(i+n,j);
                            Cl[k++] = make_pair(j,i+n);
                            Cl[k++] = make_pair(j+n,i);
                        }
                        else{

                            // A ^ B == 0

                            Cl[k++] = make_pair(i,j);
                            Cl[k++] = make_pair(i+n,j+n);
                            Cl[k++] = make_pair(j,i);
                            Cl[k++] = make_pair(j+n,i+n);
                        }
                    }
                }
            }
            if (!twosat(n,k)) {
                good = 0;
                break;
            }
        }
        if(good) printf("YES\n");
        else printf("NO\n");
    }

    return 0;

}
