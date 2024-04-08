int foo() {
    int b = 2;

    return b;
}

int main() {
    int a = 1;
    return a + foo() + b;
}