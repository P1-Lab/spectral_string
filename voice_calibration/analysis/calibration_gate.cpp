#include <iostream>

enum CalibrationState {
    PASS,
    FAIL,
    DRIFT_WARNING,
    RECALIBRATE
};

CalibrationState evaluateGate(float score, float drift) {

    if (score < 0.70f) {
        return FAIL;
    }

    if (score < 0.85f || drift > 0.15f) {
        return DRIFT_WARNING;
    }

    if (drift > 0.25f) {
        return RECALIBRATE;
    }

    return PASS;
}
