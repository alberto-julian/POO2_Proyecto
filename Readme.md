<img src="Image/Utec-logo.jpg" alt="alt text" width="100">

# POO2_Proyecto
## Simulador de Partículas
### Grupo 5

_Proyecto realizado por alumnos de la UTEC dedicado a generar una aplicación de la simulación de partículas. Está basado en un simulador de contagio de partículas de COVID-19 a través del lenguaje ```C++ 17``` y la libreria ```SFML```._

## Objetivos: 🚀

* Generar alto grado de autonomía.
* Lograr buen nivel de abstracción. 
* Aplicar algoritmos basados en contenedores y librerias estándares.
* Utilizar patrones de diseño y principios de abstracción.
* Generar la documentación del proyecto.

## Estructura 🔧

_Este proyecto está desarrollado en condiciones ideales como considerar choque elástico, masas similares en cada partícula, radio similar, sin existencia de rozamiento en todas las interacciones en su desplazamiento y probabilidad de contagio con la data actual del virus COVID-19_

Se hizo uso de la estructura enum para representar el estado de la partícula sana::celeste, infectado::amarillo, recuperado::morado y muerto::rojo. En donde, se considera que una partícula sana se infecta al contacto directo con una partícula infectada, una partícula recuperada ya no puede volverse a infectar y una partícula roja pierde todo el dinamismo en la animación

```C++
enum color {
    celeste,	// 0
    amarillo,	// 1
    morado,		// 2
    rojo      // 3
};
```

Se desarrollo la estructura clase ```Particula```

```C++
class Particula {
private:
    D posicionx{};
    D posiciony{};
    D radio{};
    D velocidad{};
    D angulo{};
    color estado{};

    T ticks{};
    T indice_recupe{};
    B cambio_recuperacion{};

    RenderWindow* window;
    CircleShape circulo;
public:
    Particula(RenderWindow*,D,D);

    friend D distancia(Particula,Particula);
    friend B en_contacto(Particula,Particula);
    void set_estado(color);
    color get_estado();
    void estado_choque_particula(Particula&);
    void set_angulo_particula(Particula&);
    void choque_particula(Particula&);
    void set_color_particula();
    void choque_pared();
    void movimiento();
    void sanar();
    void draw();

};
```

_Y repite_

```C++
class MyWindow : public RenderWindow {
private:
    vector<Particula> Particulas{};
public:
    MyWindow();

    void event_handler();
    void loop();
    void report();
};
```

_Se espera que esta estructura sea lo más entendible para que pueda ser visualizada su funcionamiento de forma abstracta y lo más sencillo posible_

## Prueba ⚙️

_Explica como ejecutar las pruebas automatizadas para este sistema_

### Reporte 🔩

_Explica que verifican estas pruebas y por qué_

```
Da un ejemplo
```

## Limitaciones 📋

_El proyecto al realizarse es condiciones ideales para su desarrollo y su aplicación cuenta con las siguientes limitaciones:_

```
> Limitación en cantidad de partículas en espacio, actua de forma óptima hasta las doscientas partículas.
```

## Construido con 🛠️

_Menciona las herramientas que utilizaste para crear tu proyecto_

* [Dropwizard](http://www.dropwizard.io/1.0.2/docs/) - El framework web usado
* [Maven](https://maven.apache.org/) - Manejador de dependencias
* [ROME](https://rometools.github.io/rome/) - Usado para generar RSS

## Versionado 📌

Usamos [SemVer](http://semver.org/) para el versionado. Para todas las versiones disponibles, mira los [tags en este repositorio](https://github.com/tu/proyecto/tags).

## Autores ✒️

_Menciona a todos aquellos que ayudaron a levantar el proyecto desde sus inicios_

* **Example 1** - *Trabajo Inicial* - [villanuevand](https://github.com/villanuevand)
* **Example 2** - *Documentación* - [fulanitodetal](#fulanito-de-tal)

También puedes mirar la lista de todos los [contribuyentes](https://github.com/your/project/contributors) quíenes han participado en este proyecto. 

## Bibliografía 🖇️

> [EVENT-DRIVEN-SIMULATION](https://algs4.cs.princeton.edu/61event/).

> [Why outbreaks like coronavirus spread exponentially, and how to “flatten the curve”](https://www.washingtonpost.com/graphics/2020/world/corona-simulator/)

