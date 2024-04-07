int main() {
    int a = 1;

    switch (a) {
        case 1: {
            int b = 1;
            a = a + b;
            break;
        }
        default:
            a = a + 2;
            break;
    }

    return a;
}