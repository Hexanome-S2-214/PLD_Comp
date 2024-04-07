int main() {
    int a = 1;
    int b = 2;
    int c = 4;

    if (1) {
        int a = 10;
        b = b + a;

        if (1) {
            int b = 20;
            c = c + b;
        }
    }

    return a + b + c;
}