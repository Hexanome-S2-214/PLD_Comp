int main () {
    int a = 1;
    int b = ++--a--++;
    int c = ++(--a)--++;
    int d = ++(--a--++); 
    int e = ++(--a--)++;
    int f = (++(--a--))++;
    return a += --a *= (--a-- += ++a++) -= a++ += 3;
}