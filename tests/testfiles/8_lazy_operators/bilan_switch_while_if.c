int main() {
    int a = 0; int b = 2; int c = 0;
    while ((a < 3 && b < 5) || (a>3 && b>5)){
        if (a == 2 || b == 3){
            if (a==2 && b == 2) {
                c = c+1;
                switch(a) {
                    case 2: {
                        int a = 1; int b = 2;
                        if (a == 2 || b == 3){
                            if (a==2 && b == 2) {
                                int a = 3;
                                while (a<2 && a < 3) {
                                    a = a+1;
                                }
                                c = c+1;
                            } else {
                                c = c+1;
                            }
                        } else {
                            if (a==1 && b == 2) {
                                c = c+1;
                            } else {
                                c = c+1;
                            }
                        }
                    }
                }
                return c;
            } else {
                c = c+1;
            }
        } else {
            if (a==1 && b == 2) {
                c = c+1;
                switch(a) {
                    case 2: {
                        int a = 1; int b = 2;
                        if (a == 2 || b == 3){
                            if (a==2 && b == 2) {
                                c = c+1;
                            } else {
                                c = c+1;
                            }
                        } else {
                            if (a==1 && b == 2) {
                                c = c+1;
                            } else {
                                c = c+1;
                            }
                        }
                    }
                }
            } else {
                c = c+1;
            }
        }
        a = a+1;
    }
    return c;
}