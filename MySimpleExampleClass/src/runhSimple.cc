/*!
 *
 * \class runhSimple
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
#include "hSimple/hSimple.h"
#include "Options/Options.h"
using namespace std;

int main(int argc, char **argv) {
  // decode options
  const char * optv[] = {"N:NIter <nit>","O:NamePNG <pngstr>",NULL} ;
  Int_t nit = 30000;
  TString pngstr;
  Options  opts(*argv, optv);
  OptArgvIter  iter(--argc, ++argv);
  const char *optarg;
  int argcR = argc;
  char **argvR;
  while( char optchar = opts(iter, optarg) ) {
    switch (optchar) {
    case 'N' :
    nit = (Int_t)atoi(optarg); argcR=argcR-2; break;
    case 'O' : pngstr = optarg; argcR=argcR-2; break;
    default : break;
    } 
  }
  argvR = new char*[argcR];
  Int_t cnter = 0;
  if (iter.index() < argc) {
    for (int i = iter.index() ; i < argc ; i++) { argvR[cnter] = argv[i]; ++cnter; }
  }
  // application
  TRint* theApp = new TRint("App", &argcR, argvR, NULL, 0);
  if ( theApp->Argc() == 1 ) {
   TString filename = theApp->Argv(0);
   TFile* hfile = new TFile(filename,"RECREATE");
   hSimple *hs = new hSimple(hfile);
   if ( pngstr.Contains("png") ) hs->SetNamePNG(pngstr.Data());
   hs->Run(nit);
  }
  else {
    cout << "Usage:" << endl;
    cout << "hSimple filename" << endl;
  }
  theApp->Run();
  return 0;
}
