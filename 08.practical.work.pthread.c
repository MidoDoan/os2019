#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
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
    while ((first + 1) % BUFFER_SIZE == last)
    {
        // do nothing -- no free buffer item
    }
    memcpy(&buffer[first], i, sizeof(item));
    first = (first + 1) % BUFFER_SIZE;
}

void consume() {
    item *i = malloc(sizeof(item));
    while (first == last) {
        // do nothing -- nothing to consume
    }
    memcpy(i, &buffer[last], sizeof(item));
    last = (last + 1) % BUFFER_SIZE;
    //return i;
}

item *init(char type, int amount, char unit) {
    item *i = malloc(sizeof(item));
    i-> type = type;
    i-> amount = amount;
    i-> unit = unit;
    return i;
}

void printLog(){
    printf("\nfirst = %d\tlast = %d\n", first, last);
}
void *threadProduce(void *param)
{
    item *i1 = init('1', 4, '1');
    item *i2 = init('0', 5, '1');
    item *i3 = init('0', 6, '1');
    printf("\nBegin producing:\n");
    produce(i1);
    printLog();
    produce(i2);
    printLog();
    produce(i3);
    printLog();
}
void *threadConsume(void *param)
{
    printf("\nBegin consuming:\n");
    consume();
    printLog();
    consume();
    printLog();
}

int main() {
    printf("\nInitial value:\nfirst = %d\tlast = %d\n", first, last);
    pthread_t tid1;
    pthread_t tid2;
    pthread_create(&tid1, NULL, threadProduce, NULL);
    pthread_create(&tid2, NULL, threadConsume, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
}