/************************************************************
		module ETR1.h -
	Partie de la décomposition du module ETR 
*************************************************************/
forward(YREAL SW, YREAL PWP)
{		
	YS1=SW-PWP;
}

//===========================================================
backward(YREAL SW, YREAL PWP)
{	
	YJ1I1 = 1;
	YJ1I2 = -1;
}
 
