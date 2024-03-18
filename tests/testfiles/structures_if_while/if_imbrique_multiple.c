int main() {
    int a=0; int b=0;
    int c = 0;
    if (a==0) {
        if (b==1) {
            c = c + 1;
            if (a==0) {
                if (b==1) {
                    c = c + 2;
                } else {
                    c = c + 3;
                }
            } else {
                c = c + 5;
                if (a==0) {
                    if (b==1) {
                        c = c + 7;
                    } else {
                        c = c + 11;
                    }
                } else {
                    c = c + 13;
                }
            }
        } else {
            c = c + 17;
            if (a==0) {
                if (b==1) {
                    c = c + 19;
                } else {
                    c = c + 23;
                    if (a==0) {
                        if (b==1) {
                            c = c + 29;
                        } else {
                            c = c + 31;
                        }
                    } else {
                        c = c + 37;
                    }
                }
            } else {
                c = c + 41;
            }
        }
    } else {
        c = c + 43;
        if (a==0) {
            if (b==1) {
                c = c + 47;
            } else {
                c = c + 53;
            }

            c = c + 59;
        } else {
            c = c + 61;
        }
    }

    if (a==0) {
        if (b==1) {
            c = c + 67;
        } else {
            c = c + 71;
        }
    } else {
        c = c + 73;
    }

    return c;
}