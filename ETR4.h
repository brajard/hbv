/************************************************************
		module ETR4.h -
	Partie de la décomposition du module ETR
*************************************************************/
forward(YREAL YS1ETR3,YREAL YS1ETR2,YREAL SW)
{	
	if(YS1ETR3<0.0001){
		YS1=YS1ETR2-(0.0001-YS1ETR3);
		YS2=0.0001;
	}else{
		YS1=YS1ETR2;
		YS2=YS1ETR3;
	}	
}

//===========================================================
backward(YREAL YS1ETR3,YREAL YS1ETR2,YREAL SW)
{
	if(YS1ETR3<0){
		YJ1I1 = 1;
		YJ1I2 = 1; 
	}else{
		YJ1I2 = 1;  
		YJ2I1 = 1;			
	}
}
