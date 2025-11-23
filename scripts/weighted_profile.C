void weighted_profile() {
    TProfile* prof = new TProfile("wprof", "Weighted Profile;X;Y", 30, 0, 5);
    
    TRandom3 rand;
    for (int i = 0; i < 5000; i++) {
        Double_t x = rand.Exp(2);
        Double_t y = sin(x) + rand.Gaus(0, 0.2);
        Double_t weight = 1.0 / (1.0 + x);  // 权重随 x 减小
        prof->Fill(x, y, weight);
    }
    
    prof->SetMarkerStyle(20);
    prof->Draw("E");
}
