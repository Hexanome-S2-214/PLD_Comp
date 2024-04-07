int main(){
    int foo[10];
    int a = 23;
    foo[5] = a;
    foo[4] = foo[5] + 1;
    int b = 0;
    b = a + foo[4];
    return b;
}