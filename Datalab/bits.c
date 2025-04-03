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
        // if we negate our X and add it to Y, the result should be positive or 0
        // if 0, the leading bit will be 0 and if it's a nonzero positive int, the leading bit will be 0                                                        // so extract this leading bit and return !(leadingBit)
                                                                            

        // so if -x + 1+y is positive, then y >= x, and return 1
        int resHigh = ~x+1 +y;

        // if 0 --> leading bit is 0, so result is positive
        int checkHigh = (resHigh>>31);

        // !(positive result) returns 1
        return !checkHigh;
}

//4
/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int logicalNeg(int x) {
        // the ! operator sets any number NOT 0 to 1, and if given 0 outputs a 1
        // this sounds like a conditional that we mentioned earlier
        // the issue is that in our conditional, we used the ! operator...
        // notice that if we invert all bits and add 1, if the number is 0, it stays zero, otherwise, we get the negative of that number
        // the leading bit will also be set if we XOR the input with the inverse
        // but this will not work for the most negative number since inverting the most negative number gets the same number (due to addition overflow)

        int minusX = ~x + 1; // invert all bits, if we invert 0 it stays 0  
                                                                                    int allBits  = (x ^ minusX); // leading bit is 1 for non negative numbers except for max negative                                               
        int checkNegX = x >> 31; // 1 if number is negative

        // check below!!! Doesnt Work!! Must extract stuff!!!
        int checkNonZero =  (allBits>>31|checkNegX) + 1 & 1; // 1 if number is zero, 0 otherwise


        return checkNonZero;



}

int howManyBits(int x) {

        // example: 00...1100
        // count number of significant bits
        // trailing zeroes matter, leading zeroes don't EXCEPT for sign bit
        // the 1100 needs to stay
        // so we need 4 bits + 1 bit (sign bit) = 5 bits to rep 1100 in twos comp
        // if we have a negative number, and have to flip everything and add 1, we look for the zeroes
        // so for a large neg number, 111.....1011, we care about 011
        // this is 3 bits, accounting for sign bits means we only need 4 bits

        // for pos numbers, check left half and see if there's 1's
        // toss out bits on the right if found
        // toss out left half if not found
        // keep track of how many bits we toss out, add the sign bit to the total at the end


        // because we need to split in half, we shift by <<2
        // repeat for all other denominations


        int b16, b8, b4, b2, b1, sign;
        int b16, b8, b4, b2, b1, sign;
        // step 1: convert possibly negative number to an equivalent positive
        sign  = x>>31;
        x = (sign & ~x) | (~sign & x);

        // process 16 bit halves case, mult by 2^4, means we need 16 bits, otherwise the number is 0 and we ad 0 bits
         b16 = !!(x>>16) <<4;
        x = x>>b16;

         b8  = !!(x>>8)<<3;
        x>>=b8;


         b4 = !!(x>>4)<<2;
        x>>= b4;


         b2 = !!(x>>2)<<1;
        x >>=b2;

         b1 = !!(x>>1);
        x >>= b1;


        return b16 + b8 + b4 + b2 + b1 + x + 1;

}


unsigned floatNegate(unsigned uf) {

// separate out exponent
// exponent is 8 bits of the float
// get rid of the 23 bit mantissa

int exp = (uf>>23) & 0xFF; // allows us to keep first 8 bits

// if number is nan

// 8 bits of 1's and mantissa is nonzero
if(exp == 0xFF && (uf << 9) != 0 ){

// changes sign bit and negates the rest
return uf;
}

// number is not nan, negate float
// if sign bit is active is 0, turn it to 1, and likewise for active 1
return uf ^ (1<<31);

}
