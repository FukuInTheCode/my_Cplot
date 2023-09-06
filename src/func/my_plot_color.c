#include "../../includes/my.h"

sfColor interpolateColor(sfColor color1, sfColor color2, float value)
{
    sfColor result;

    result.r = (sfUint8)((1 - value) * color1.r + value * color2.r);
    result.g = (sfUint8)((1 - value) * color1.g + value * color2.g);
    result.b = (sfUint8)((1 - value) * color1.b + value * color2.b);
    result.a = (sfUint8)((1 - value) * color1.a + value * color2.a);

    return result;
}
