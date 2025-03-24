int bitXOR(int x, int y){

  return (~ (~(x&~y) & ~(~x & y )));
}

int tmin(void){
  int x = 1;
  return x <<31;
}

int isTmax(int x){
  int compare = 1;
  compare = compare << 31;
  compare = ~compare;

  int xor = compare ^ x;
  return !(xor);
}

int allOddBits(int x){}

int negate(int x){
  return ~x+1;
}
