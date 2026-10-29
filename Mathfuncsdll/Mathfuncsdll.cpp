#include "pch.h" 
#include "Mathfuncsdll.h"
#include <iostream>

namespace Mathfuncs
{
    ModelWindow::ModelWindow()
        : title("Default"), x(0), y(0), width(100), height(100), color("White"), isVisible(true), hasBorder(true) {
    }

    ModelWindow::ModelWindow(std::string winTitle, int startX, int startY, int w, int h, std::string winColor, bool visible, bool border)
        : title(winTitle), x(startX), y(startY), width(w), height(h), color(winColor), isVisible(visible), hasBorder(border) {
    }

    void ModelWindow::MoveHorizontal(int deltaX) {
        int newX = x + deltaX;
        if (newX >= 0 && (newX + width) <= maxWidth) {
            x = newX;
        }
        else {
            std::cout << "Warning: Out of horizontal screen bounds!\n";
        }
    }

    void ModelWindow::MoveVertical(int deltaY) {
        int newY = y + deltaY;
        if (newY >= 0 && (newY + height) <= maxHeight) {
            y = newY;
        }
        else {
            std::cout << "Warning: Out of vertical screen bounds!\n";
        }
    }

    void ModelWindow::Resize(int newWidth, int newHeight) {
        if (newWidth > 0 && (x + newWidth) <= maxWidth && newHeight > 0 && (y + newHeight) <= maxHeight) {
            width = newWidth;
            height = newHeight;
        }
        else {
            std::cout << "Warning: Cannot resize - screen bounds exceeded or invalid value!\n";
        }
    }

    void ModelWindow::SetColor(const std::string& newColor) {
        color = newColor;
    }

    void ModelWindow::SetVisibility(bool visible) {
        isVisible = visible;
    }

    void ModelWindow::SetBorder(bool border) {
        hasBorder = border;
    }

    std::string ModelWindow::GetTitle() const { return title; }
    int ModelWindow::GetX() const { return x; }
    int ModelWindow::GetY() const { return y; }
    int ModelWindow::GetWidth() const { return width; }
    int ModelWindow::GetHeight() const { return height; }
    std::string ModelWindow::GetColor() const { return color; }
    bool ModelWindow::IsVisible() const { return isVisible; }
    bool ModelWindow::HasBorder() const { return hasBorder; }

    void ModelWindow::Display() const {
        std::cout << "=== Window Settings: " << title << " ===\n"
            << "Window Position (X, Y): (" << x << ", " << y << ")\n"
            << "Size (width x height): " << width << " x " << height << "\n"
            << "Color: " << color << "\n"
            << "Visibility: " << (isVisible ? "Visible" : "Invisible") << "\n"
            << "Border: " << (hasBorder ? "With border" : "Without border") << "\n"
            << "===================================\n";
    }
}