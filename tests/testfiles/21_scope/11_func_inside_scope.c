int foo() {
    int a = 12;

    return a;
}

int bar() {
    int a = 24;

    return a;
}

int main() {
    int a = 1;
    bar();

    return a + foo();
}