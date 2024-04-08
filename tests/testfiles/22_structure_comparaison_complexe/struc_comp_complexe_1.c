int main() {
    int a = 3;
    int b = 5;

    if (a >= 2 && b <= 7) {
        a = a + 6;

        if (a == 9 || b == 7) {
            b = b + 3;
        } else {
            b = b + 2;
        }

        if (a == 0 || b == 8) {
            a = a + 40;
        } else { 
            a = a + 80;
        }
    }

    return a + b;
}