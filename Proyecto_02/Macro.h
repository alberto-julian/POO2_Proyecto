//
// Created by user on 12/11/2020.
//

#ifndef PROYECTO_02_MACRO_H
#define PROYECTO_02_MACRO_H

#include <iostream>
#include <cmath>
#include <vector>
#include <SFML/Graphics.hpp>
#include <random>

using namespace std;
using namespace sf;

typedef float F;
typedef int T;
typedef bool B;

#define LIMITE 200
#define RADIO 5.0
#define PI 3.14159265
#define VELOCIDAD 2
#define LADO 800
#define ORIGEN 0
#define PROB_RECUP (846215.0/922333.0)*100
#define PROB_MORIR (34879.0/922333.0)*100
#define PROB_INFECT (922333.0/4674263.0)*100
#define POBLACION 100

enum color {
    celeste,	// 0
    amarillo,	// 1
    morado,		// 2
    rojo        // 3
};

#endif //PROYECTO_02_MACRO_H
