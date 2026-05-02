#include "SubstrateClassifier.h"

float SubstrateClassifier::classify(float input) {
    return input > 0.5f ? 1.0f : 0.0f;
}
