int facto(int n) {
    if (n <= 1) {
        return 1;
    } else {
        int x = facto(n-1);
        return n*x;
    }
}

int func(int a, int b, int c, int d) {
    return a - b - c - d;
}


int main() {
    int a = facto(6);
    int b = func(1, 2, 3, a);
    return a;
}