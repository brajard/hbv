/************************************************************
		module Soil4.h -
*************************************************************/

forward(YREAL YS2Soil3,YREAL YS1Soil1, YREAL YS1Soil2){		

	if(YS2Soil3>=0){
		YS2= YS1Soil1 + YS2Soil3;
		YS1= YS1Soil2 - YS2Soil3;	
	}else{
		YS2=YS1Soil1;
		YS1=YS1Soil2;
		}
}

//===========================================================
backward(YREAL YS2Soil3,YREAL YS1Soil1, YREAL YS1Soil2){

	if(YS2Soil3 >=0){
		YJ1I1 = -1;
		YJ1I2 =  0;
		YJ1I3 =  1;

		YJ2I1 =  1;
		YJ2I2 =  1;
		YJ2I3 =  0;		

	}else{

		YJ1I1 =  0;
		YJ1I2 =  0;
		YJ1I3 =  1;

		YJ2I1 =  0;
		YJ2I2 =  1;
		YJ2I3 =  0;
		
	}

}
