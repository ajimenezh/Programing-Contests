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

string s1;
string s2;
int days;
int m[] = {31,28,31,30,31,30,31,31,30,31,30,31};

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>s1>>s2;
    int y1,y2, m1, m2, d1, d2;
    if (s1>s2) {
        string tmp = s1;
        s1 = s2;
        s2 = tmp;
    }

    for (int i=0; i<s1.length(); i++) if (s1[i]==':') s1[i] = ' ';
    for (int i=0; i<s1.length(); i++) if (s2[i]==':') s2[i] = ' ';

    stringstream ss1(s1);
    stringstream ss2(s2);

    ss1>>y1>>m1>>d1;
    ss2>>y2>>m2>>d2;

    for (int i=y1; i<y2; i++) {
        if (i%4!=0) days += 365;
        else if (i%4==0 && i%100!=0) days += 366;
        else if (i%4==0 && i%100==0 && i%400!=0) days += 365;
        else days += 366;
    }
    for (int i=1; i<m1; i++) {
        if (i==2) {
            if (y1%4!=0) days -= 28;
            else if (y1%4==0 && y1%100!=0) days -= 29;
            else if (y1%4==0 && y1%100==0 && y1%400!=0) days -= 28;
            else days -= 29;
        }
        else {
            days -= m[i-1];
        }
    }
    days -= d1;
    for (int i=1; i<m2; i++) {
        if (i==2) {
            if (y2%4!=0) days += 28;
            else if (y2%4==0 && y2%100!=0) days += 29;
            else if (y2%4==0 && y2%100==0 && y2%400!=0) days += 28;
            else days -= 29;
        }
        else {
            days += m[i-1];
        }
    }
    days += d2;

    cout<<days<<endl;


    return 0;

}
