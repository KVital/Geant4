#include "DetectorSD.hh"
#include "RunAction.hh"
#include "DetectorConstruction.hh"
#include "fstream"
#include "G4RunManager.hh"
#include "G4Step.hh"

DetectorSD::DetectorSD(G4String name): G4VSensitiveDetector(name)
{
  runAction = (RunAction*) G4RunManager::GetRunManager()->GetUserRunAction();
}

DetectorSD::~DetectorSD()
{ }

void DetectorSD::Initialize(G4HCofThisEvent*)
{}

G4bool DetectorSD::ProcessHits(G4Step* step, G4TouchableHistory*)
{
  
  G4StepPoint* prePoint = step->GetPreStepPoint();
  G4TouchableHandle touchable = prePoint->GetTouchableHandle();
  G4int layer1 = touchable->GetCopyNumber();
  G4int layer2 = touchable->GetCopyNumber(1);
  G4int layer3 = touchable->GetCopyNumber(2);

  G4double edep = step->GetTotalEnergyDeposit();

//std::cout<<edep<<"  "<<layer1<<"  "<<layer2<<"  "<<layer3<<"\n";

std::ofstream fi("EnergyBINcoord.txt", std::ios::app);
fi<<edep<<"  "<<layer1<<" "<<layer2<<" "<<layer3<<"\n" ;
  fi.close();
  return true;
}

void DetectorSD::EndOfEvent(G4HCofThisEvent*)
{}

