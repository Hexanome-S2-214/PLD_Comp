int foo(int a) {
    a = a + 10;
    return a;
}

int main() {
    int a = 1;
    return a + foo(a);
}