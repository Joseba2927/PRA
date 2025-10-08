#ifndef BRAZOROBOTICO_H
#define BRAZOROBOTICO_H

#include <iostream>

class BrazoRobotico {
private:
    double x, y, z;        
    bool sujetando;        

public:
    // Constructor
    BrazoRobotico(double x = 0.0, double y = 0.0, double z = 0.0);

    // Métodos consultores
    double getX() const;
    double getY() const;
    double getZ() const;
    bool sujetando() const;
    // Métodos de acción
    void mover(double X_, double Y_, double Z_);
    void coger();
    void soltar();
};

#endif

