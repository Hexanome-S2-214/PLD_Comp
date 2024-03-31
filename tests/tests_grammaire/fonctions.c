int facto(int n) {
    func();
    if (n <= 1) {
        return 1;
    } else {
        int x = facto(n-1);
        return n*x;
    }
}

void func(int a, int b, int c, int d) {
    return a - b - c - d;
}

int main() {
    int a = facto(6);
    int b = func(1, 2, 3, a);
    int c = func(a) = func(3) ;
    int d = c = func(a) = func(3) ; = func(4);
    return a;
}

void f(int a int b){
    func(a b);
}