#include<stdio.h>

typedef int Strength;
typedef int Obedience;

#define INIT_STRENGTH 50
#define INIT_OBEDIENCE 20

#define STRENGTH_EAT 5
#define OBEDIENCE_EAT 2

#define STRENGTH_TRAIN 4
#define OBEDIENCE_TRAIN 5

#define LEARN_STRENGTH 55
#define LEARN_OBEDIENCE 28

int main () {
    int count = 0;
    int s = INIT_STRENGTH, o = INIT_OBEDIENCE;
    while (1) {
        char c = getchar();
        if (c == '\n') break;
        else if (c == 'e') {
            s += STRENGTH_EAT, o -= OBEDIENCE_EAT;
        }
        else if (c == 't') {
            o += OBEDIENCE_TRAIN, s -= STRENGTH_TRAIN;
        }
        if (o >= LEARN_OBEDIENCE && s <= LEARN_STRENGTH) count++, o = INIT_OBEDIENCE;
    }
    if (count >= 5) printf("Yes\n");
    else printf("No\n");
    return 0;
}
