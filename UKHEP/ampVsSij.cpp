void ampVsSij(){
  gROOT->ProcessLine(".x lhcbstyle_COLZ.C");


  TFile* D0file = new TFile("NTuples/GeneratedMC_withPhase.root", "READ");
  TTree* D0tree = (TTree*)D0file->Get("DalitzEventList");
  //TFile* D0barfile = new TFile("NTuples/D0bar_psf0.root", "READ");
  //TTree* D0bartree = (TTree*)D0barfile->Get("DalitzEventList");
  
  TH2F* dhisti = new TH2F("dhisti", "dhisti", 50, 0, 2700000, 50, 0, 2700000);
  TH2F* norm = new TH2F("norm", "norm", 50, 0, 2700000, 50, 0, 2700000);
  TH2F* dhisti2 = new TH2F("dhisti2", "dhisti2", 50, 0, 2700000, 50, 0, 2700000);
  TH2F* norm2 = new TH2F("norm2", "norm2", 50, 0, 2700000, 50, 0, 2700000);

  TH2F* dh = new TH2F("dh", "dh", 50, 0, 2700000, 50, 0, 3100000);
  TH2F* n = new TH2F("n", "n", 50, 0, 2700000, 50, 0, 3100000);
  TH2F* dh2 = new TH2F("dh2", "dh2", 50, 0, 2700000, 50, 0, 3100000);
  TH2F* n2 = new TH2F("n2", "n2", 50, 0, 2700000, 50, 0, 3100000);


  D0tree->SetAlias("s_12", "((_1_pi~_E+_2_pi#_E)**2 - (_1_pi~_Px+_2_pi#_Px)**2 - (_1_pi~_Py+_2_pi#_Py)**2 - (_1_pi~_Pz+_2_pi#_Pz)**2)");
  D0tree->SetAlias("s_14", "((_1_pi~_E+_4_pi~_E)**2 - (_1_pi~_Px+_4_pi~_Px)**2 - (_1_pi~_Py+_4_pi~_Py)**2 - (_1_pi~_Pz+_4_pi~_Pz)**2)");
  D0tree->SetAlias("s_123", "((_1_pi~_E+_2_pi#_E + _3_pi#_E)**2 - (_1_pi~_Px+_2_pi#_Px + _3_pi#_Px)**2 - (_1_pi~_Py+_2_pi#_Py + _3_pi#_Py)**2 - (_1_pi~_Pz+_2_pi#_Pz + _3_pi#_Pz)**2)");
  D0tree->SetAlias("s_124", "((_1_pi~_E+_2_pi#_E + _4_pi~_E)**2 - (_1_pi~_Px+_2_pi#_Px + _4_pi~_Px)**2 - (_1_pi~_Py+_2_pi#_Py + _4_pi~_Py)**2 - (_1_pi~_Pz+_2_pi#_Pz + _4_pi~_Pz)**2)"); 


  D0tree->SetAlias("A_mag", "sqrt(A_real**2 + A_imag**2)");
  D0tree->SetAlias("phasi", "TMath::ATan(A_imag/A_real)");
  D0tree->SetAlias("Abar_mag", "sqrt(Abar_real**2 + Abar_imag**2)");

  D0tree->Draw("s_14:s_12>>dhisti", "sqrt(Abar_imag**2)");
  D0tree->Draw("s_14:s_12>>norm");
  D0tree->Draw("s_14:s_12>>dhisti2", "sqrt(Abar_mag)");
  D0tree->Draw("s_14:s_12>>norm2");

  D0tree->Draw("s_123:s_12>>dh", "A_real");
  D0tree->Draw("s_123:s_12>>n");
  D0tree->Draw("s_123:s_12>>dh2", "Abar_real");
  D0tree->Draw("s_123:s_12>>n2");


  dhisti->Divide(norm);
  dhisti2->Divide(norm2);
  dh->Divide(n);
  dh2->Divide(n2);
  //dhisti->SetMarkerColor(kPink);
  //dbhisti->SetMarkerColor(kBlue);

  TCanvas cPlot2("cPlot2","B_MM");
  cPlot2.Divide(1,1);
  cPlot2.cd(1);
  dhisti->Draw("COLZ");
  //cPlot2.cd(2);
  //dhisti2->Draw("COLZ");
  //cPlot2.cd(3);
  //dh->Draw("COLZ");
  //cPlot2.cd(4);
  //dh2->Draw("COLZ");
  cPlot2.SaveAs("Abar_imag2_s14.pdf");

  /*
  TH2F* p = new TH2F("p", "p", 50, 0, 2700000, 50, 0, 2700000);
  TH2F* normp = new TH2F("normp", "normp", 50, 0, 2700000, 50, 0, 2700000);

  TH2F* p2 = new TH2F("p2", "p2", 50, 0, 2700000, 50, 0, 3100000);
  TH2F* normp2 = new TH2F("normp2", "normp2", 50, 0, 2700000, 50, 0, 3100000);

  D0tree->Draw("s_14:s_12>>p", "phasi+3.14");
  D0tree->Draw("s_14:s_12>>normp");
  D0tree->Draw("s_123:s_12>>p2", "phasi+3.14");
  D0tree->Draw("s_123:s_12>>normp2");

  p->Divide(normp);
  p2->Divide(normp2);

  TCanvas cPlot2("cPlot3","B_MM");
  cPlot3.Divide(2,1);
  cPlot3.cd(1);
  p->Draw("COLZ");
  cPlot3.cd(2);
  p2->Draw("COLZ");
  cPlot3.SaveAs("Phases.pdf");
*/


}
