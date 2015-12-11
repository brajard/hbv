/************************************************************
		module Soil1.h -
*************************************************************/

forward(YREAL PE, YREAL HW, YREAL FC, YREAL BE){
	
	YS1 = (PE)*(pow((HW/FC),BE));
}

//===========================================================
backward(YREAL PE, YREAL HW, YREAL FC, YREAL BE){

	YJ1I1 = pow((HW/FC),BE);

	YJ1I2 = ((PE)/(pow (FC,BE))) * (BE) * (pow (HW, BE-1));

	YJ1I3 = -((PE) * (pow (HW,BE)) * ((BE) /(pow (FC,BE+1)))) ;

	YJ1I4 = (PE) *(log (HW / FC)) * (pow( (HW / FC) , BE));
}
