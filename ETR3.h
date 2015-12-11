/************************************************************
		module ETR3.h -
	Partie de la décomposition du module ETR
*************************************************************/
forward(YREAL YS1ETR2,YREAL SW)
{	
	YS1=SW-YS1ETR2;		
}

//===========================================================
backward(YREAL YS1ETR2,YREAL SW)
{
	YJ1I1 = -1;
	YJ1I2 = 1;
}
