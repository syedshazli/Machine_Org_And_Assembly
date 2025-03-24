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

int allOddBits(int x){
   int oddWord = 0x55555555; // all negative odds
        int res = (~oddWord & x); // get the oddWord AND with X to then see if it's equal
//      printf("my number is 0x%08X\n",x);
        return !(res^ ~oddWord); // NOT to see if the odd word
}

int negate(int x){
  return ~x+1;
}
