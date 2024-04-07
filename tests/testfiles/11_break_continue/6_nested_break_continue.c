int main() {
    int a=0; int b=0; int c=0;
    
    while (a<10) {
        while (b < 5) {
            if (b == 2) {
                break;
            } else {
                c=c+2;
                b = b+1;
                continue;
            }
        }
        a = a+1;
    }
    return b;
}