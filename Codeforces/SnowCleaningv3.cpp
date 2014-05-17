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

const int dirx[4] = {1,0,-1,0};
const int diry[4] = {0,1,0,-1};
const char dir[4] = {'D','R','U','L'};
int boardSize;
int salary;
int snowFine;
int cnt;
ofstream debug;
bool mapa[51][51];
bool isPerson[10][10];
int timer;
int q[6000];
bool vis[50][50];
int pre[50][50];

class SnowCleaning {
public:

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

    struct worker {
        int next;
        int tenx;
        int teny;
        int x,y;
        int ox,oy;
        queue<int> moves;
        bool doneMoving;
        bool busy;
        worker() {
        }
        worker(int _x, int _y) {
            x = (_x/5)*5;
            y = (_y/5)*5;
            next = 0;
            ox = x;
            oy = y;
            tenx = 0;
            teny = 1;
            busy = 0;
            doneMoving = 1;
        }
        void update() {

            if (!moves.empty() && !doneMoving) {
                x += dirx[next];
                y += diry[next];
                next = moves.front();
                moves.pop();
            }
            else if (moves.empty() && !doneMoving) {
                x += dirx[next];
                y += diry[next];
                doneMoving = 1;
                if (ox!=boardSize-1) next = 0;
                else next = 1;
                tenx = 0;
                teny = 1;
            }
            else {
                x += dirx[next];
                y += diry[next];


                if (next==0 || next==2) {
                    if (tenx == 0 && teny == 1) {
                        if (x+dirx[next]==ox+5 || x+dirx[next]>=boardSize) {
                            tenx = 2;
                            if (oy==boardSize-1) next = tenx;
                            else if (y+diry[1]==oy+5 || y+diry[1]>=boardSize) {
                                teny = 3;
                                next = 3;
                            }
                            else {
                                next = 1;
                            }
                        }
                    }
                    else if (tenx == 0 && teny == 3) {
                        if (x+dirx[next]==ox+5 || x+dirx[next]>=boardSize) {
                            tenx = 2;
                            if (oy==boardSize-1) next = tenx;
                            else if (y+diry[3]==oy-1 || y+diry[3]<0) {
                                teny = 1;
                                next = 1;
                            }
                            else{
                                next = 3;
                            }
                        }
                    }
                    else if (tenx == 2 && teny == 1) {
                        if (x+dirx[next]==ox-1 || x+dirx[next]<0) {
                            tenx = 0;
                            if (oy==boardSize-1) next = tenx;
                            else if (y+diry[1]==oy+5 || y+diry[1]>=boardSize) {
                                teny = 3;
                                next = 3;
                            }
                            else {
                                next = 1;
                            }
                        }
                    }
                    else if (tenx == 2 && teny == 3) {
                        if (x+dirx[next]==ox-1 || x+dirx[next]<0) {
                            tenx = 0;
                            if (oy==boardSize-1) next = tenx;
                            else if (y+diry[3]==oy-1 || y+diry[3]<0) {
                                teny = 1;
                                next = 1;
                            }
                            else {
                                next = 3;
                            }
                        }
                    }
                }
                else {
                    next = tenx;
                }
                if (ox==boardSize-1) {
                    if (y+diry[3]==oy-1 || y+diry[3]==-1) {
                        next = 1;
                        teny = 1;
                    }
                    else if (y+diry[1]==oy+5 || y+diry[1]==boardSize) {
                        next = 3;
                        teny = 3;
                    }
                    else {
                        next = teny;
                    }
                }
                if (oy==boardSize-1) {
                    if (x+dirx[2]==ox-1 || x+dirx[2]==-1) {
                        next = 0;
                        tenx = 0;
                    }
                    else if (x+dirx[0]==ox+5 || x+dirx[0]==boardSize) {
                        next = 2;
                        tenx = 2;
                    }
                    else {
                        next = tenx;
                    }
                }
            }
        }

        void beginMoving() {
            next = moves.front();
            moves.pop();
            busy = 1;
            doneMoving = 0;
        }
        bool check() {
            if (!moves.empty() || !doneMoving) return 1;
            return 0;
            for (int i=ox; i<min(ox+5,boardSize); i++) {
                for (int j=oy; j<min(oy+5,boardSize); j++) {
                    if (mapa[i][j]) {
                        return 1;
                    }
                }
            }
            return 0;
        }
    };

    vector<cloud> clouds;
    vector<worker> people;

    int init(int _boardSize, int _salary, int _snowFine) {
        boardSize = _boardSize;
        salary = _salary;
        snowFine = _snowFine;

        timer = 0;

        for (int i=0; i<boardSize; i++) {
            for (int j=0; j<boardSize; j++) {
                mapa[i][j] = 0;
            }
        }
        return 0;
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
            if (max(abs(people[i].x-x),abs(people[i].y-y))<6) {
                return 1;
            }
        }

        return 0;
    }

    int nearest(int x, int y) {

        int p = -1;

        for (int i=0; i<people.size(); i++) {
            if (people[i].check()) continue;
            if (2*salary*(2000-timer)<(abs(x-people[i].ox)+abs(y-people[i].oy))*snowFine*25) continue;

            if (p==-1 || abs(x-people[i].ox)+abs(people[i].oy)<abs(x-people[p].ox)+abs(people[p].oy)) {
                p = i;
            }
        }
        return p;
    }

    void makeMoves(int i, int x, int y) {
        x = (x/5)*5;
        y = (y/5)*5;

        cerr<<"Beginning to calculate moves..."<<endl;

        int in = 0, fn = 0;
        for (int k=0; k<50; k++) for (int j=0; j<50; j++) vis[k][j] = 0;

        vis[x][y] = 1;
        q[fn++] = x;
        q[fn++] = y;

        while (in!=fn) {
            int px = q[in++];
            int py = q[in++];

            if (px==people[i].x && py==people[i].y) break;

            for (int j=0; j<4; j++) {
                int ux = px - dirx[j];
                int uy = py - diry[j];

                if (ux>=boardSize || ux<0) continue;
                if (uy>=boardSize || uy<0) continue;
                if (vis[ux][uy]) continue;

                vis[ux][uy] = 1;
                pre[ux][uy] = j;
                q[fn++] = ux;
                q[fn++] = uy;

            }
        }

        queue<int> tmp;

        int px = people[i].x;
        int py = people[i].y;
        //cerr<<x<<" "<<y<<endl;

        while (px!=x || py!=y) {
            tmp.push(pre[px][py]);
            //cerr<<dir[pre[px][py]]<<" "<<px<<" "<<py<<endl;
            int d = pre[px][py];
            px += dirx[d];
            py += diry[d];
        }
        //cerr<<"Done!"<<endl;
        people[i].moves = tmp;

        people[i].ox = x;
        people[i].oy = y;

        return;
    }

    vector<string> nextDay(vector<int> snowFalls) {
        vector<string> moves;

        timer++;

        int k = snowFalls.size();

        for (int i=0; i<k; i+=2) {
            mapa[snowFalls[i]][snowFalls[i+1]] = 1;
        }

        //clouds = searchClouds();

        //for (int i=0; i<clouds.size(); i++) {
        //    cerr<<"La nube "<<i<<" esta en la posicion "<<clouds[i].cx<<" "<<clouds[i].cy<<endl;
        //}

        int n = people.size();

        for (int i=0; i<n; i++) if (!people[i].check()) {
            int d=500000;
            int px=-1,py=-1;
            for (int p=0; p<boardSize; p++) {
                for (int r=0; r<boardSize; r++) {
                    if (!mapa[p][r] || isPerson[p/5][r/5]) continue;
                    if (abs(people[i].ox-p+4)+abs(people[i].oy-r)<d) {
                        d = abs(people[i].ox-p)+abs(people[i].oy-r);
                        px = p;
                        py = r;
                    }
                }
            }
            //cerr<<px<<" "<<py<<endl;
            //cerr<<people[i].ox<<endl;
            if (d==500000) continue;

            isPerson[people[i].ox/5][people[i].oy/5] = 0;
            makeMoves(i,px, py);
            people[i].beginMoving();
            isPerson[px/5][py/5] = 1;

        }

        for (int i=0; i<boardSize; i++) for (int j=0; j<boardSize; j++) if (mapa[i][j]) {
            if (cnt<99 && isPerson[i/5][j/5]==0 && 30*snowFine>salary) {
                people.push_back(worker(i,j));
                stringstream ss;
                ss<<"H ";
                ss<<people[people.size()-1].x;
                ss<<" ";
                ss<<people[people.size()-1].y;
                moves.push_back(ss.str());
                cnt++;

                mapa[people[people.size()-1].x][people[people.size()-1].y] = 0;

                //clouds[i].person = 1;

                isPerson[i/5][j/5] = 1;
            }
        }

        for (int k=0; k<n; k++) if (!people[k].check()) {

            if (people[k].ox==boardSize-1 && people[k].oy==boardSize-1) continue;
            if (people[k].x+dirx[people[k].next]==boardSize || people[k].y+diry[people[k].next]==boardSize) {
                people[k].next = 2;
            }

            stringstream ss;
            ss<<"M ";
            ss<<k;
            ss<<" ";
            ss<<dir[people[k].next];
            moves.push_back(ss.str());

            people[k].update();

            mapa[people[k].x][people[k].y] = 0;
        }

        return moves;
    }
};

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    debug.open("C:\\Users\\Alex\\Documents\\Projects\\Codeforces\\bin\\Debug\\Debug.txt");

    SnowCleaning sn;

    string s;

    cin>>boardSize;
    cin>>salary;
    cin>>snowFine;

    sn.init(boardSize,salary,snowFine);

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

        ret = sn.nextDay(snowFalls);

        cout<<ret.size()<<endl;
        for (int j=0; j<ret.size(); j++) {
            cout<<ret[j]<<endl;
        }
        cout.flush();
    }

    debug.close();

    return 0;

}
