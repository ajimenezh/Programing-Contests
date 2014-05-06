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

map<vector<vector<int> >, int> dist;
queue<vector<vector<int> > > q;

int main() {

    vector<vector<int> > v(3, vector<int>(3,0));

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            v[i][j] = i*3 + j;
        }
    }

    dist[v] = 1;
    q.push(v);

    int k = 0;
    // 9! = 362880
    while (!q.empty()) {
        v = q.front();
        q.pop();
        int p = dist[v];

        //cout<<k++<<" "<<p<<endl;

        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                int x = i+1;
                if (x<3) {
                    swap(v[i][j], v[x][j]);
                    if (!dist[v]) {
                        dist[v] = p + 1;
                        q.push(v);
                    }
                    swap(v[i][j], v[x][j]);
                }
                int y = j+1;
                if (y<3) {
                    swap(v[i][j], v[i][y]);
                    if (!dist[v]) {
                        dist[v] = p + 1;
                        q.push(v);
                    }
                    swap(v[i][j], v[i][y]);
                }
            }
        }
    }

    int t;
    cin>>t;

    string s;
    getline(cin,s);
    for (int i=0; i<t; i++) {
        getline(cin,s);
        map<string, int> id;
        int cnt = 0;
        for (int k=0; k<3; k++) {
            getline(cin,s);
            //cout<<s<<endl;
            for (int j=0; j<s.length(); j++) {
                if (s[j]==',') s[j] = ' ';
                if (j<s.length()-1 && s[j]==' ' && s[j+1]==',') s[j] = '-';
            }
            stringstream ss(s);
            while (ss>>s) id[s] = cnt++;
        }
        getline(cin,s);
        for (int k=0; k<3; k++) {
            getline(cin,s);
            for (int j=0; j<s.length(); j++) {
                if (s[j]==',') s[j] = ' ';
                if (j<s.length()-1 && s[j]==' ' && s[j+1]==',') s[j] = '-';
            }
            stringstream ss(s);
            cnt = 0;
            while (ss>>s) v[k][cnt++] = id[s];
        }

        //for (int k=0; k<3; k++) {
        //    for (int j=0; j<3; j++) cout<<v[k][j]<<" ";
        //    cout<<endl;
        //}

        cout<<dist[v]-1<<endl;
    }

    return 0;

}
