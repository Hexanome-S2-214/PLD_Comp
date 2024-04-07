int main() {
    int a = b = 3;
    int a = b = c = 3;
    int a = b; = c;
    a = b = c;
    a = b; = c = d;
}