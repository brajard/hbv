/************************************************************
		module ETR2.h -
	Partie de la décomposition du module ETR
*************************************************************/
forward(YREAL YS1ETR1, YREAL ETP, YREAL SW)
{	
	if(YS1ETR1>0){
		YS1=ETP;		
	}else{
		YS1=ETP*(SW/(SW-YS1ETR1));
	}		
}

//===========================================================
backward(YREAL YS1ETR1, YREAL ETP, YREAL SW)
{
	if(YS1ETR1>0){
		YJ1I1=0;
		YJ1I2=1;
		YJ1I3=0;
	}else{
		YJ1I1= ( ETP *SW ) * pow(  ( SW - YS1ETR1 ),-2  );
		YJ1I2= SW / ( SW - YS1ETR1 );
		YJ1I3= (ETP/(SW-YS1ETR1))   -   (((ETP*SW)/(pow(SW-YS1ETR1,2))));
	}
}
 
