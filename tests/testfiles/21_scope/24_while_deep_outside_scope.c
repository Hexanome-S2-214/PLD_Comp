int main() {
    int a = 1;

    while (a < 3) {
        int b = 1;

        while (b < 3) {
            int c = 1;

            while (c < 3) {
                c = c + 1;
            }

            b = b + c;
        }

        a = a + b + c;
    }

    return a;
}