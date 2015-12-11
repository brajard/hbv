/************************************************************
		module ETP.h -
*************************************************************/

forward(YREAL T, YREAL TM, YREAL ETPM, YREAL CEF)
{    
      YS1 = ETPM*(1+(T-TM)*CEF);
}

//===========================================================
backward(YREAL T, YREAL TM, YREAL ETPM, YREAL CEF)
{
	YJ1I1	= CEF*ETPM;
	YJ1I2   = -(CEF*ETPM);
	YJ1I3   = 1+ (CEF * T) - (CEF * TM);
        YJ1I4   = (ETPM*T) - (ETPM*TM);
} 
