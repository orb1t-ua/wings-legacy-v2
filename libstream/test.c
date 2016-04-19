/**
 * test program for working with streams
 * for clarification, this is meant to run under GNU/Linux, not WINGS
 */

#include <stdio.h>
#include "libstream.h"

ReactiveStream in, out;

void screenOut(void* node) {
    putchar( (char) node);
}

void lambda0(void* node) {
    pushStream(&out, (void*) (char) node + 1);
}

int main(int argc, char** argv) {
    // establish stdin
    out = makeStream();
    registerStream(&out, screenOut);
    in = makeStream();

    // some logic
    registerStream(&in, lambda0);

    // main loop
    while(char c = getchar()) {
        pushStream(&in, (void*) c);
    }
}
