{
    Dt = turbulence->nut()/Sct;
    Dt.correctBoundaryConditions();

    volScalarField DEff("DEff", turbulence->nu()/Sc + Dt);

    fvScalarMatrix CEqn
    (
        fvm::div(phi, C)
      - fvm::laplacian(DEff, C)
     ==
        fvOptions(C)
    );

    CEqn.relax();

    fvOptions.constrain(CEqn);

    CEqn.solve();

    fvOptions.correct(C);

    rhoS = 1 + MRef * (r - 1) / rhoRef * C; 
}
