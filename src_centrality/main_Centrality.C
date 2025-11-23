#include "Centrality_Analyzer.C"


int main(){
	Centrality_Analyzer my_cen_analyzer;
	for (int i =0 ; i < 24;i++){
		my_cen_analyzer.InputFiles.push_back(Form("/gpfs01/star/scratch/fengliu/JAM2/sqrt_sNN_3p0_root/JAM2_sqrt_3p0_%d.root",i));
	}
	my_cen_analyzer.OutputFile = "/Users/feng/Documents/physics_project/Lambda_AuAu/genEvent/JAM1/forFeng_root/charged_multiplicity.root";
	my_cen_analyzer.Loop();
	return 0;
}