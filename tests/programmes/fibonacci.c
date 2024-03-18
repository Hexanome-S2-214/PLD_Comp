int main() {
    int n = 6;
    int result = 0;
    
    if (n < 2) {
        result = n;
    } else {
        int tmp1 = 0;
        int tmp2 = 1;
        int i=2;

        while(i<=n) {
            result = result + tmp1 + tmp2;
            tmp2 = tmp2 + tmp1;
            tmp1 = tmp2;
            i = i+1;
        }
    }

    return result;
}