#pragma once
#ifdef MATHFUNCSDLL_EXPORTS
#define MATHFUNCSDLL_API __declspec(dllexport)
#else
#define MATHFUNCSDLL_API __declspec(dllimport)
#endif
#include <string>

namespace Mathfuncs
{
    class MATHFUNCSDLL_API ModelWindow
    {
    private:
        std::string title;    
        int x, y;             
        int width, height;    
        std::string color;    
        bool isVisible;       
        bool hasBorder;       

        const int maxWidth = 1920;
        const int maxHeight = 1080;

    public:
        ModelWindow();
        ModelWindow(std::string winTitle, int startX, int startY, int w, int h, std::string winColor, bool visible, bool border);

        void MoveHorizontal(int deltaX);
        void MoveVertical(int deltaY);

        void Resize(int newWidth, int newHeight);

        void SetColor(const std::string& newColor);

        void SetVisibility(bool visible);
        void SetBorder(bool border);

        std::string GetTitle() const;
        int GetX() const;
        int GetY() const;
        int GetWidth() const;
        int GetHeight() const;
        std::string GetColor() const;
        bool IsVisible() const;
        bool HasBorder() const;

        void Display() const;
    };
}