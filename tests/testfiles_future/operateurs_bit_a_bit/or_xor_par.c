int main() {
    int a = 0x0000F0F0;
    int b = 0x0000FF00;
    int c = 0x0F0F0F0F;
    return a | (b ^ c);
}
