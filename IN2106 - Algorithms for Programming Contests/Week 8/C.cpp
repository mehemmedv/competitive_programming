#include <bits/stdc++.h>

using namespace std;

struct Point
{
    long double x;
    long double y;
    long double z;
    Point()
    {
        x = 0, y = 0, z = 1;
    }
};

Point new_point(long double x, long double y, long double z)
{
    Point res;
    res.x = x;
    res.y = y;
    res.z = z;
    return res;
}

bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x))
        if(q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
            return true;
    return false;
}

int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;
    if(val > 0)
        return 1;
    return 2;

}

bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    if (o1 != o2 && o3 != o4)
        return true;
    if (o1 == 0 && onSegment(p1, p2, q1))
        return true;
    if (o2 == 0 && onSegment(p1, q2, q1))
        return true;
    if (o3 == 0 && onSegment(p2, p1, q2))
        return true;
    if (o4 == 0 && onSegment(p2, q1, q2))
        return true;
    return false;
}

int cnt[1010];
long double x[1010][1010], y[1010][1010];

vector<int> v[1010];

bool used[1010];
int say[1010];

void bfs(vector<int> cur)
{
    for(int i : cur)
        say[i] = 0;

    queue<int> q;
    for(int i : cur)
        q.push(i), used[i] = true;

    while(!q.empty())
    {
        int temp = q.front();
        q.pop();

        for(int i : v[temp])
        {
            if(used[i] == false)
            {
                q.push(i);
                used[i] = true;
                say[i] = say[temp] + 1;
            }
        }
    }
}

int main()
{
    int t, n;
    cin >> t;
    long double xbeg, ybeg, xend, yend;

    for(int c = 1; c <= t; ++c)
    {
        memset(used, 0, sizeof(used));
        for(int i = 0; i < 1000; ++i)
            say[i] = 1000000000;

        vector<int> beg;
        vector<int> vend;

        for(int i = 0; i < 1000; ++i)
            v[i].clear();

        cin>>n;
        cin>>xbeg>>ybeg>>xend>>yend;

        for(int i = 1; i <= n; ++i)
        {
            cin>>cnt[i];
            for(int j = 1; j <= cnt[i]; ++j)
                cin>>x[i][j]>>y[i][j];
        }

        for(int i = 1; i <= n; ++i)
            for(int j = i + 1; j <= n; ++j)
            {
                bool flag = false;

                for(int o = 1; o < cnt[i]; ++o)
                {
                    for(int k = 1; k < cnt[j]; ++k)
                    {
                        Point l1 = new_point(x[i][o], y[i][o], 1);
                        Point l2 = new_point(x[i][o+1], y[i][o+1], 1);

                        Point r1 = new_point(x[j][k], y[j][k], 1);
                        Point r2 = new_point(x[j][k+1], y[j][k+1], 1);

                        if(doIntersect(l1, l2, r1, r2) == true)
                        {
                            flag = true;
                            v[i].push_back(j);
                            v[j].push_back(i);
                            break;
                        }
                    }
                    if(flag == true)
                        break;
                }
            }

        Point beg_p = new_point(xbeg, ybeg, 1);
        Point end_p = new_point(xend, yend, 1);

        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j < cnt[i]; ++j)
            {
                Point l1 = new_point(x[i][j], y[i][j], 1);
                Point l2 = new_point(x[i][j+1], y[i][j+1], 1);
                if(doIntersect(l1, l2, beg_p, beg_p))
                {
                    beg.push_back(i);
                    break;
                }
            }
        }

        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j < cnt[i]; ++j)
            {
                Point l1 = new_point(x[i][j], y[i][j], 1);
                Point l2 = new_point(x[i][j+1], y[i][j+1], 1);
                if(doIntersect(l1, l2, end_p, end_p))
                {
                    vend.push_back(i);
                    break;
                }
            }
        }

        bfs(beg);

        int ans = 1000000000;

        for(int i : vend)
            ans = min(ans, say[i]);

        cout<<"Case #"<<c<<": ";
        if(ans > 100000)
            cout<<"impossible"<<endl;
        else
            cout<<ans<<endl;

    }

    return 0;
}
