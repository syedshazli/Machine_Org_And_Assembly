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


/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {

        // think of this as the upper bound problem back in isASCII
        // we have our upper bound y, and input x

        // so if -y + 1+x is negative or 0, then y >= x, and return 1
        int resHigh = ~x+1 +y;

         int checkHigh = (resHigh>>31);

        //int compare = 1;
        return !checkHigh;
}

int conditional(int x, int y, int z) {

        // for the conditional, it goes as follows
        // x ? y: z
        // if x is true, return y, else return z
        // for x: input of 0 should return 0 and if nonzero should return 1

        // can XOR x with 0, output should be 1 if x is true
        // but then how can we determine to choose y based on this without using IF?
        // since we cannot have control flow in this, we might have to encode the result
        // the control flow can be used with an OR

        // notice how doing a ! makes something either a 0 or 1
        // so we can not our condition X, 0 means it's true, 1 means it's false
        // can choose to not this again to make things more intuitive, with 1 meaning true and 0 meaning false


        // (x & y ) | SOMETHING
        // return x & y because if x is 0 then the output of x & y is 0.





        x = !x; // x becomes either 0 or 1, 0 if true and 1 if false
        x = !x; // flip the value again so 1 is true and 0 is false

        // negate the result as seen before by doing the following
        x = ~x+1;

        // this now leaves us with all 1's or all 0's
        // which then allows us to bitwise AND properly, instead of 000000...1 which would ruin our operations when ANDING
//      printf("X IS %d", x);

        // if x is true, it returns all 1's and with y
        // ANDING something with all 1's gives the original number

        // must be ~x, because if x was all 0's then ANDING with x would make our resulting z a 0
        return ( x &y) | (~x & z);
}
