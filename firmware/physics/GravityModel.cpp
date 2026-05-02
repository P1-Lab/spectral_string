#include "GravityModel.h"

float GravityModel::apply(float energy, float tension) {
    return energy / (1.0f + tension);
}
