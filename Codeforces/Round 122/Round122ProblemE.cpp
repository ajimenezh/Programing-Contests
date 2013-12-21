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

int h12,h13,h14,h23,h24,h34;

bool s1[500000], s2[500000], s3[500000], s4[500000];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>h12>>h13>>h14;
    cin>>h23>>h24;
    cin>>h34;

    int n = 0;
    for (int i=0; i<h12; i++) {
        s2[n++] = 1;
    }
    if (h23+h13<h12) {
        cout<<-1;
        return 0;
    }
    int t = 0;
    if (h13+h23>h12) {
        t = h13+h23-h12;
        while (t>0) {
            s3[n++] = 1;
            h13--;
            h23--;
            t-=2;
        }
        if (t<0 || h13+h23!=h12) {
            cout<<-1;
            return 0;
        }
    }
    for (int i=0; i<h13; i++) s3[i] = 1;

    if (h24+h14+h34<h13+h23) {
        cout<<-1;
        return 0;
    }

    int m = h24+h14+h34;
    for (int i=0; i<m; i++) {
        if (s1[i]!=s2[i] && s2[i]==s3[i]) {
            if (h24>0 && h34>0) {
                s4[i] = 1-s2[i];
                h24--;
                h34--;
            }
            else if (h14>0) {
                s4[i] = 1 - s1[i];
                h14--;
            }
            else {
                cout<<-1;
                return 0;
            }
        }
        else if (s1[i]==s2[i] && s2[i]!=s3[i]) {
            if (h24>0 && h14>0) {
                s4[i] = 1-s2[i];
                h24--;
                h14--;
            }
            else if (h34>0) {
                s4[i] = 1 - s3[i];
                h34--;
            }
            else {
                cout<<-1;
                return 0;
            }
        }
        else if (s1[i]==s3[i] && s2[i]!=s3[i]) {
            if (h34>0 && h14>0) {
                s4[i] = 1-s1[i];
                h34--;
                h14--;
            }
            else if (h24>0) {
                s4[i] = 1 - s2[i];
                h24--;
            }
            else {
                cout<<-1;
                return 0;
            }
        }
    }

    while (h14>0 && h24>0 && h34>0) {
        s4[n++] = 1;
        h14--;
        h24--;
        h34--;
    }

    if (h14>0 || h24>0 || h34>0) {
        cout<<-1;
        return 0;
    }

    cout<<n<<endl;
    for (int i=0; i<n; i++) cout<<(s1[i]?'a':'b'); cout<<endl;
    for (int i=0; i<n; i++) cout<<(s2[i]?'a':'b'); cout<<endl;
    for (int i=0; i<n; i++) cout<<(s3[i]?'a':'b'); cout<<endl;
    for (int i=0; i<n; i++) cout<<(s4[i]?'a':'b'); cout<<endl;

    return 0;

}
