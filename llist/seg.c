#include <stdio.h>
#include <stdlib.h>

struct Location {
    int x;
    int y;
};

struct SnakeSegment {
    struct Location loc;
    struct SnakeSegment* next;
};

typedef struct SnakeSegment* segment;
typedef struct Location* location;

segment createSegment(location loc) {
    segment seg;
    seg = (segment)malloc(sizeof(struct SnakeSegment));
    seg->loc.x = loc->x;
    seg->loc.y = loc->y;
    seg->next = NULL;
    return seg;
}

void addSegment(segment* head, location loc) {
    segment tmp;
    segment seg;

    tmp = createSegment(loc);

    if (*head == NULL) {
        *head = tmp;
        return;
    }

    seg = *head;
    while (seg->next) {
        seg = seg->next;
    }
    seg->next = tmp;
}

int main() {
    segment head = NULL;
    location loc = (location)malloc(sizeof(struct Location));
    loc->x = 0;
    loc->y = 0;

    for (int i = 2; i < 16; i += 2) {
        loc->x = i;
        loc->y = i;
        addSegment(&head, loc);
    }

    /* traverse the list */
    segment seg = head;
    while (seg->next != NULL) {
        printf("- %d;%d - ", seg->loc.x, seg->loc.y);
        seg = seg->next;
    }

    return 0;
}