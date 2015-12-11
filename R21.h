/************************************************************
		module R21.h -
*************************************************************/

forward(YREAL STW, YREAL QPER1, YREAL K2){
  
     YS1= STW + QPER1;
     YS2= K2*(STW+QPER1);    
}

//===========================================================
backward(YREAL STW, YREAL QPER1, YREAL K2){
	YJ1I1=1;
	YJ1I2= 1;
	YJ1I3=0;
	
	YJ2I1=K2;
	YJ2I2=K2;
	YJ2I3=STW+QPER1;

} 
