int main() {
    int a = 0;

    if (1) {
        if (0) {}
        else {
            a = a + 1;
        }

        if (1) {
            if (1) {
                if (0)
                else {
                    a = a + 2;
                }
            }
        }
    }

    return a;
}