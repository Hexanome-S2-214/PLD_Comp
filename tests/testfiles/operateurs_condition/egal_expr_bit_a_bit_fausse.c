int main() {
    int a; int b;
    a = 0x0F0F0F0F;
    b = 0x0F0F0F0F;
    return a | b == b & a;
}
