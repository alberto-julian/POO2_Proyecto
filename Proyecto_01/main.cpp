#include <iostream>
#include <cmath>
#include <vector>
#include <unistd.h>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

#define LIMITE 500
#define RADIO 1.0
#define PI 3.14159265
//#define VELOCIDAD 2

enum color{
    celeste,//0
    amarillo,//1
    morado//2
};

class Particula{
private:
    float posicionx{};
    float posiciony{};
    float radio{};
    float velocidad{};
    float angulo{};
    color estado{};
    int ticks;
public:
    Particula(float posicionx_,float posiciony_,float velocidad_,float angulo_,color estado_):posicionx(posicionx_),posiciony(posiciony_),radio(RADIO),velocidad(velocidad_),angulo(angulo_),estado(estado_),ticks(0){}

    friend float distancia(Particula a, Particula b){
        return sqrt(pow(a.posiciony-b.posiciony,2)+pow(a.posicionx-b.posicionx,2));
    }
    friend bool en_contacto(Particula a, Particula b){
        if(distancia(a,b)<=(a.radio+b.radio))
            return true;
        else
            return false;
    }
    void update(Particula &b){
        choque(b);
        movimiento();
        sanar();
    }
    void choque(Particula &b){
        if(en_contacto(*this,b)){
            if(estado==color::celeste && b.estado==color::amarillo)
                estado=color::amarillo;
        }
    }

    void movimiento(){
        float aumentox = velocidad*cos(angulo*PI/180);
        float aumentoy = velocidad*sin(angulo*PI/180);
        if(aumentoy<0.001 && aumentoy>-0.001) aumentoy=0;
        if(aumentox<0.001 && aumentox>-0.001) aumentox=0;
        posicionx+=aumentox;
        posiciony+=aumentoy;
    }

    void sanar(){
        if(estado==color::amarillo){
            if(ticks>=LIMITE)
                estado=color::morado;
            else
                ticks++;
        }
    }
};

class MyWindow{
    RenderWindow window;
public:
    MyWindow():window(VideoMode(800,800),"Hello World"){
    }

    void event_handler(){
        Event evento;
        while(window.pollEvent(evento)) {
            if (evento.type == Event::Closed)
                window.close();
            if (evento.type == Event::MouseButtonPressed)
                cout << "Hola " << endl;
        }
    }

    void loop(){
        CircleShape point(50);
        point.setFillColor(Color::White);
        point.setPosition(500,500);
        while(window.isOpen()){
            event_handler();
            window.clear(Color::Black);
            window.draw(point);
            window.display();
        }
    }
};

class MyWindow2:RenderWindow{
private:
public:
    MyWindow2():RenderWindow(VideoMode(800,800),"Mi proyecto"){};
    void event_handler(){
        Event evento;
        while(pollEvent(evento)){
            if(evento.type==Event::Closed)
                close();
        }
    }

    void loop(){
        while(isOpen()){
            event_handler();
            clear();
            display();
        }
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    cout << color::celeste << endl;
    vector<Particula> particulas{};
    particulas.push_back(Particula(0.0,0.0,2.0,0, color::celeste));
    particulas.push_back(Particula(1.0,1.0,1.5,0, color::amarillo));
    /*while(true){
        for(int i=0;i<particulas.size();i++){
            for(int j=0;j<particulas.size();j++){
                if(i!=j){
                    particulas[i].update(particulas[j]);
                }
            }
        }
        usleep(100);
    }*/

    //SFML
    MyWindow win;
    win.loop();
    //RenderWindow w(VideoMode(800,800),"Prueba");
    //MyWindow2 win2;
    return 0;
}
