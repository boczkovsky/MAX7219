// First approach

#define din 1
#define clk 13
#define cs 12
#define dig0 2
#define dig1 3
#define dig2 5
#define dig3 6
#define dig4 7
#define dig5 8
#define dig6 10
#define dig7 11

setPin(char pin)
{

}

clrPin(char pin)
{

}



shiftOutByte(char byt)
{


}

writeDisplay(address,dat){

    clrPin(cs)
    shiftOutByte(address)
    shiftOutByte(dat)
    setPin(cs)

}