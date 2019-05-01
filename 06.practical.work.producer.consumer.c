#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 10

typedef struct {
    char type; // 0=fried chicken, 1=French fries
    int amount; // pieces or weight
    char unit; // 0=piece, 1=gram
} item;

item buffer[BUFFER_SIZE];
int first = 0;
int last = 0 ;

void produce(item *i) {
    while ((first + 1) % BUFFER_SIZE == last) {
        // do nothing -- no free buffer item
    }
    memcpy(&buffer[first], i, sizeof(item));
    first = (first + 1) % BUFFER_SIZE;
}

item *consume() {
    item *i = malloc(sizeof(item));
    while (first == last) {
        // do nothing -- nothing to consume
    }
    memcpy(i, &buffer[last], sizeof(item));
    last = (last + 1) % BUFFER_SIZE;
    return i;
}

int main() {
    // Item declaration
    item i1, i2;
    i1.type = '1';
    i1.amount = 4;
    i1.unit = '1';
    i2.type = '0';
    i2.amount = 5;
    i2.unit = '1';

    // print item list 
    printf("Item no.\tType\tAmount\tUnit\n");
    printf("Item 1\t\t%c\t%d\t%c\n", i1.type, i1.amount, i1.unit);
    printf("Item 2\t\t%c\t%d\t%c\n", i2.type, i2.amount, i2.unit);

    printf("\nInitial value:\nfirst = %d\tlast = %d\n", first, last);

    produce(&i1); // produce item 1
    printf("\nAfter producing item 1:\nfirst = %d\tlast = %d\n", first, last);

    produce(&i2); // produce item 2
    printf("\nAfter producing item 2:\nfirst = %d\tlast = %d\n", first, last);

    item *i3 = consume(); // consume an item
    printf("\nAfter consuming an item:\nfirst = %d\tlast = %d\n", first, last);
}