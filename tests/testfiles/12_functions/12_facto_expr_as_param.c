int facto(int n) {
    if (n < 1) {
        return 1;
    } else {
        return n*facto((n-1));
    }
}

int main() {
    int a = 1;
    return facto((5*2)+a);
}