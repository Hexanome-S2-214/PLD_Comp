int func() {
    int a=1; int b=2;
    return a+b;
}

int main() {
    int a=3; int b=2;
    int c = a+b;
    func();
    return c*a + b;
}