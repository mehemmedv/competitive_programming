#include <bits/stdc++.h>

using namespace std;

struct Point
{
    double x;
    double y;
    double z;
    Point()
    {
        x = 0, y = 0, z = 1;
    }
};

struct Line
{
    double x;
    double y;
    double z;
    Line()
    {
        x = 0;
        y = 0;
        z = 0;
    }
};

Point new_point(double x, double y, double z)
{
    Point res;
    res.x = x;
    res.y = y;
    res.z = z;
    return res;
}

double eps = 1e-20;

Point cross_product(Point l, Point r)
{
    Point res;
    res.x = l.y*r.z - l.z*r.y;
    res.y = l.z*r.x - l.x*r.z;
    res.z = l.x*r.y - l.y*r.x;
    return res;
}

Line cross_product(Line l, Line r)
{
    Line res;
    res.x = l.y * r.z - l.z * r.y;
    res.y = l.z * r.x - l.x * r.z;
    res.z = l.x * r.y - l.y * r.x;
    return res;
}

Line new_line(double x, double y, double z)
{
    Line res;
    res.x = x;
    res.y = y;
    res.z = z;
    return res;
}

Line new_line_points(Point l, Point r)
{
    Line ret;
    Point res = cross_product(l, r);
    ret.x = res.x;
    ret.y = res.y;
    ret.z = res.z;
    return ret;
}

Line new_line_point(Point p)
{
    Line res;
    res.x = p.x;
    res.y = p.y;
    res.z = p.z;
    return res;
}

Point new_point_line(Line l)
{
    Point res;
    res.x = l.x;
    res.y = l.y;
    res.z = l.z;
    return res;
}

bool infinite(Line l)
{
    if(l.x == 0.0 && l.y == 0.0 && l.z == 1.0)
        return true;
    return false;
}

bool infinite(Point p)
{
    if(abs(p.z) <= eps)
        return true;
    return false;
}

Line normalize(Line l)
{
    Line res;
    if(infinite(l))
        return l;
    res.x = l.x / sqrt(l.x * l.x + l.y * l.y);
    res.y = l.y / sqrt(l.x * l.x + l.y * l.y);
    res.z = l.z / sqrt(l.x * l.x + l.y * l.y);
    return res;
}

Point normalize(Point p)
{
    Point res;
    if(infinite(p))
        return p;
    res.x = p.x / p.z;
    res.y = p.y / p.z;
    res.z = 1;
    return res;
}

pair<double, double> conv_2D(Point l)
{
    pair<double, double> p;
    normalize(l);
    p.first = l.x;
    p.second = l.y;
    return p;
}

bool valid(Point x1, Point x, Point m)
{
    pair<double, double> p1 = conv_2D(x1);
    pair<double, double> p2 = conv_2D(x);
    pair<double, double> p3 = conv_2D(m);

    int res1 = (p3.first - p1.first)*(p2.first - p3.first);
    int res2 = (p3.second - p1.second)*(p2.second - p3.second);
    if(res1 >= 0 && res2 >= 0)
    {
        return true;
    }
    return false;
}

Point projection(Line l, Point p)
{
    Line dir = cross_product(l, new_line(0,0,1));
    Line m = cross_product(new_line_point(p), new_line(dir.y,-dir.x,0));
    return new_point_line(cross_product(m, l));
}

Point x1[3], x2[3];

int main()
{
    Line inf = Line();
    inf.z = 1;

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for(int c = 1; c <= t; ++c)
    {
        double sumx = 0, sumy = 0;

        for(int i = 0; i < 3; ++i){
            x1[i] = Point();
            cin>>x1[i].x>>x1[i].y;
            sumx += x1[i].x;
            sumy += x1[i].y;
        }

        double mid1x = (x1[0].x + x1[1].x) / 2.0;
        double mid1y = (x1[0].y + x1[1].y) / 2.0;
        Point mid1 = Point();
        mid1.x = mid1x;
        mid1.y = mid1y;

        double mid2x = (x1[0].x + x1[2].x) / 2.0;
        double mid2y = (x1[0].y + x1[2].y) / 2.0;
        Point mid2 = Point();
        mid2.x = mid2x;
        mid2.y = mid2y;

        Line l1 = new_line_points(x1[0], x1[1]);
        Line l2 = new_line_points(x1[0], x1[2]);

        Line h1 = new_line(-(l1.y), l1.x, l1.y*mid1.x-l1.x*mid1.y);
        Line h2 = new_line(-(l2.y), l2.x, l2.y*mid2.x-l2.x*mid2.y);

        Point ans = new_point_line(cross_product(h1, h2));
        ans = normalize(ans);

        sumx = sumx / 3.0;
        sumy = sumy / 3.0;

        cout<<"Case #"<<c<<":"<<endl;
        cout.precision(15);
        cout<<fixed<<sumx<<" "<<sumy<<endl;
        Point p1 = projection(new_line_points(x1[0], x1[1]), x1[2]);
        p1 = normalize(p1);

        Point p2 = projection(new_line_points(x1[1], x1[2]), x1[0]);
        p2 = normalize(p2);



        Line ll[4];
        ll[0] = new_line_point(x1[0]);
        ll[1] = new_line_point(x1[2]);
        ll[2] = new_line_point(p2);
        ll[3] = new_line_point(p1);

        Line lcur1 = cross_product(ll[0], ll[2]);
        Line lcur2 = cross_product(ll[1], ll[3]);

        Line newl = cross_product(lcur1, lcur2);
        Point cur = new_point_line(newl);
        cur = normalize(cur);
        cout.precision(15);
        cout<<fixed<<cur.x<<" "<<cur.y<<endl;
        cout.precision(15);
        cout<<fixed<<ans.x<<" "<<ans.y<<endl;
    }

    return 0;
}
