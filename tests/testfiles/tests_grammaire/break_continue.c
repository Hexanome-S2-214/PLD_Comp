int main() {
    int a=0;
    
    while (a<10) {
        if (a%2 == 0) {
            a = 15;
            break;
        } else {
            continue;
        }
    }

    if (a<1) { break;} else { continue;}


    return 0;
}