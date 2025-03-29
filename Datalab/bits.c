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

int isAsciiDigit(int x){
 // required to compare input w/2 constraints
        // so how can we check >= or <= without explicitly using these operators?
        // maybe << will help, keep dropping bits and seeing if things are equal to 0 after dropping the minimum amount
        // then dropping past the limit and seeing if things are equal to 0
        // any 4 bits on the right is garbage for unsigned ints, what about signed ints?
        // because of this, I suggest doing an AND with the input and the lowbound
        // because we know if any of the two bits on the far left are 1, then it's invalid, so we AND with something which we know two left bits are off
        // however, with an input of -13: 1111 0011 this would give a passing case when it shouldn't


        // what about negating everything first?
        int lowBound = 0x30;
        int highBound = 0x39;
        int resLow = x + ~lowBound+1;

        int checkLow = !(resLow>>31);



        int resHigh = x + ~highBound+1;
        int checkHigh = (resHigh>>31) | !(resHigh);

        return ( (checkHigh) & checkLow ) ;

}
