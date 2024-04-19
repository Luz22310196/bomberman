#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <thread>
#include <iostream>
#include <string>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    int fotograma = 0;
    string reset;

    while (true)
    {
        fotograma++;
        Decorator cfondo = bgcolor(Color::GrayDark);
        Decorator ctexto = color(Color::White);
        

        Element personaje = spinner(21, fotograma);
        Element dibujo = border({

            hbox(personaje) | cfondo | ctexto

        });

        Dimensions Alto = Dimension::Fixed(10);
        Dimensions Ancho = Dimension::Full();

        Screen pantalla = Screen::Create(Ancho, Alto); // Create es un metodo estatico que tiene la clase Screen

        Render(pantalla, dibujo);

        pantalla.Print();
        reset = pantalla.ResetPosition();
        cout << reset;
        this_thread::sleep_for(0.1s);
    }

    return 0;
}