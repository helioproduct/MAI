#include <stdio.h>
#include <stdlib.h>

// Кратко про структуры

typedef struct _point {
	int x;
	int y;
} point;

point make_point(int x, int y)
{
	point p;
	p.x = x;
	p.y = y;
	return p;
}

point *make_point2(int x, int y)
{
	point *p = (point*)malloc(sizeof(point));
	p->x=x;
	p->y=y; 
}

int main(void)
{
	// point p = make_point(3, 2);
	point *p = make_point2(0, 1);
	printf("x: %d, y: %d", p->x, p->y);
	return 0;	
}