void binning(){
  gROOT->ProcessLine(".x lhcbstyle_COLZ.C");


  TFile* D0file = new TFile("NTuples/GeneratedMC_withPhase.root", "READ");
  TTree* D0tree = (TTree*)D0file->Get("DalitzEventList");
  //TFile* D0barfile = new TFile("NTuples/D0bar_psf0.root", "READ");
  //TTree* D0bartree = (TTree*)D0barfile->Get("DalitzEventList");
  
  TH1D* d1 = new TH1D("d1", "d1", 16, -3.14, 3.14);
  TH1D* d2 = new TH1D("d2", "d2", 16, -3.14, 3.14);
  TH1D* d3 = new TH1D("d3", "d3", 16, -3.14, 3.14);


  D0tree->SetAlias("s_12", "((_1_pi~_E+_2_pi#_E)**2 - (_1_pi~_Px+_2_pi#_Px)**2 - (_1_pi~_Py+_2_pi#_Py)**2 - (_1_pi~_Pz+_2_pi#_Pz)**2)");
  D0tree->SetAlias("s_13", "((_1_pi~_E+_3_pi#_E)**2 - (_1_pi~_Px+_3_pi#_Px)**2 - (_1_pi~_Py+_3_pi#_Py)**2 - (_1_pi~_Pz+_3_pi#_Pz)**2)");
  D0tree->SetAlias("s_123", "((_1_pi~_E+_2_pi#_E + _3_pi#_E)**2 - (_1_pi~_Px+_2_pi#_Px + _3_pi#_Px)**2 - (_1_pi~_Py+_2_pi#_Py + _3_pi#_Py)**2 - (_1_pi~_Pz+_2_pi#_Pz + _3_pi#_Pz)**2)");
  D0tree->SetAlias("A_mag", "sqrt(A_real**2 + A_imag**2)");
  D0tree->SetAlias("phasi", "TMath::ATan(A_imag/A_real)");


  /*float phase = -999;
  float phasebar = -999;
  D0tree->SetBranchAddress("Phase", &phase);
  D0tree->SetBranchAddress("Phasebar", &phasebar);
  
  int events[16]= {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  double Dd = -999;
  
  for(int i =0; i< D0tree->GetEntries();i++){
    D0tree->GetEntry(i);
    Dd = phase-phasebar;
    for(int j = -8; j<9; j++){
      if(0!=j){
	if(2*3.14*(j - 1.5) < Dd && Dd < 2*3.14*(j - 0.5)){
	  events[j+8]+=1;
	}
      }
    }
  }
  
  for(int j = 0; j<17; j++){
    if(0!=j){
      d1->Fill(j-8, events[j]);
    }
  }

  */  
    
  D0tree->Draw("Phase - Phasebar>> d1");
  D0tree->Draw("Phase >> d2");
  D0tree->Draw("Phasebar >> d3");
  //D0tree->Draw("phasi>>d2");
  
  d1->SetLineColor(kPink);
  d1->SetLineWidth(2);
  d3->SetLineColor(kBlue);
  //d2->SetLineStyle(kDashed);

  TCanvas cPlot2("cPlot2","B_MM");
  cPlot2.Divide(1,1);
  cPlot2.cd(1);
  d1->Draw();
  d2->Draw("same");
  d3->Draw("same");
  cPlot2.SaveAs("Binning.pdf");


}
