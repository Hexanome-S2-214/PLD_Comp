int main() {
    int a = 2;
    int b = 5;
    int res;

    switch ((a > b || a > 3) + 3)
    {
    case 3:
        res = 1;
        break;
    case 4:
        res = 2;
        break;
    }

    return res;
}