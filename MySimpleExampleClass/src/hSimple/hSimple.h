/* src/hSimple/hSimple.h */
/*!
 * \class hSimple
 *
 * \brief class for ROOT tutorial hsimple.C
 *
 * \author Patrick Huck
 */

#ifndef hSimple_h
#define hSimple_h
#include <TH1F.h>
#include <TH2F.h>
#include <TNtuple.h>
#include <TProfile.h>
#include <TFile.h>
#include <TString.h>

class hSimple {
  private: 
    TH1F *hpx; TH2F *hpxpy; TProfile *hprof;
    TNtuple *ntuple; TFile* hfile; TString png_name;
  public:
    hSimple(TFile* pfile); // constructor
    virtual ~hSimple() {}; // destructor
    void SetNamePNG(TString str) { png_name = str.Data(); }
    void Run(Int_t niter = 25000) ;
    ClassDef(hSimple,0)
};
#endif
