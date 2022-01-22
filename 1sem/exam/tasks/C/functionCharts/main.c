#include <stdio.h>
#include <math.h>

// gnuplot is needed
int main(void)
{
    int x, y;
    FILE *file = NULL;
    FILE *gnupipe = NULL;
    char *GnuCommands [] = {"set title \"Demo\"", "plot 'data.tmp'"};

    file = fopen("data.tmp", "w");
    gnupipe = _popen("gnuplot -persitent", "w");

    for (int i = 0; i < 11; i++)
    {
        fprintf(file, "%d %d\n", x, y);
        x++;
        y++;
    }

    for (int i = 0; i < 2; i++)
    {
        fprintf(gnupipe, "%s\n", GnuCommands[i]);
    }

    return 0;
}