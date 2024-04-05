int main() {
    int a = 1;

    while (a < 12) {
        int b = 1;

        while (b < 4) {
            b = b + a;
        }

        a = a + b;
    }

    return a;
}