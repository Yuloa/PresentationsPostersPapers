void binning(){
  gROOT->ProcessLine(".x lhcbstyle_COLZ.C");


  TFile* D0file = new TFile("NTuples/GeneratedMC_withPhase.root", "READ");
  TTree* D0tree = (TTree*)D0file->Get("DalitzEventList");
  //TFile* D0barfile = new TFile("NTuples/D0bar_psf0.root", "READ");
  //TTree* D0bartree = (TTree*)D0barfile->Get("DalitzEventList");
  
  TH2F* d1 = new TH2F("d1", "d1", 50, 0, 2700000, 50, 0, 2700000);
  TH2F* d2 = new TH2F("d2", "d2", 50, 0, 2700000, 50, 0, 2700000);
  TH2F* d3 = new TH2F("d3", "d3", 50, 0, 2700000, 50, 0, 2700000);
  TH2F* d4 = new TH2F("d4", "d4", 50, 0, 2700000, 50, 0, 2700000);
  TH2F* d5 = new TH2F("d5", "d5", 50, 0, 2700000, 50, 0, 2700000);
  TH2F* d6 = new TH2F("d6", "d6", 50, 0, 2700000, 50, 0, 2700000);

  D0tree->SetAlias("s_12", "((_1_pi~_E+_2_pi#_E)**2 - (_1_pi~_Px+_2_pi#_Px)**2 - (_1_pi~_Py+_2_pi#_Py)**2 - (_1_pi~_Pz+_2_pi#_Pz)**2)");
  D0tree->SetAlias("s_13", "((_1_pi~_E+_3_pi#_E)**2 - (_1_pi~_Px+_3_pi#_Px)**2 - (_1_pi~_Py+_3_pi#_Py)**2 - (_1_pi~_Pz+_3_pi#_Pz)**2)");
  D0tree->SetAlias("s_123", "((_1_pi~_E+_2_pi#_E + _3_pi#_E)**2 - (_1_pi~_Px+_2_pi#_Px + _3_pi#_Px)**2 - (_1_pi~_Py+_2_pi#_Py + _3_pi#_Py)**2 - (_1_pi~_Pz+_2_pi#_Pz + _3_pi#_Pz)**2)");
  D0tree->SetAlias("A_mag", "sqrt(A_real**2 + A_imag**2)");
  
  D0tree->Draw("s_13:s_12>>d1", "Phase < -2.094");
  D0tree->Draw("s_13:s_12>>d2", "Phase >-2.094 && Phase < -1.047");
  D0tree->Draw("s_13:s_12>>d3", "Phase > -1.047 && Phase < 0");
  D0tree->Draw("s_13:s_12>>d4", "Phase > 0 && Phase < 1.046");
  D0tree->Draw("s_13:s_12>>d5", "Phase > 1.046 && Phase < 2.094");
  D0tree->Draw("s_13:s_12>>d6", "Phase > 2.094");

  d1->SetMarkerColor(kViolet);
  d2->SetMarkerColor(kBlue);
  d3->SetMarkerColor(kCyan);
  d4->SetMarkerColor(kGreen);
  d5->SetMarkerColor(kYellow);
  d6->SetMarkerColor(kRed);
  

  TCanvas cPlot2("cPlot2","B_MM");
  cPlot2.Divide(1,1);
  cPlot2.cd(1);
  d1->Draw();
  d2->Draw("same");
  d3->Draw("same");
  d4->Draw("same");
  d5->Draw("same");
  d6->Draw("same");
  cPlot2.SaveAs("Binning.pdf");


}
