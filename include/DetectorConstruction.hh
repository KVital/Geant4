#ifndef DetectorConstruction_H
#define DetectorConstruction_H 1

#include "G4VUserDetectorConstruction.hh"

class DetectorConstruction : public G4VUserDetectorConstruction
{                 
  public:
    DetectorConstruction();
    ~DetectorConstruction();
 G4int nLayers;
    G4VPhysicalVolume* Construct();
};

#endif

