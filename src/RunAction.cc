#include "RunAction.hh"

#include "G4Run.hh"
#include "Randomize.hh"
#include "DetectorConstruction.hh"
#include "G4RunManager.hh"


RunAction::RunAction() {}

RunAction::~RunAction() {}

void RunAction::BeginOfRunAction(const G4Run*)
{ }

void RunAction::FillHist()
{}

void RunAction::EndOfRunAction(const G4Run* )
{ }

