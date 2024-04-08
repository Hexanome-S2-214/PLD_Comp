int main() {
  int foo[5];
  int idx = 3;
  foo[idx] = 10;
  foo[2] = foo[idx];
  return foo[idx];
}
