#include <stdio.h>

const char *edinici[] = {[0]="zero", [1]="one", [2]="two", [3]="three", [4]="four", [5]="five", [6]="six", [7]="seven", [8]="eight", [9]="nine"};
const char *desyatki[] = {[0]="", [1]="ten", [2]="twenty", [3]="thirty", [4]="fourty", [5]="fifty", [6]="sixty", [7]="seventy", [8]="eighty", [9]="ninety"};
const char *words[] = {[0]="ten", [1]="eleven", [2]="twelve", [3]="thirteen", [4]="fourteen", [5]="fifteen", [6]="sixteen", [7]="seventeen", [8]="eighteen", [9]="nineteen"};

int main() {
int in, a, b, c;
scanf("%d", &in);
a = in % 10;
b = (in / 10) % 10;
c = in/100;
if (c == 0) {
if (b == 0) printf("%s\n", edinici[a]);
else if (b == 1) printf("%s\n", words[a]);
else if (b > 1) printf("%s %s\n", desyatki[b], a != 0 ? edinici[a] : "");
} else if (c >= 1) {
if (b == 0) printf("%s hundred %s\n", edinici[c], edinici[a]);
else if (b == 1) printf("%s hundred %s\n", edinici[c], words[a]);
else if (b > 1) printf("%s hundred %s %s\n", edinici[c], desyatki[b], a != 0 ? edinici[a] : "");
}
}

#include <stdio.h>
void spell(long long k, int i) {
    if (k == 1 && i == 2) {
        printf("одна");
    } else if (k == 1) {
        printf("один");
    } else if (k == 2) {
        printf("два");
    }
    else if (k == 3) {
        printf("три");
    }
    else if (k == 4) {
        printf("четыре");
    }
    else if (k == 5) {
        printf("пять");
    }
    else if (k == 6) {
        printf("шесть");
    }
    else if (k == 7) {
        printf("семь");
    }
    else if (k == 8) {
        printf("восемь");
    }
    else if (k == 9) {
        printf("девять");
    }
}

int main()
{
    long long n, n1;
    scanf("%lld", &n);
    int i = 0;
    n1 = n;
    while (n1 > 0) {
        i += 1;
        n1 /= 1000;
    }
    if (i == 0) {
        printf("ноль");
    }
    else if (i <= 4) {
        while (n > 0) {
            long long k = n;
            long long p = 1;
            while (k >= 1000) {
                k /= 1000;
                p *= 1000;
            }
            n %= p;
            
            if (k / 100 > 0) {
                if(k / 100 == 1) {
                    printf("сто ");
                } else if (k / 100 == 2) {
                    printf("двести ");
                } else if (k / 100 < 5) {
                    spell(k / 100, i);
                    printf("ста ");
                } else if (k / 100 < 10) {
                    spell(k / 100, i);
                    printf("сот ");
                }
            }
            
            if(k % 100 == 11) {
                printf("одиннадцать");
            } else if (k % 100 == 12) {
                printf("двенадцать");
            } else if (k % 100 == 10) {
                printf("десять");
            } else if (k % 100 < 10 && k % 100 > 0) {
                spell(k % 100, i);
            } else if (k % 100 < 20) {
                spell(k % 10, i);
                printf("надцать ");
            } else if (k % 100 < 90) {
                spell(k % 100 / 10, i);
                printf("десят ");
                spell(k % 10, i);
            } else {
                printf("девяносто ");
                spell(k % 10, i);
            }
            
            if (i == 4 && k % 10 == 1 && k % 100 != 11) {
                printf(" миллиард ");
            } else if (i == 4 && k % 10 < 5 && k % 10 != 0 && (k % 100 < 10 || k % 100 > 19)) {
                printf(" миллиарда ");
            } else if (i == 4) {
                printf(" миллиардов ");
            } if (i == 3 && k % 10 == 1 && k % 100 != 11) {
                printf(" миллион ");
            } else if (i == 3 && k % 10 < 5 && k % 10 != 0 && (k % 100 < 10 || k % 100 > 19)) {
                printf(" миллиона ");
            } else if (i == 3) {
                printf(" миллионов ");
            } else if (i == 2 && k % 10 == 1 && k % 100 != 11) {
                printf(" тысяча ");
            } else if (i == 2) {
                printf(" тысяч ");
            }
            
            i -= 1;
        }
    } else {
        printf("Дохуялиард");
    }
    return 0;
}