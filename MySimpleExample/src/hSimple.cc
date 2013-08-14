/*!
 *
 * \class hSimple
 *
 * \brief  program for hsimple ROOT tutorial
 *
 * This program shows how to change from a macro to a simple standalone 
 * compiled program (w/o class implementation). It is based on the hsimple.C tutorial in $ROOTSYS. 
 * In addition doxygen documentation (html/latex/man-pages) is included as well as 
 * how to generate the distribution tarball/package.
 *
 * \par Make All
 * autoreconf -v --force --install\n
 * ./configure<br>
 * make
 *
 * \par Steps in Detail (see presentation ... url)
 * \li mk folders: src,docs,bin,pics,out
 * \li cp hsimple.C from $ROOTSYS/tutorials to src/hSimple.cc
 * \li Makefile.am, configure.ac, Doxyfile.in
 * \li hsimple mods: I/O stuff, save pic
 * \li add bin directory to $PATH in bashrc or bash_profile
 * \li hSimple running faster
 * \li add comments to hSimple.cc (class,brief,par,image,param,html-tags,formula)
 * \li modify docs/Doxyfile.in (l.2-6, l.99, l.142, l.176, logo)
 * \li ...

 * \par Images
 * \image html "pics/hSimple.png" "px distribution"
 * \image latex "pics/hSimple.png" "px distribution" width=10cm
 *
 * \par Usage
 * hSimple filename
 * \param[in] filename filename (incl. dir) for output file 
 *
 */

#include <iostream>
#include <cstdlib>
#include "TApplication.h"
#include "TRint.h"
#include "TString.h"
#include "TH1.h"
#include "Riostream.h"
#include <TFile.h>
#include <TNtuple.h>
#include <TH2.h>
#include <TProfile.h>
#include <TCanvas.h>
#include <TFrame.h>
#include <TROOT.h>
#include <TSystem.h>
#include <TRandom.h>
#include <TBenchmark.h>
#include <TInterpreter.h>
using namespace std;

void *hsimple(TFile* hfile) { // hSimple.C code

   // Create some histograms, a profile histogram and an ntuple
   TH1F *hpx = new TH1F("hpx","This is the px distribution",100,-4,4);
   hpx->SetFillColor(48);
   TH2F *hpxpy = new TH2F("hpxpy","py vs px",40,-4,4,40,-4,4);
   TProfile *hprof = new TProfile("hprof","Profile of pz versus px",100,-4,4,0,20);
   TNtuple *ntuple = new TNtuple("ntuple","Demo ntuple","px:py:pz:random:i");

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
   const Int_t kUPDATE = 1000;
   for (Int_t i = 0; i < 25000; i++) {
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
   c1->Print("pics/hSimple.png");
}

int main(int argc, char **argv) {
  TRint* theApp = new TRint("App", &argc, argv, NULL, 0);
  if ( theApp->Argc() == 2 ) {
   TString filename = theApp->Argv(1);
   TFile* hfile = new TFile(filename,"RECREATE");
   hsimple(hfile);
  }
  else {
    cout << "Usage:" << endl;
    cout << "hSimple filename" << endl;
  }
  theApp->Run();
  return 0;
}
