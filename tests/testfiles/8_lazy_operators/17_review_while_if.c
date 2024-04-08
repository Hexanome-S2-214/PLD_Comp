int main() {
    int a = 0; int b = 0;
    while ((a < 3 && b < 5) || (a>3 && b>5)){
        if (a == 2 || b == 3){
            if (a==2 && b == 2) {
                int c = 1;
                a = a+1;
                return c;
            } else {
                int c = 2;
                a = a+1;
                return c;
            }
        } else {
            if (a==1 && b == 2) {
                int c = 4;
                a = a+1;
                return c;
            } else {
                int c = 3;
                a = a+1;
                return c;
            }
        }
    a = a+1;
    }
}