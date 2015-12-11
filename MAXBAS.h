 /************************************************************
		     module MXBAS3.h -
        Module maxbas, ici maxbas = 4 et il est fixe.
        on peut pas controler maxbas, mais ça peut se faire avec yao, 
        dans ce cas il faudrais une approche différente (voir le module Q1 et Q9 du modele GR4J)
        là il peut etre compensé par d'autre paramètres
*************************************************************/
forward(YREAL QTOT,YREAL QW1,YREAL QW2,YREAL QW3)
{
	YS1= QW1 +(0.166667 * QTOT);
	YS2= QW2 +(0.333333 * QTOT);
	YS3= QW3 +(0.333333 * QTOT);
	YS4= (0.166667 * QTOT);
}

//===========================================================
backward(YREAL QTOT,YREAL QW1,YREAL QW2,YREAL QW3)
{
	YJ1I1= 0.166667;
	YJ1I2= 1;

	YJ2I1= 0.333333;
	YJ2I3= 1;

	YJ3I1= 0.333333;
	YJ3I4= 1;

	YJ4I1= 0.166667;

}
 
 

