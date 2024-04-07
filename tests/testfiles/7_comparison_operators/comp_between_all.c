int main() {
    int x = 1;

    while (x < 10) {
        if (x >= 3 && x <= 6) {
            putchar('0' + x);
        }

        x = x + 1;
    }

    return 0;
}