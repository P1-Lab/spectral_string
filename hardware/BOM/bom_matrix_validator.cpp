// bom_matrix_validator.cpp
// Spectral String System — Scale Integrity Enforcement Layer

#include "BaseBOM.h"
#include "VariantDeltas.h"

namespace BOMValidator {

enum class ScaleType {
    MINI,
    STANDARD,
    STAGE
};

struct BOMState {
    double impedance;        // must remain >= 10MΩ system-wide
    double enclosureMass;
    double powerCapacity;
    double rigidityIndex;
};

bool validateImpedance(const BOMState& state) {
    return state.impedance >= 10e6;
}

bool validateRigidityConsistency(const BOMState& base,
                                 const BOMState& variant) {
    // Stage cannot be less rigid than Standard
    if (variant.rigidityIndex < base.rigidityIndex) {
        return false;
    }
    return true;
}

bool validatePowerScaling(ScaleType type, const BOMState& state) {
    switch (type) {
        case ScaleType::MINI:
            return state.powerCapacity <= 0.6;
        case ScaleType::STANDARD:
            return state.powerCapacity <= 1.0;
        case ScaleType::STAGE:
            return state.powerCapacity >= 1.0;
    }
    return false;
}

bool validateBOM(const BOMState& base,
                 const BOMState& variant,
                 ScaleType type) {

    if (!validateImpedance(variant)) {
        return false;
    }

    if (!validateRigidityConsistency(base, variant)) {
        return false;
    }

    if (!validatePowerScaling(type, variant)) {
        return false;
    }

    return true;
}

} // namespace BOMValidator
