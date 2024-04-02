int main() {
    int a=1;
    int c;
    switch(a) {
        case 1:
            c=1;
        
        case 2:
            int b=0;
            while (a < 5) {
                if (a == 3) {
                    break;
                }
                a = a+1;
                c = c+1;
            }
            break;
        
        case 3:
            c=3;
            break;
    }

    return c;
}