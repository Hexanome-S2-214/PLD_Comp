#include <stdio.h>

int fonction_pour_montrer_le_reste() {
    int result = 0;
    char c = 'a';
    switch(c) {
        case 'b':
        case 'a':
            result += 3;
            break;
        case 'c':
            result -= 1;
            break;
    }
    return result += result /= result -= result *= 2;
}

int facto(int n) {
    if (n < 1) {
        return 1;
    } else {
        return n*facto((n-1));
    }
}

int func(int a, int b) {
    const int expr = !(3 - 4 + 5) + 2 / -3 % 3 * (3 <= 3 >= 3 + !3 + 3 - -3 < 3) < 3 + 3 > 3 & 3 <= 3 % 3 | 3 + 3 && 3 != 3 || 3 == 3 * 3 ^ -3 | 3 ^ !(3 != 3);
    putchar('a');
    return a * facto(expr) + b;
}

int main() {
    int a = 0; int b = 2; int c = 0;
    while ((a < 4 && b < 5) || (a>3 && b>5)){
        if (a == 2 || b == 3){
            if (a==2 && b == 2) {
                c = c+1;
                switch(a) {
                    case 2: {
                        int a = 1; int b = 2;
                        int d = func(a, b);
                        c = c+d;
                        int e = fonction_pour_montrer_le_reste();
                        c += e;
                    }
                }
                return c;
            } else {
                c = c+1;
            }
        } else {
            if (a==1 && b == 2) {
                c = c+1;
                switch(a) {
                    case 1: {
                        int a = 1; int b = 2;
                        while(a<2) {
                            if (a == 2 || b == 3){
                                if (a==2 && b == 2) {
                                    c = c+1;
                                } else {
                                    c = c+1;
                                }
                            } else {
                                if (a==1 && b == 2) {
                                    c = c+1;
                                } else {
                                    c = c+1;
                                }
                            }
                            a= a+1;
                        }
                    }
                }
            } else {
                a = a+1;
                continue;
                c = c+1;
            }
        }
        a = a+1;
    }
    return c;
}