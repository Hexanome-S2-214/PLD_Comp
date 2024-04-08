int foo(int a) {
    if (1) {
        int a = 3;
    }
    return a;
}

int main() {
    return foo(1);
}