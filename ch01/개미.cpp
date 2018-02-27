#include <stdio.h>

int main()
{
    int w,h,x,y,t,p,q;
    scanf("%d %d %d %d %d",&w, &h, &x, &y, &t);
    x += t; y += t;
    p = x % w; q = y % h;
    if((x/w)&1) p = w - p;
    if((y/h)&1) q = h - q;
    printf("%d %d\n", p, q);
}
// 개미

