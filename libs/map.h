/**
 * Syntax
map(value, fromLow, fromHigh, toLow, toHigh)

Parameters
value: the number to map

fromLow: the lower bound of the value’s current range

fromHigh: the upper bound of the value’s current range

toLow: the lower bound of the value’s target range

toHigh: the upper bound of the value’s target range

Returns
The mapped value.
*/

#define map(x, inMin, inMax, outMin, outMax) ((x - inMin) * (outMax - outMin) / (inMax - inMin) + outMin)