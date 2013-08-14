/* src/hSimple/hSimple.cxx */
#include "Riostream.h"
#include "hSimple.h"
#include <TCanvas.h>
#include <TBenchmark.h>
#include <TFrame.h>
#include <TRandom.h>
#include <TSystem.h>
using namespace std;

ClassImp(hSimple)

hSimple::hSimple(TFile* pfile) { // init all private class members
  hfile = pfile;
  png_name = "../pics/hSimple.png";
  // Create some histograms, a profile histogram and an ntuple
  hpx    = new TH1F("hpx","This is the px distribution",100,-4,4);
  hpxpy  = new TH2F("hpxpy","py vs px",40,-4,4,40,-4,4);
  hprof  = new TProfile("hprof","Profile of pz versus px",100,-4,4,0,20);
  ntuple = new TNtuple("ntuple","Demo ntuple","px:py:pz:random:i");
  hpx->SetFillColor(48);
}

void hSimple::Run(Int_t niter) { // hSimple.C code

  cout << "niter = " << niter << endl;
  gBenchmark->Start("hsimple");
  // Create a new canvas.
  TCanvas *c1 = new TCanvas("c1","Dynamic Filling Example",200,10,700,500);
  c1->SetFillColor(42);
  c1->GetFrame()->SetFillColor(21);
  c1->GetFrame()->SetBorderSize(6);
  c1->GetFrame()->SetBorderMode(-1);

  // Fill histograms randomly
  gRandom->SetSeed();
  Float_t px, py, pz;
  const Int_t kUPDATE = 10000;
  for (Int_t i = 0; i < niter; i++) {
    gRandom->Rannor(px,py);
    pz = px*px + py*py;
    Float_t random = gRandom->Rndm(1);
    hpx->Fill(px);
    hpxpy->Fill(px,py);
    hprof->Fill(px,pz);
    ntuple->Fill(px,py,pz,random,i);
    if (i && (i%kUPDATE) == 0) {
      if (i == kUPDATE) hpx->Draw();
      c1->Modified();
      c1->Update();
      if (gSystem->ProcessEvents())
	break;
    }
  }
  gBenchmark->Show("hsimple");

  // Save all objects in this file
  hpx->SetFillColor(0);
  hfile->Write();
  hpx->SetFillColor(48);
  c1->Modified();
  c1->Print(png_name.Data());
}

