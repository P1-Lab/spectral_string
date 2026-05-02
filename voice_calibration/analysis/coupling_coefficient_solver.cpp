struct CouplingMatrix {
    float massAnchor;
    float primarySurface;
    float edgeBoundary;
    float rigidDefinition;
    float bodyCoupling;
};

struct CouplingDeviation {
    float totalError;
};

CouplingDeviation computeCouplingDeviation(
    CouplingMatrix measured,
    CouplingMatrix reference
) {
    CouplingDeviation d;

    float error =
        fabs(measured.massAnchor - reference.massAnchor) +
        fabs(measured.primarySurface - reference.primarySurface) +
        fabs(measured.edgeBoundary - reference.edgeBoundary) +
        fabs(measured.rigidDefinition - reference.rigidDefinition) +
        fabs(measured.bodyCoupling - reference.bodyCoupling);

    d.totalError = error / 5.0f;

    return d;
}
