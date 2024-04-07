int main() {
    int a = 0;
    int b;

    switch (a) {
    case 0:
    case 1:
    case 2:
        b = 2;
        break;
    case 3:
        b = 3;
        break;
    default:
        b = 4;
        break;
    }

    return b;
}