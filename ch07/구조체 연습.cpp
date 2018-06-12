#include <stdio.h>

typedef struct {
    int x, y;
    float r;
}circle;

int main() {
    circle a, b, c, d;
    a.x = 3;
    a.y = 5;
    printf("%d %d\n", a.x, a.y);
    
    scanf("%d %d %f", &b.x, &b.y, &b.r);
    printf("%d %d %f", b.x, b.y, b.r);
    c = b;
    printf("%d %d %f", b.x, b.y, b.r);
    
    d = {1, 2, 3.0};
    printf("%d %d %f\n", d.x, d.y, d.r);
}
