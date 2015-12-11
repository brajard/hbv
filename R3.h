/************************************************************
		module R3.h -
*************************************************************/

forward(YREAL STW, YREAL QPER2, YREAL K3){
  
    //YS1=STW+QPER2;
    //YS2=K3 * YS1;
    //YS1=YS1-YS2;

    YS1 = (STW + QPER2) - (K3 *(STW*QPER2));
    YS2 = K3 *(STW+QPER2);


}

//===========================================================
backward(YREAL STW, YREAL QPER2, YREAL K3){

	YJ1I1 = 1-K3*QPER2;
	YJ1I2 = 1-K3*STW;
	YJ1I3 = -STW*QPER2;

	YJ2I1 = K3;
	YJ2I2 = K3;
	YJ2I3 = STW+QPER2;

}  
