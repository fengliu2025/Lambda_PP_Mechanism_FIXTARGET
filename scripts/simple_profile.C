// simple_profile.C
void simple_profile() {
    // 创建 profile
    TProfile *prof = new TProfile("prof", "简单示例: Y vs X;X;Y的值", 20, 0, 10);
    
    TRandom3 rand;
    
    // 填充数据: y = x + 噪声
    for (int i = 0; i < 1000; i++) {
        Double_t x = rand.Uniform(0, 10);
        Double_t y = x + rand.Gaus(0, 1);  // 线性关系加噪声
        prof->Fill(x, y);
    }
    
    // 绘制
    TCanvas *c1 = new TCanvas("c1", "Simple Profile", 600, 400);
    prof->SetLineColor(kBlue);
    prof->SetMarkerStyle(20);
    prof->Draw("E1");
    
    // 添加理论直线
    TF1 *f = new TF1("f", "x", 0, 10);
    f->SetLineColor(kRed);
    f->SetLineStyle(2);
    f->Draw("SAME");
    
    // 添加图例
    TLegend *leg = new TLegend(0.6, 0.2, 0.9, 0.3);
    leg->AddEntry(prof, "数据", "lep");
    leg->AddEntry(f, "理论: y = x", "l");
    leg->Draw();
}
