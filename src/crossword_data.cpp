#include "crossword_data.h"

CrosswordData::CrosswordData():
    width(0), height(0), pointSize(10)
{

}
CrosswordData::~CrosswordData()
{

}
unsigned int CrosswordData::getWidth()
{
    return this->width;
}
unsigned int CrosswordData::getHeight()
{
    return this->height;
}
void CrosswordData::setSize(unsigned int w, unsigned int h)
{
    int n = 0;
    if (w>0 && h > 0)
    {
        this->width = w;
        this->height = h;
        status.resize(h);
        for (auto& items : status)
        {
            items.resize(w);
            for (auto& element : items)
            {
                n++;
                element = (n % 3 == 0) ? FieldColor::black : FieldColor::white;
            }
        }
    }
}

// получения статуса клетки по координатам (true - поле окрашенно)
// x - вправо, y - вниз
bool CrosswordData::isFieldColored(unsigned int x, unsigned int y)
{
    if (y < this->status.size())
    {
        const std::vector<FieldColor>& points = this->status.at(y);
        if (x < points.size())
        {
            return (points.at(x) == FieldColor::black);
        }
    }
    // если данные некорректные - возвращает заведомо некорерктный -1
    return false;
}
