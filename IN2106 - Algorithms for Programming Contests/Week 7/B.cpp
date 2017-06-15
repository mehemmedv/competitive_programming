#include <bits/stdc++.h>
using namespace std;

struct Point
{
    double  x, y;
} poly[10010];

bool calc(Point p, int len)
{
    double minx = poly[0].x;
    double maxx = poly[0].x;
    double miny = poly[0].y;
    double maxy = poly[0].y;
    for (int i = 1 ; i < len ; i++)
    {
        Point q = poly[i];
        minx = min(q.x, minx);
        maxx = max(q.x, maxx);
        miny = min(q.y, miny);
        maxy = max(q.y, maxy);
    }

    if (p.x < minx || p.x > maxx || p.y < miny || p.y > maxy)
        return false;

    bool res = false;
    for (int i = 1; i < len ; i += 2)
    {
        int j = i - 1;
        if ((poly[i].y > p.y) != (poly[j].y > p.y))
            if(p.x < (poly[j].x - poly[i].x) * (p.y - poly[i].y)/(poly[j].y - poly[i].y) + poly[i].x)
                res = !res;
    }
    return res;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n;
    cin>>t;
    int a1, b1, res, a, b;
    for(int cc = 1; cc <= t; ++cc)
    {
        Point temp1;

        cin>>a1>>b1;
        temp1.x = a1;
        temp1.y = b1;
        cin>>n;
        int cnt = 0;
        for(int i = 0; i < n; ++i)
        {
            cin>>a>>b;
            Point temp;
            temp.x = a;
            temp.y = b;
            poly[cnt++] = temp;
            cin>>a>>b;
            temp.x = a;
            temp.y = b;
            poly[cnt++] = temp;
        }

        cout<<"Case #"<<cc<<":";
        bool flag = calc(temp1, cnt);

        if(flag == false)
            cout<<" too bad"<<endl;
        else
            cout<<" jackpot"<<endl;
    }
    return 0;
}
