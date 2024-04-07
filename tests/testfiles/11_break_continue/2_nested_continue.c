int main() {
    int a=0; int b=0;
    int c = 0;
    
    while (a<10) {
        while (b < 5) {
            b = b+1;
            if (b == 2) {
                continue;
            }
            c = c+1;
        }
        a = a+1;

        if (a == 3) {
            continue;
        }
        c = c+1;
    }

    return b;
}