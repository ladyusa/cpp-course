#include <stdio.h>


typedef struct {
	int width;
	int length;
} Rectangle;  // user-defined type

int area(Rectangle r) {
	return r.width * r.length;
}

int perimeter(Rectangle r) {
	return 2 * (r.width + r.length);
}

void change_size(Rectangle *r, int d) {
	r->width += d;
	r->length += d;
}


int main() {
	
	Rectangle r;
	printf("Enter width: ");
	scanf("%d", &r.width);

	printf("Enter length: ");
	scanf("%d", &r.length);

	printf("Area: %d\n", area(r));
	printf("Perimeter: %d\n", perimeter(r));

	change_size(&r, 1);
	printf("%d, %d\n", r.width, r.length);
}


