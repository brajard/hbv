/************************************************************
		module snow.h -
*************************************************************/

forward(YREAL P,YREAL TT, YREAL TC,YREAL degd, YREAL SD){
	double smelt;
	
	if (TT > TC){
		if(SD>0){
			smelt =(TT-TC)*degd;
			if(smelt>SD){
				YS1=P+SD;
				YS2=0;
			}else{
				YS1=P+smelt;
				YS2=P-smelt;
			}
		
		}else{
			YS1=P;
			YS2=0;
		}
	 }else{
		YS2=SD+P;
		YS1=0;
			
	  }
}

//===========================================================
backward(YREAL P,YREAL TT, YREAL TC,YREAL degd, YREAL SD){

	double smelt;

	if (TT > TC){
		if(SD>0){
			smelt =(TT-TC)*degd;
			if(smelt>SD){
				YJ1I1 = 1;				
				YJ1I5 = 1;				
			}else{
				YJ1I1 = 1;
				YJ1I2 = degd;
				YJ1I3 = -degd;
				YJ1I4 = TT-TC;				

				YJ2I1 = 1;
				YJ2I2 = -degd;
				YJ2I3 = degd;
				YJ2I4 = TC-TT;                               			
			}
		
		}else{
			YJ1I1 = 1;
			
		}
	 }else{	
		YJ2I1 = 1;		
                YJ2I5 = 1;			
	  }

}
 
