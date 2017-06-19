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
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for(int c = 1; c <= t; ++c)
    {
        for(int i = 0; i <= 2; ++i)
        {
            x1[i] = Point();
            cin >> x1[i].x >> x1[i].y;
        }
        for(int i = 0; i <= 2; ++i)
        {
            x2[i] = Point();
            cin >> x2[i].x >> x2[i].y;
        }

        Point p1 = projection(new_line_points(x1[0], x1[1]), x1[2]);
        p1 = normalize(p1);

        Point p2 = projection(new_line_points(x2[0], x2[1]), x2[2]);
        p2 = normalize(p2);

        Point x = new_point_line(cross_product(new_line_points(x1[2], p1), new_line_points(x2[2], p2)));
        x = normalize(x);

        cout<<"Case #"<<c<<": ";
        if(infinite(x))
        {
            cout << "strange"<<endl;
        }
        else
        {
            if(!valid(x1[2], x, p1) || !valid(x2[2], x, p2))
            {
                cout << "strange"<<endl;
            }
            else
            {
                cout.precision(7);
                cout<<fixed<<x.x<<" "<<x.y<<endl;
            }
        }
    }

    return 0;
}
