int main() {
    int a = 0;
    if(a < 10)
    {
        while (a<10)
        {
            if(a%2 == 0) { a = a+1; }
            else {a = a+2; }
        }
    }

    return 0;
}