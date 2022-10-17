#include <stdio.h>
#include <math.h>

struct point
{
	double x, y;
};
typedef struct point Point;

struct triangle
{
	Point a,b,c;
};
typedef struct triangle Triangle;

void print_point(Point a) 
{
    printf("(%.2f, %.2f)", a.x, a.y);
}

void print_triangle(Triangle a)
{
	printf("{(%.2f, %.2f), (%.2f, %.2f), (%.2f, %.2f)}", a.a.x, a.a.y, a.b.x, a.b.y, a.c.x, a.c.y);
}

double distance(Point a, Point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

double get_triangle_perimeter(const Triangle g)
{
	return (distance(g.a, g.b) + distance(g.b, g.c) + distance(g.a, g.c));
}

double get_triangle_area(const Triangle g)
{
	return sqrt((get_triangle_perimeter(g) / 2) * ((get_triangle_perimeter(g) / 2) - distance(g.a, g.b))*((get_triangle_perimeter(g) / 2) - distance(g.b,g.c)) * ((get_triangle_perimeter(g) / 2) - distance(g.c,g.a)));
}

Triangle moved_triangle(const Triangle g, Point v)
{
	struct triangle k;
	k.a.x = g.a.x + v.x;
	k.a.y = g.a.y + v.y;
	k.b.x = g.b.x + v.x;
	k.b.y = g.b.y + v.y;
	k.c.x = g.c.x + v.x;
	k.c.y = g.c.y + v.y;

	return k;
}

Triangle move_triangle(struct triangle* p, Point v)
{
    (*p).a.x = (*p).a.x + v.x;
    (*p).a.y = (*p).a.y + v.y;
    (*p).b.x = (*p).b.x + v.x;
    (*p).b.y = (*p).b.y + v.y;
    (*p).c.x = (*p).c.x + v.x;
    (*p).c.y = (*p).c.y + v.y;
    return *p;
}

int main()
{
	typedef struct point Point;
	typedef struct triangle Triangle;
	struct point v = {3.47, 5.88};
	struct point a = {1.23, 4.56};
	struct point b = {7.89, 10.11};
	struct point c = {12.13, 14.15};
	struct triangle g = {a, b, c};
	struct triangle* p = &g;
	printf("(%.2f, %.2f)\n", a.x, a.y);
	printf("{(%.2f, %.2f), (%.2f, %.2f), (%.2f, %.2f)}\n", a.a.x, a.a.y, a.b.x, a.b.y, a.c.x, a.c.y);
	printf("%.2lf\n", get_triangle_perimeter(g));
	printf("%.2lf\n", get_triangle_area(g));
	print_triangle(moved_triangle(g, v));
	printf("\n");
	print_triangle(move_triangle(p, v));
	printf("\n");
}