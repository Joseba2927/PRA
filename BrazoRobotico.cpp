#include "BrazoRobotico.h"

BrazoRobotico::BrazoRobotico(double x, double y, double z){
    : x(x), y(y), z(z), sujetando(false)

double BrazoRobotico::getX() { 
	return x; 
}

double BrazoRobotico::getY() { 
	return y; 
}

double BrazoRobotico::getZ() { 
	return z; 
}

bool BrazoRobotico::Sujetando() { 
	return sujetando;
}

void BrazoRobotico::mover(double X_, double Y_, double Z_) {
    x = X_;
    y = Y_;
    z = Z_;
}

void BrazoRobotico::coger() {
    if (!sujetando) {
        sujetando = true;
    }
}

void BrazoRobotico::soltar() {
    if (sujetando) {
        sujetando = false;
    }
}
