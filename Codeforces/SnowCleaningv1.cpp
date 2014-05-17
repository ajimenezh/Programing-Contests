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
#include <fstream>

using namespace std;

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

int boardSize;
int salary;
int snowFine;
int cnt;
ofstream debug;
bool mapa[51][51];
bool vis[51][51];
vector<pair<int,int> > people;
int dirx[4] = {1,0,-1,0};
int diry[4] = {0,1,0,-1};
char dir[4] = {'D','R','U','L'};

struct cloud {
    int cx,cy,probCenter;
    int r, probSize;
    int life;
    set<pair<int,int> > points;
    bool person;
    cloud(vector<int> snow) {
        life = 1;
        int n = snow.size();
        n /= 2;
        for (int i=0; i<n; i++) {
            points.insert(make_pair(snow[2*i],snow[2*i+1]));
        }
        cx = centerMassX();
        cy = centerMassY();

        person = 0;

        r = radious();
    }
    cloud() {
        cx = 0; cy = 0;
        probCenter = 100;
        r = 0;
        probSize = 100;
        life = 1;

        person = 0;
    }
    bool operator == (cloud tmp) {
        return abs(cx - tmp.cx) + abs(cy - tmp.cy) < 6 + (r + tmp.r)/2;
    }
    void update(vector<int> snow) {
        life++;
        int n = snow.size();
        n /= 2;
        for (int i=0; i<n; i++) {
            points.insert(make_pair(snow[2*i],snow[2*i+1]));
        }
        cx = centerMassX();
        cy = centerMassY();

        r = radious();
    }
    int centerMassX() {
        int n = points.size();
        int c = 0;
        rep(it,points) {
            c += (*it).first;
        }
        int d = c / n;
        probCenter = (c - d*n)*100/n;
        if ((d+1)*n-c < c - d*n) {
            d++;
            probCenter = (d*n-c)*100/n;
        }
        return d;
    }
    int centerMassY() {
        int n = points.size();
        int c = 0;
        rep(it,points) {
            c += (*it).second;
        }
        int d = c / n;
        int p = (c - d*n)*100/n;
        if ((d+1)*n-c < c - d*n) {
            d++;
            p = (d*n-c)*100/n;
        }
        probCenter = probCenter*p/100;
        return d;
    }
    int radious() {
        int tmp = 0;

        rep(it,points) {
            rep(it2,points) {
                tmp = max(tmp,abs((*it).first - (*it2).first));
                tmp = max(tmp,abs((*it).second - (*it2).second));
            }
        }
        return tmp;
    }
};

vector<cloud> clouds;

void init(int _boardSize, int _salary, int _snowFine) {
    boardSize = _boardSize;
    salary = _salary;
    snowFine = _snowFine;

    for (int i=0; i<boardSize; i++) {
        for (int j=0; j<boardSize; j++) {
            mapa[i][j] = 0;
        }
    }
}

vector<cloud> searchClouds() {

    for (int i=0; i<boardSize; i++) {
        for (int j=0; j<boardSize; j++) {
            vis[i][j] = 0;
        }
    }

    vector<cloud> newClouds;

    for (int i=0; i<boardSize; i++) {
        for (int j=0; j<boardSize; j++) if (!vis[i][j] && mapa[i][j]) {
            vector<int> points;
            //cerr<<i<<" "<<j<<endl;
            //cerr<<newClouds.size()<<endl;
            for (int p=0; p<6&&(p+i)<boardSize; p++) {
                for (int r=0; r<6&&(r+j)<boardSize; r++) {
                    if (mapa[i][j]) {
                        points.push_back(i+p);
                        points.push_back(j+r);
                    }
                    vis[p+i][r+j] = 1;
                }
            }
            cloud c = cloud(points);
            bool exists = 0;
            for (int k=0; k<clouds.size(); k++) {
                if (clouds[k]==c) {
                    exists = 1;
                    clouds[k].update(points);
                    newClouds.push_back(clouds[k]);
                    break;
                }
            }
            if (!exists) newClouds.push_back(c);
        }
    }

    return newClouds;

}

bool nearby(int x, int y) {

    for (int i=0; i<people.size(); i++) {
        if (max(abs(people[i].first-x),abs(people[i].second-y))<6) {
            return 1;
        }
    }

    return 0;
}

vector<string> nextDay(vector<int> snowFalls) {
    vector<string> moves;

    int k = snowFalls.size();

    for (int i=0; i<k; i+=2) {
        mapa[snowFalls[i]][snowFalls[i+1]] = 1;
    }

    clouds = searchClouds();

    //for (int i=0; i<clouds.size(); i++) {
    //    cerr<<"La nube "<<i<<" esta en la posicion "<<clouds[i].cx<<" "<<clouds[i].cy<<endl;
    //}

    for (int k=0; k<people.size(); k++) {
        if (!mapa[people[k].first][people[k].second]) {
            for (int i=0; i<4; i++) {

                if (people[k].first+dirx[i]<0 || people[k].first+dirx[i]>=boardSize) continue;
                if (people[k].second+diry[i]<0 || people[k].second+diry[i]>=boardSize) continue;

                if (!mapa[people[k].first+dirx[i]][people[k].second+diry[i]]) continue;

                stringstream ss;
                ss<<"M ";
                ss<<k;
                ss<<" ";
                ss<<dir[i];
                moves.push_back(ss.str());

                people[k].first += dirx[i];
                people[k].second += diry[i];

                mapa[people[k].first][people[k].second] = 0;

                break;
            }
        }
        else {
            mapa[people[k].first][people[k].second] = 0;
        }
    }

    for (int i=0; i<clouds.size(); i++) {
        if (cnt<99 && !clouds[i].person && !nearby(clouds[i].cx,clouds[i].cy)) {
            stringstream ss;
            ss<<"H ";
            ss<<clouds[i].cx;
            ss<<" ";
            ss<<clouds[i].cy;
            moves.push_back(ss.str());
            cnt++;

            mapa[clouds[i].cx][clouds[i].cy] = 0;

            clouds[i].person = 1;

            people.push_back(make_pair(clouds[i].cx,clouds[i].cy));
        }
    }

    return moves;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    debug.open("C:\\Users\\Alex\\Documents\\Projects\\Codeforces\\bin\\Debug\\Debug.txt");

    string s;

    cin>>boardSize;
    cin>>salary;
    cin>>snowFine;

    init(boardSize,salary,snowFine);

    vector<int> snowFalls;
    vector<string> ret;

    for (int i=0; i<2000; i++) {
        int snowCnt;
        int tmp;

        scanf("%d",&snowCnt);
        snowFalls.clear();

        for (int j=0; j<2*snowCnt; j++) {
            cin>>tmp;
            snowFalls.push_back(tmp);
        }

        ret = nextDay(snowFalls);

        cout<<ret.size()<<endl;
        for (int j=0; j<ret.size(); j++) {
            cout<<ret[j]<<endl;
        }
        cout.flush();
    }

    debug.close();

    return 0;

}
