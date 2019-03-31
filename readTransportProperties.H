singlePhaseTransportModel laminarTransport(U, phi);

// Thermal expansion coefficient [1/K]
dimensionedScalar beta
(
    "beta",
    dimless/dimTemperature,
    laminarTransport
);


dimensionedScalar MRef("MRef", dimensionSet (1, 0, 0, 0, -1, 0, 0), laminarTransport);

dimensionedScalar rhoRef("rhoRef", dimDensity, laminarTransport);

dimensionedScalar Sc("Sc", dimless, laminarTransport);


dimensionedScalar Sct("Sct", dimless, laminarTransport);
dimensionedScalar r("r", dimless, laminarTransport);