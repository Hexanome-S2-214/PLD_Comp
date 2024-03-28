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
    return add(sub(mult(a, b), add(a, b)), div(add(a, b), mult(a, b)));
}