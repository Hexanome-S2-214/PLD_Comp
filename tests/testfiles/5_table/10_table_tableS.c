int main() {
  int toto[5];
  int foo[4];

  toto[0]=0;
  toto[1]=1;
  toto[2] = 1;
  
  foo[0] = 1;
  foo[1] = toto[2] + 1;
  foo[2] = toto[2] + toto[1];
  foo[3] = toto[2] + foo[1];

  return 0;
}
