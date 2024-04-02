int main() {
    int a=1;
    int c;
    switch(a) {
        case 0:
        case 1:
            c=1;
        
        case 2:
            c=2;
            break;
        
        case 3:
            if (a == 2) {
                while (a > 10) { a = 2+4+5; }
            }
            break;

        default:
            c = 12;
            break;
    }

    return c;
}