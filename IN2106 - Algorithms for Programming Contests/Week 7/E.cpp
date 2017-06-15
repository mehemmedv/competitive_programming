#include <bits/stdc++.h>
using namespace std;

struct Point_2
{
    double  x, y;
} poly[1001000];

bool calc(int lll, int rrr, Point_2 t){
    double d1 = (poly[lll].x - poly[rrr].x) * (poly[lll].x - poly[rrr].x);
    d1 += (poly[lll].y - poly[rrr].y) * (poly[lll].y - poly[rrr].y);

    double d2 = (poly[lll].x - t.x) * (poly[lll].x - t.x);
    d2 += (poly[lll].y - t.y) * (poly[lll].y - t.y);

    double d3 = (t.x - poly[rrr].x) * (t.x - poly[rrr].x);
    d3 += (t.y - poly[rrr].y) * (t.y - poly[rrr].y);
    d1 = sqrt(d1);
    d2 = sqrt(d2);
    d3 = sqrt(d3);
    if(d1 >= d2 + d3)
        return true;
    return false;
}

bool calc(Point_2 p, int len)
{
    double minx = poly[0].x;
    double maxx = poly[0].x;
    double miny = poly[0].y;
    double maxy = poly[0].y;
    for (int i = 1 ; i < len ; i++)
    {
        Point_2 q = poly[i];
        minx = min(q.x, minx);
        maxx = max(q.x, maxx);
        miny = min(q.y, miny);
        maxy = max(q.y, maxy);
    }

    if (p.x < minx || p.x > maxx || p.y < miny || p.y > maxy)
        return false;

    bool res = false;
    int j = len - 1;
    for (int i = 0; i < len ; j = i++)
    {
        if ((poly[i].y > p.y) != (poly[j].y > p.y))
            if(p.x < (poly[j].x - poly[i].x) * (p.y - poly[i].y)/(poly[j].y - poly[i].y) + poly[i].x)
                res = !res;
    }
    if(res == true)
        return res;
    j = len - 1;
    for (int i = 0; i < len ; j = i++)
    {
        if(calc(j, i, p) == true)
            return true;
    }

    return false;
}

bool used[306][306];


struct Point
{

    double x, y;
    Point(double x = 0, double y = 0)
    {
        this->x = x;
        this->y = y;
    }
    double len2() const
    {
        return x*x + y*y;
    }
};

Point operator+ (Point a, Point b)
{
    return Point(a.x+b.x,a.y+b.y);
}

Point operator- (Point a, Point b)
{
    return Point(a.x-b.x,a.y-b.y);
}

vector<Point> v, hull;
int i, n, cur;
double p;

int TurnLeft(Point a, Point b, Point c)
{
    Point p = b - a, q = c - b;
    return p.x * q.y > q.x * p.y;
}

int f(Point a, Point b)
{
    a = a - v[0];
    b = b - v[0];
    if(a.x * b.y == b.x * a.y)
        return a.len2() < b.len2();
    return a.x * b.y > b.x * a.y;
}


int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int t, nnn;
    cin>>t;
    int a1, b1, res;
    double a, b;
    for(int cc = 1; cc <= t; ++cc)
    {
        v.clear();
        memset(used, 0, sizeof(used));
        cin>>nnn;
        int cnt = 0;
        for(int i = 0; i < nnn; ++i)
        {
            cin>>a>>b;
            Point_2 temp;
            temp.x = a;
            temp.y = b;
            poly[cnt++] = temp;
            if((a - (int)a == 0.0) && (b - (int)b == 0.0))
                used[(int)a][(int)b] = true;
        }


        Point_2 temp1;
        int say = 0;
        for(int i = 0; i <= 300; ++i)
            for(int j = 0; j <= 300; ++j){
                temp1.x = i;
                temp1.y = j;
                used[i][j] = used[i][j] | calc(temp1, cnt);
                if(used[i][j] == true){
                    ++say;
                    v.push_back(Point(i, j));
                }
            }

        if(v.size() < 3){
            cout<<"Case #"<<cc<<":"<<endl;
            cout<<v.size()<<endl;
            for(int i = 0; i < v.size(); ++i)
                cout<<v[i].x<<" "<<v[i].y<<endl;
            continue;
        }

        //cout<<"xaxa "<<v.size()<<endl;

        for(i = 1; i < say; ++i)
        {
            if (v[i].x < v[0].x)
                swap(v[i],v[0]);
            if ((v[i].x == v[0].x) && (v[i].y < v[0].y))
                swap(v[i], v[0]);
        }



        sort(v.begin() + 1, v.end(), f);
        v.push_back(v[0]);
        say++;

        for(cur = 1, i = 2; i < say; ++i)
        {
            while( (cur > 0) && !TurnLeft(v[cur-1], v[cur], v[i]))
                --cur;
            v[++cur] = v[i];
        }
        if(cur == 1){
            cout<<"Case #"<<cc<<":"<<endl;
            cout<<2<<endl;
            cout<<v[0].x<<" "<<v[0].y<<endl;
            cout<<v[say-2].x<<" "<<v[say-2].y<<endl;
            continue;
        }
        cout<<"Case #"<<cc<<":"<<endl;
        cout<<cur<<endl;
        for(int i = 0; i < cur; ++i){
            cout<<v[i].x<<" "<<v[i].y<<endl;
        }

    }
    return 0;
}
