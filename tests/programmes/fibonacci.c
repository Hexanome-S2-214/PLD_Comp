int main() {
    int n = 6;
    int result = 0;
    
    if (n < 2) {
        result = 1;
    } else {
        int tmp1 = 1;
        int tmp2 = 1;
        int i=2;

        while(i<=n) {
            result = tmp1 + tmp2;
            tmp1 = tmp2;
            tmp2 = result;
            i = i+1;
        }
    }

    return result;
}