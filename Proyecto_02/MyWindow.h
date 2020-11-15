//
// Created by user on 12/11/2020.
//

#ifndef PROYECTO_02_MYWINDOW_H
#define PROYECTO_02_MYWINDOW_H

#include "Macro.h"
#include "Particula.h"

class MyWindow : public RenderWindow {
private:
    vector<Particula> Particulas{};
public:
    MyWindow();

    void event_handler();
    void loop();
    void report();
};


#endif //PROYECTO_02_MYWINDOW_H
