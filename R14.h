/************************************************************
		module R14.h -
*************************************************************/

forward(YREAL YS1R3,YREAL YS1R2,YREAL STW, YREAL QD){      
	if(YS1R3<0.0001){
		YS1=0.0001;
		YS2=STW+QD;//-(0.0001-YS1R3)
	}else{
		YS1 = YS1R3;
		YS2 = YS1R2;
	}
}

//===========================================================
backward(YREAL YS1R3,YREAL YS1R2,YREAL STW, YREAL QD){

	if(YS1R3<0){
		YJ1I1 = 0;
		YJ1I2 = 0;	
		YJ1I3 = 0;
		YJ1I4 = 0;

		YJ2I1 = 0;
		YJ2I2 = 0;
		YJ2I3 = 1;
		YJ2I4 = 1;
	}else{
		YJ1I1 = 1;
		YJ1I2 = 0;	
		YJ1I3 = 0;
		YJ1I4 = 0;

		YJ2I1 = 0;
		YJ2I2 = 1;
		YJ2I3 = 0;
		YJ2I4 = 0;
	
	}
}
  
