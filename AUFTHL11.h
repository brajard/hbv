/************************************************************
		module AUFTHL11.h -
	  Décomposition du module AUFTHL1
*************************************************************/
forward(YREAL PS,YREAL HL1)
{	
	YS1 = PS - HL1;
}

//===========================================================
backward(YREAL PS,YREAL HL1)
{
	YJ1I1 = 1;
	YJ1I2 = -1;
}
  
