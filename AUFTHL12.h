/************************************************************
		module AUFTHL12.h -
	 Décomposition du module AUFTHL1

	 on peut ne pas mettre le 0 par 
	 défault si on spécifie pas, YSi, 
		YJiIi sera mis à 0
*************************************************************/
forward(YREAL AUFTHL11,YREAL PS,YREAL AUFT)
{		
	if(AUFTHL11>0){
		YS2 = AUFTHL11 * AUFT;
		YS1 = PS - (AUFTHL11 * AUFT);
	}else{
		YS1=PS;
		YS2 = 0;
	}
}

//===========================================================
backward(YREAL AUFTHL11,YREAL PS, YREAL AUFT)
{
	if(AUFTHL11 > 0){
		YJ1I1 = - AUFT;
		YJ1I2 = 1;
		YJ1I3 = -AUFTHL11;

		YJ2I1 = AUFT;
		YJ2I2 = 0;
		YJ2I3 = AUFTHL11;	
	}else{
		YJ1I1 = 0;
		YJ1I2 = 1;
		YJ1I3 = 0;

		YJ2I1 = 0;
		YJ2I2 = 0;
		YJ2I3 = 0;		
	}
}
  
