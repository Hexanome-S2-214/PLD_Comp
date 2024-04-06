int add(int a, int b) {
    return a+b;
}

int sub(int a, int b) {
    return a-b;
}

int div(int a, int b) {
    return a/b;
}

int mult(int a, int b) {
    return a*b;
}

int main() {
    int a = 2; int b = 6;
    int c = add(a, b);
    int d = sub(c+a, a);
    int e = mult(d, c+d);
    int f = div(e, b);
    return f;
}