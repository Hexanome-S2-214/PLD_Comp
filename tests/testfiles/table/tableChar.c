int main(){
    char foo[3];
    foo[2] = 'a';
    foo[3] = foo[2] + 1;
    return foo[3];
}