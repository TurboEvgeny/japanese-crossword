#ifndef CROSSWORD_DATA_H
#define CROSSWORD_DATA_H
#include <vector>
enum class FieldColor : unsigned char
{
    white = 0,
    black = 1
};

class CrosswordData
{
public:
    CrosswordData();
    ~CrosswordData();
    unsigned int getWidth();
    unsigned int getHeight();
    // получения статуса клетки по координатам (true - поле окрашенно)
    // x - вправо, y - вниз
    bool isFieldColored(unsigned int x, unsigned int y);
    void setSize(unsigned int w, unsigned int h);
private:
    // ширина, длина кроссворда в клеточках
    unsigned int width;
    unsigned int height;
    // размер точки в пикселях
    int pointSize;
    // статус точки - (0 - белая, другое значение - черная)
    // первая координата высота, вторая - длина
    std::vector<std::vector<FieldColor>> status;
};

#endif // CROSSWORD_DATA_H
