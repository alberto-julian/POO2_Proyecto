//
// Created by user on 12/11/2020.
//

#include "MyWindow.h"

MyWindow::MyWindow():RenderWindow(VideoMode(LADO+300,LADO+300),"Simulador de Particulas") {
    T CUADRE= LADO-2*RADIO;
    for(int i = 0; i < POBLACION; i++) {
        F PROB_EVALUAR2=rand()%100;
        if(PROB_EVALUAR2<=(100-PROB_INFECT))
            Particulas.push_back(Particula(this, rand() % CUADRE,rand() % CUADRE));
        else{
            Particula infectado(this,rand() % CUADRE,rand() % CUADRE);
            infectado.set_estado(color::amarillo);
            Particulas.push_back(infectado);
        }
    }
}

void MyWindow::event_handler() {
    Event evento;
    while(pollEvent(evento)) {
        if(evento.type == Event::Closed) {
            close();
        }
    }
}

void MyWindow::loop() {
    while(isOpen()) {
        event_handler();
        clear(Color(236, 240, 241));//COLOR RGB
        for(int i = 0; i < Particulas.size(); i++) {
            Particulas[i].draw();
            for(int j = i+1; j < Particulas.size(); j++) {
                Particulas[i].choque_particula(Particulas[j]);
            }
        }
        display();
    }
}


void MyWindow::report() {
    srand(time(0));
    loop();
    B Infectado=true;
    while(Infectado){
        T contador=0;
        for(auto & Particula : Particulas) {
            if(Particula.get_estado()==color::amarillo)
                contador++;
        }
        if(contador==0)
            Infectado=false;
    }
    T contadorsano=0,contadorinfectado=0,contadorecuperado=0,contadormuerto=0;
    for(auto & Particula : Particulas) {
        if(Particula.get_estado()==color::celeste)
            contadorsano++;
        else if(Particula.get_estado()==color::amarillo)
            contadorinfectado++;
        else if(Particula.get_estado()==color::morado)
            contadorecuperado++;
        else
            contadormuerto++;
    }
    cout<<"Cantidad de sanos: "<<contadorsano<<endl<<"Cantidad de infectados: "<<contadorinfectado<<endl<<
    "Cantidad de recuperados: "<<contadorecuperado<<endl<<"Cantidad de muertos: "<<contadormuerto<<endl;
}
