/************************************************************
		module R2.h -
*************************************************************/

forward(YREAL YS1R22, YREAL PER2){

     YS2 = PER2*YS1R22;
     YS1 = YS1R22-(PER2*YS1R22);    

}

//===========================================================
backward(YREAL YS1R22, YREAL PER2){

	YJ2I1 = PER2;
	YJ2I2 = YS1R22;

	YJ1I1 = 1-PER2;
	YJ1I2 = -YS1R22;

} 