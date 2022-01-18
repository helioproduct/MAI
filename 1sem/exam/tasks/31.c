#include <stdio.h>
#include <math.h>

double f(double x) {
	return sin(x);
}

int main() {
	double dx = 0.1, dy = 0.1, mx = -4, Mx = 4, my = -1, My = 1;
	char s = '#';

	double y = My;
	for (int i = 0; y >= my; i++, y = My - i*dy) {
		double x = mx;
		for (int j = 0; x <= Mx; j++, x = mx + j*dx) {
			if ((f(x) < y + dy/2) && (f(x) > y - dy/2)) printf("%c", s);
			else {
				if ((x > -dx/2) && (x < dx/2)) printf("|");
				else if ((y > -dy/2) && (y < dy/2)) printf("-");
				else printf(" ");
			} 
			// printf("(%.2f,%.2f) ", x, y);
		}
		printf("\n");
	}
}