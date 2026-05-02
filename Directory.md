spectral-string/
├── README.md
├── LICENSE
├── CONTRIBUTING.md
│
├── hardware/
│ ├── mechanical_spec.md
│ ├── string_tension.md
│ ├── lever_tuning_system.md
│ ├── sensor_layout.md
│ └── BOM.md
│
├── firmware/
│ ├── main.cpp
│ ├── SystemState.h
│ ├── StateKernel.cpp
│ │
│ ├── physics/
│ │ ├── Constants.h
│ │ ├── PhiGovernor.cpp
│ │ ├── PhiGovernor.h
│ │ ├── GravityModel.cpp
│ │ └── GravityModel.h
│ │
│ ├── input/
│ │ ├── StringScanner.cpp
│ │ ├── StringScanner.h
│ │ ├── SubstrateClassifier.cpp
│ │ └── SubstrateClassifier.h
│ │
│ ├── nre/
│ │ ├── NRE_StateResolver.cpp
│ │ ├── NRE_StateResolver.h
│ │ ├── SpectralField.h
│ │ └── FieldIntegrator.cpp
│ │
│ └── io/
│ ├── AudioOutput.cpp
│ ├── AudioOutput.h
│ ├── SensorBus.cpp
│ └── SensorBus.h
│
└── docs/
├── theory.md
├── performance_modes.md
├── tuning_system.md
└── instrument_philosophy.md
