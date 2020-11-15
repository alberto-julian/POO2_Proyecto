//
// Created by user on 12/11/2020.
//

#include "Particula.h"

Particula::Particula(RenderWindow* window_, F posicionx_, F posiciony_):window(window_),circulo(RADIO),
posicionx(posicionx_),posiciony(posiciony_),estado(color::celeste),velocidad(VELOCIDAD), radio(RADIO),
angulo(rand()%360),ticks(0),indice_recupe(rand()%500),cambio_recuperacion(true){
    circulo.setPosition(posicionx_,posiciony_);
    circulo.setOrigin(ORIGEN,ORIGEN);
}

F distancia(Particula a, Particula b) {
    return sqrt(pow(a.posiciony-b.posiciony,2)+pow(a.posicionx-b.posicionx,2));
}

B en_contacto(Particula a,Particula b) {
    if(distancia(a,b)<=(a.radio+b.radio))
        return true;
    else
        return false;
}

void Particula::set_estado(color A_Cambiar) {
    estado=A_Cambiar;
}

color Particula::get_estado() {
    return estado;
}

void Particula::choque() {
    if(posicionx+2*RADIO>=LADO)
        velocidad *= -1;
    else if(posiciony+2*RADIO>=LADO)
        velocidad *= -1;
    if(posicionx<=0)
        velocidad *= -1;
    else if(posiciony<=0)
        velocidad *= -1;
}

void Particula::movimiento() {
    if(estado!=color::rojo){
        F aumentox = velocidad*cos(angulo*PI/180);
        F aumentoy = velocidad*sin(angulo*PI/180);
        if(aumentoy<0.001 && aumentoy>-0.001) aumentoy=0;
        if(aumentox<0.001 && aumentox>-0.001) aumentox=0;
        posicionx+=aumentox;
        posiciony+=aumentoy;
        circulo.setPosition(posicionx,posiciony);
    }
}

void Particula::sanar() {
    if(estado==color::amarillo){
        if(ticks>=(LIMITE+indice_recupe) && cambio_recuperacion) {
            F PROB_EVALUAR=rand() % 100;
            if (PROB_EVALUAR <= PROB_RECUP)
                estado = color::morado;
            else
                estado = color::rojo;
            cambio_recuperacion = false;
        } else
            ticks++;
    }
}

void Particula::draw() {//Color RGB
    switch(estado) {
        case color::celeste:
            circulo.setFillColor(Color(52, 152, 219));
            break;
        case color::amarillo:
            circulo.setFillColor(Color(241, 196, 15));
            break;
        case color::morado:
            circulo.setFillColor(Color(155, 89, 182));
            break;
        case color::rojo:
            circulo.setFillColor(Color(231, 76, 60));
            break;
    }
    movimiento();
    sanar();
    choque();
    window->draw(circulo);
}



