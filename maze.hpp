/**
 * The maze project is a maze game that uses raycasting to render the
 * walls.
 * This project is built on SDL2 and uses C++
 *
 * GitHub: https://github.com/Beautyome/maze_project
 */

#ifndef __MAZE_HPP__
#define __MAZE_HPP__

#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <iomanip>
#include <map>

#define MAZE_UNIQUE_IDENTIFIER // Add a unique identifier for include guards

namespace maze
{
    // Templates to get everything up and running.
    template <typename T>
    const T template_abs(const T &value)
    {
        return (value < 0) ? -value : value;
    }

    template <typename T>
    std::string valtostr(const T &value)
    {
        std::ostringstream stream;
        stream << value;
        return stream.str();
    }

    template <typename T>
    T strtoval(const std::string &stream)
    {
        T value;
        std::istringstream sstream(stream);
        sstream >> value;
        return value;
    }

    template <typename T>
    std::string valtostr(const T &value, int length, bool fixed = true)
    {
        std::ostringstream sstream;
        if (fixed)
            sstream << std::fixed;
        sstream << std::setprecision(length) << value;
        return sstream.str();
    }

    // COLOR STRUCTURES

    struct ColorRGB8bit;
    struct ColorRGB
    {
        int r;
        int g;
        int b;
        ColorRGB(Uint8 r, Uint8 g, Uint8 b);
        ColorRGB(const ColorRGB8bit &color);
        ColorRGB();
    };

    ColorRGB operator+(const ColorRGB &color1, const ColorRGB &color2);
    ColorRGB operator-(const ColorRGB &color1, const ColorRGB &color2);
    ColorRGB operator*(const ColorRGB &color1, int a);
    ColorRGB operator*(int a, const ColorRGB &color1);
    ColorRGB operator/(const ColorRGB &color1, int a);
    bool operator==(const ColorRGB &color1, const ColorRGB &color2);
    bool operator!=(const ColorRGB &color1, const ColorRGB &color2);

    // Updated color const
    static const ColorRGB RGB_Black = ColorRGB(0, 0, 0);
    static const ColorRGB RGB_White = ColorRGB(255, 255, 255);
    static const ColorRGB RGB_Red = ColorRGB(255, 0, 0);
    static const ColorRGB RGB_Green = ColorRGB(0, 128, 0); // Updated
    static const ColorRGB RGB_Blue = ColorRGB(0, 0, 255);
    static const ColorRGB RGB_Yellow = ColorRGB(255, 255, 0);
    static const ColorRGB RGB_Cyan = ColorRGB(0, 255, 255);
    static const ColorRGB RGB_Magenta = ColorRGB(255, 0, 255);
    static const ColorRGB RGB_Gray = ColorRGB(128, 128, 128);
    static const ColorRGB RGB_Gray50 = ColorRGB(128, 128, 128);
    static const ColorRGB RGB_Gray25 = ColorRGB(64, 64, 64);
    static const ColorRGB RGB_Maroon = ColorRGB(128, 0, 0);
    static const ColorRGB RGB_DarkGreen = ColorRGB(0, 128, 0);
    static const ColorRGB RGB_Navy = ColorRGB(0, 0, 128);
    static const ColorRGB RGB_Olive = ColorRGB(128, 128, 0);
    static const ColorRGB RGB_Teal = ColorRGB(0, 128, 128);
    static const ColorRGB RGB_Purple = ColorRGB(128, 0, 128);
    static const ColorRGB RGB_Silver = ColorRGB(192, 192, 192);
    static const ColorRGB RGB_Lime = ColorRGB(0, 255, 0);
    static const ColorRGB RGB_Orange = ColorRGB(255, 165, 0);
    static const ColorRGB RGB_Aqua = ColorRGB(0, 255, 255);
    static const ColorRGB RGB_Rose = ColorRGB(255, 0, 255);
    static const ColorRGB RGB_Amber = ColorRGB(255, 191, 0);
    static const ColorRGB RGB_Turquoise = ColorRGB(64, 224, 208);
    static const ColorRGB RGB_Violet = ColorRGB(238, 130, 238);
    static const ColorRGB RGB_Azure = ColorRGB(240, 255, 255);
    static const ColorRGB RGB_Beige = ColorRGB(245, 245, 220);
    static const ColorRGB RGB_Brown = ColorRGB(165, 42, 42);

    // Global var
    extern int w;
    extern int h;

    extern std::map<int, bool> key_pressed; // Key pressed -- Detect key press once only
    extern SDL_Window *scr;                 // Screen surface.
    extern Uint8 *inkeys;
    extern SDL_Event event;

    // Keyboard func
    __local__ bool KeyPressed(int key);
    __local__ bool KeyDown(int key);

    // Basic Screen func
    __local__ void lock();
    __local__ void screen(int width, int height, bool fullscreen, const std::string &title);
} // namespace maze

#endif // __MAZE_HPP__
