#include <bits/stdc++.h>
using namespace std;

struct Point
{

    double x, y;
    int idx;
    Point(double x = 0, double y = 0, int idx = 0)
    {
        this->x = x;
        this->y = y;
        this->idx = idx;
    }
    double len2() const
    {
        return x*x + y*y;
    }
};



double A, Cx, Cy;

double nl_dbl_dmin;

double distance(Point l, Point r)
{
    return sqrt((l.x-r.x)*(l.x-r.x) + (l.y-r.y)*(l.y-r.y));
}

bool get_line_intersection(Point p0, Point p1, Point p2, Point p3)
{
    double s1_x, s1_y, s2_x, s2_y;
    s1_x = p1.x - p0.x;
    s1_y = p1.y - p0.y;
    s2_x = p3.x - p2.x;
    s2_y = p3.y - p2.y;

    double s, t;
    s = (-s1_y * (p0.x - p2.x) + s1_x * (p0.y - p2.y)) / (-s2_x * s1_y + s1_x * s2_y);
    t = ( s2_x * (p0.y - p2.y) - s2_y * (p0.x - p2.x)) / (-s2_x * s1_y + s1_x * s2_y);

    if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
    {
        // Collision detected
        double i_x = p0.x + (t * s1_x);
        double i_y = p0.y + (t * s1_y);
        if(i_x == p0.x && i_y == p0.y)
            return false;
        if(i_x == p1.x && i_y == p1.y)
            return false;

        return true;
    }
    //cout<<"Not found"<<endl;
    return false; // No collision
}

bool SegmentIntersectRectangle (Point p1, Point p2, Point p3, Point p4, Point p5, Point p6){
    double  x1 = p5.x, y1 = p5.y, x2 = p6.x, y2 = p6.y;
    double minX = min(min(min(p1.x, p2.x), p3.x), p4.x);
    double minY = min(min(min(p1.y, p2.y), p3.y), p4.y);
    double maxX = max(max(max(p1.x, p2.x), p3.x), p4.x);
    double maxY = max(max(max(p1.y, p2.y), p3.y), p4.y);
    // Completely outside.
    if ((x1 <= minX && x2 <= minX) || (y1 <= minY && y2 <= minY) || (x1 >= maxX && x2 >= maxX) || (y1 >= maxY && y2 >= maxY))
        return false;

    double m = (y2 - y1) / (x2 - x1);

    double y = m * (minX - x1) + y1;
    if (y >= minY && y <= maxY) return true;

    y = m * (maxX - x1) + y1;
    if (y >= minY && y <= maxY) return true;

    double x = (minY - y1) / m + x1;
    if (x >= minX && x <= maxX) return true;

    x = (maxY - y1) / m + x1;
    if (x >= minX && x <= maxX) return true;

    return false;
}


vector<Point> v;

bool check(Point l, Point r)
{
    for(int i = 0; i < v.size(); i += 4)
    {
        if(SegmentIntersectRectangle(v[i], v[i+1], v[i+2], v[i+3], l, r) == true)
            return false;
    }
    return true;
}

double dist[1001000];
vector < pair< int, double > > p[1001000];

Point which[100100];
int par[1001000];
int main()
{
    nl_dbl_dmin = std::numeric_limits< double >::denorm_min();

    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    double a, b;
    int n, w, h;

    for(int cc = 1; cc <= t; ++cc)
    {
        v.clear();
        for(int i = 0; i < 1000000; ++i)
            par[i] = -1;
        for(int i = 0; i <= 1000000; ++i)
            p[i].clear(), dist[i] = 2000000000;
        cin>>w>>h>>n;
        int cnt = 1;
        for(int i = 0; i < n; ++i)
        {
            cin>>a>>b>>w>>h;
            Point t1 = Point(a, b, cnt++);
            which[cnt-1] = t1;
            Point t2 = Point(a + w, b, cnt++);
            which[cnt-1] = t2;
            Point t3 = Point(a, b + h, cnt++);
            which[cnt-1] = t3;
            Point t4 = Point(a + w, b + h, cnt++);
            which[cnt-1] = t4;
            v.push_back(t1);
            v.push_back(t2);
            v.push_back(t3);
            v.push_back(t4);
        }
        n = cnt;

        cin>>a>>b;
        Point beg = Point(a, b, 0);
        which[0] = beg;
        cin>>a>>b;
        Point enn = Point(a, b, cnt);
        which[n] = enn;

        for(Point i : v)
        {
            for(Point j : v)
                if(i.idx != j.idx)
                {
                    if(check(i, j) == true)
                    {
                        p[i.idx].push_back(make_pair(j.idx,distance(i, j)));
                        p[j.idx].push_back(make_pair(i.idx,distance(i, j)));
                    }
                }
        }

        for(Point i : v)
        {
            if(check(i, beg) == true)
            {
                p[i.idx].push_back(make_pair(0,distance(i, beg)));
                p[0].push_back(make_pair(i.idx,distance(i, beg)));
            }

            if(check(i, enn) == true)
            {
                p[i.idx].push_back(make_pair(n,distance(i, enn)));
                p[n].push_back(make_pair(i.idx,distance(i, enn)));
            }
        }

        if(check(beg, enn) == true)
        {
            p[0].push_back(make_pair(n,distance(beg, enn)));
            p[n].push_back(make_pair(0,distance(beg, enn)));
        }

        par[0]=-1;
        dist[0]=0;
        set < pair < double, int > > s;
        s.insert(make_pair(0.0, 0));

        while(!s.empty())
        {
            pair < double, int > tmp;
            tmp=(*s.begin());
            s.erase(s.begin());

            for(int i=0; i<p[tmp.second].size(); i++)
            {
                int cost1=p[tmp.second][i].first;
                double cost2=p[tmp.second][i].second;
                if(tmp.first+cost2<dist[cost1])
                {
                    dist[cost1]=tmp.first+cost2;
                    s.insert(make_pair(dist[cost1],cost1));
                    par[cost1]=tmp.second;
                }
            }
        }

        vector < int > ans;
        int k=n;
        while(k!=-1)
        {
            ans.push_back(k);
            k=par[k];
        }

        cout<<"Case #"<<cc<<":";
        for(int i=ans.size()-1; i>=0; i--)
            cout<<" ("<<which[ans[i]].x<<","<<which[ans[i]].y<<")";
        cout<<endl;
    }
    return 0;
}
