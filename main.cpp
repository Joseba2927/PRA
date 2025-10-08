#include "BrazoRobotico.h"

int main() {
    BrazoRobotico brazo(0, 0, 0);
    brazo.mover(10, 5, 2);
    brazo.coger();
    brazo.mover(15, 8, 3);
    brazo.soltar();
    return 0;
}

