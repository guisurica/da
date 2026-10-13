#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int *elements;
    size_t capacity;
    size_t count;
} Da;

int main(void) {
    Da da = {0};

    for(int i = 0; i < 10; ++i) {
        if (da.count >= da.capacity) {
            if (da.capacity == 0) da.capacity = 256;

            da.capacity *= 2;
            da.elements = realloc(da.elements, da.capacity*sizeof(*da.elements));
        }

        da.elements[da.count++] = i;
    }

    for(int x = 0; x < da.count; ++x) printf("%d\n", da.elements[x]);

    return 0;
}