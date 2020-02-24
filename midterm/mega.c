unsigned int combine(unsigned int x, unsigned int y){
     x = (x & 0xFF000000);
     y = (y & 0x00FFFFFF);
     return (x | y);
}
unsigned int replace(unsigned int x, int i, unsigned char b){
    i = (i << 3);
    unsigned int ffMask = (0xFF << i);
    unsigned int newVal = (b << i);
    return (x & ~ffMask) | newVal;
}
int evenBit(unsigned int n){
    return !!(n & 0x55555555);
}
int mask(int x){
    return (1 << x) - 1;
}
unsigned int extract(unsigned int x, int i){
    unsigned int leftOffset =  24 - (i << 3);
    int newWord = x << leftOffset;
    return (unsigned int) (newWord >> 24);
}