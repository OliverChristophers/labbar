#include <stdio.h>
#include <stdbool.h>


struct point
{
  int x;
  int y;
};

typedef struct point point_t;

struct rectangle
{
    point_t tl;
    point_t br;
};

typedef struct rectangle rectangle_t; 

void translate(point_t *p1, point_t *p2)
{
  p1->x += p2->x;
  p1->y += p2->y;
}


void print_point(point_t *p) {
    printf("(%d, %d)", p->x, p->y);
}

point_t make_point(int X, int Y) {
    point_t p = {.x = X, .y = Y};
    return p;
}

void print_rect(rectangle_t *r) {
    printf("rectangle(upper_left=");
    print_point(&(r->tl));
    printf(", lower_right=");
    print_point(&(r->br));
    printf("))\n");
}

rectangle_t make_rect(int a, int b, int c, int d) {
    rectangle_t r = {.tl = make_point(a, b), .br = make_point(c, d)};
    return r;
}

int area_rect(rectangle_t *r) {
    return (r->tl.y - r->br.y) * (r->br.x - r->tl.x); 
}

bool intersects_rect(rectangle_t *a, rectangle_t *b){   
    return (a->tl.x < b->br.x) && 
           (a->br.x > b->tl.x) &&
           (a->tl.y > b->br.y) &&
           (a->br.y < b->tl.y);
}


rectangle_t intersection_rect(rectangle_t *a, rectangle_t *b){


} 

int main() {
    rectangle_t p = make_rect(0, 4, 4, 2);
    rectangle_t a = make_rect(-1, 1, 1, -1);

    printf("%d\n", intersects_rect(&p, &a));
    return 1;
}