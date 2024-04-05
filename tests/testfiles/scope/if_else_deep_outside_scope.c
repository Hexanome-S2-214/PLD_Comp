int main() {
    int a = 0;

    if (1) {
        if (0) {}
        else {
            int b = a;
        }

        if (1) {
            if (1) {
                if (0) {}
                else {
                    int c = b;
                }
            }
        }
    }

    return c;
}