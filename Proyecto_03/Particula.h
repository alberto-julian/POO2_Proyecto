//
// Created by user on 12/11/2020.
//

#ifndef PROYECTO_02_PARTICULA_H
#define PROYECTO_02_PARTICULA_H

#include "Macro.h"

class Particula {
private:
    F posicionx{};
    F posiciony{};
    F radio{};
    F velocidad{};
    F angulo{};
    color estado{};

    T ticks{};
    T indice_recupe{};
    B cambio_recuperacion{};

    RenderWindow* window;
    CircleShape circulo;
public:
    Particula(RenderWindow*,F,F);

    friend F distancia(Particula,Particula);
    friend B en_contacto(Particula,Particula);
    void set_estado(color);
    color get_estado();
    void estado_choque_particula(Particula&);
    void choque_pared();
    void cambio_color_estado();
    void movimiento();
    void sanar();
    void draw();

};


#endif //PROYECTO_02_PARTICULA_H
