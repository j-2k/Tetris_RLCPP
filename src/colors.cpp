#include "colors.h"

const Color grey = {30,30,30,255};
const Color green = {30,255,30,255};
const Color red = {255,30,30,255};
const Color orange = {255,150,30,255};
const Color yellow = {255,255,30,255};
const Color purple = {200,30,255,255};
const Color cyan = {30,255,255,255};
const Color blue = {30,30,255,255};

std::vector<Color> GetCellColors()
{
    return {grey,green,red,orange,yellow,purple,cyan,blue};
}