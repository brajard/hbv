/************************************************************
		module R12.h -
*************************************************************/

forward(YREAL YS1R1, YREAL K1,YREAL ALPHA){    

    	YS1=K1*(pow(YS1R1,(1+ALPHA)));    

}

//===========================================================
backward(YREAL YS1R1, YREAL K1,YREAL ALPHA){	

	YJ1I1 = (K1) * (1+ALPHA) *  (pow(YS1R1,ALPHA));
	YJ1I2 = pow ( YS1R1 , 1 + ALPHA);
	
	YJ1I3 = (K1)*(log (YS1R1)) * (pow (YS1R1 , 1 + ALPHA));		
}
  
