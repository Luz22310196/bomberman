#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <thread>
#include <iostream>
#include <string>
#include <experimental/random>
#include <list>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    
    int fotograma = 0;
    string reset;

    int posX = 0;
    int posY = 0;

    while (true)
    {
        fotograma++; 

            int r = std::experimental::randint(0, 255);
            int g = std::experimental::randint(0, 255);
            int b = std::experimental::randint(0, 255);

        Element personaje = spinner(21, fotograma); 
        Decorator cfondo = bgcolor(Color::GrayDark);
        Decorator ctexto = color(Color::White);
        Element dibujo = border({hbox(personaje)| cfondo | ctexto});

        Dimensions Alto = Dimension::Fixed(10);
        Dimensions Ancho = Dimension::Full();

        Screen pantalla = Screen::Create(Ancho, Alto); 

        Render(pantalla, dibujo);

        list<string> textos;
        textos.push_back("primera linea");
        textos.push_back("segunda  linea");
        textos.push_back("tercer linea");
        int l = 0;
        for (auto &&texto : textos)
        {
            int i = 0;
            for (auto &&letra : texto)
            {
                pantalla.PixelAt(posX + i, posY + l).character = letra;
                i++;
            }
        }
        for(int i = 0; i< 5; i++)
        {
            pantalla.PixelAt(posX + i, 6).character = "-";
        }
        
        posX++;

        pantalla.Print();
        reset = pantalla.ResetPosition();
        cout << reset;
        this_thread::sleep_for(0.1s);
    }

    return 0;
}