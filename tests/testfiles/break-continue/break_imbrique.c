int main() {
    int a=0; int b=0;
    
    while (a<10) {
        while (b < 5) {
            if (b == 2) {
                break;
            }
            b = b+1;
        }
        a = a+1;
    }

    return b;
}