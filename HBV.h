
///////////////////////////////////////////////////////////////////////////////
// define, globales, fonctions perso (obligatoire et autres) ...
///////////////////////////////////////////////////////////////////////////////


// DES PROTOTYPAGES NECESSAIRES !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


// Les fonctions propres à l'appli :===========================================
//   les OBLIGATOIRES
//_____________________________________________________________________________
void xdisplay();
void appli_start (int argc, char *argv[])
{			// permet si besoin de prendre la main des le debut de l'appli
			printf("\t*************************************************************\n");
			printf("\t**********  Assimiliation de donnees:modele HBV *************\n");
			printf("\t*************************************************************\n");
			

	
}
//_____________________________________________________________________________
void before_it (int Yit)
{			// permet d'intervenir si besoin avant une iteration
}
//_____________________________________________________________________________
void cost_function (int pdt)
{			// fonction de cout (si les standards ne conviennent pas)
}
//_____________________________________________________________________________
void adjust_target ()
{			// fonction d'ajustement (si la standard ne convient pas)
}
//_____________________________________________________________________________
void after_it (int nit)
{			// permet d'intervenir si besoin apres une iteration
}
//_____________________________________________________________________________
void forward_before (int ctrp)
{			// permet d'intervenir si besoin avant le forward
}
//_____________________________________________________________________________
void forward_after (int ctrp)
{			// permet d'intervenir si besoin apres le forward
//pb: affichage des valeurs: ca affiche toujours les memes valeurs (initiales)
}
//_____________________________________________________________________________
void backward_before (int ctrp)
{			// permet d'intervenir si besoin avant le backward
}
//_____________________________________________________________________________
void backward_after (int ctrp)
{			// permet d'intervenir si besoin apres le backward
}
//_____________________________________________________________________________
short select_io(int indic, char *nmmod, int sortie, int iaxe, int jaxe, int kaxe, int pdt, YREAL *val)
{			// Pour faire des selections sur les fonctions d'entrees sorties de Yao ou autre en generale.
			// Doit retourner 1 si l'element dont les caracteristiques sont passes en parametre doit
			// etre retenu, pris, selectionne ; et 0 sinon
			// indic permet de savoir de quelle instance provient l'appel :
			// =YIO_LOADSTATE	 => appel via loadstate
			// =YIO_SAVESTATE	 => appel via savestate
			// =YIO_LOADOBS	   => appel via loadobs
			// =YIO_OUTOOBS	   => appel via outoobs
			// =YIO_LISTOBS	   => appel via listobs
			return(1);
}
//-----------------
void	xdisplay ()
{
	printf("setstate ALPHA   % -16.8e \n", YS1_ALPHA(0));
	printf("setstate BE      % -16.8e \n", YS1_BE(0));
	printf("setstate CEF     % -16.8e \n", YS1_CEF(0));
	printf("setstate FC      %e \n", YS1_FC(0));
	printf("setstate K1      % -16.8e \n", YS1_K1(0));
	printf("setstate K2      % -16.8e \n", YS1_K2(0));
	printf("setstate K3      % -16.8e \n", YS1_K3(0));

	printf("setstate PER1    % -16.8e \n", YS1_PER1(0));
	printf("setstate PER2    % -16.8e \n", YS1_PER2(0));
	printf("setstate PWP     % -16.8e \n", YS1_PWP(0));

	printf("setstate AUFT    % -16.8e \n", YS1_AUFT(0));
	printf("setstate HL1     % -16.8e \n", YS1_HL1(0));
	printf("setstate degd    % -16.8e \n", YS1_degd(0));
	printf("setstate TC      % -16.8e \n\n", YS1_TC(0));

	printf("-----------------------Normalisé\n");
	printf("setstate ALPHA   % -16.8e \n", YS1_ALPHA(0)/6);
	printf("setstate BE      % -16.8e \n", YS1_BE(0)/6);
	printf("setstate CEF     % -16.8e \n", YS1_CEF(0)/0.3);
	printf("setstate FC      %e \n", YS1_FC(0)/500);
	printf("setstate K1      % -16.8e \n", YS1_K1(0)/0.1);
	printf("setstate K2      % -16.8e \n", YS1_K2(0)/0.1);
	printf("setstate K3      % -16.8e \n", YS1_K3(0)/0.1);

	printf("setstate PER1    % -16.8e \n", YS1_PER1(0));
	printf("setstate PER2    % -16.8e \n", YS1_PER2(0));
	printf("setstate PWP     % -16.8e \n", YS1_PWP(0)/500);

	printf("setstate AUFT    % -16.8e \n", YS1_AUFT(0)/6);
	printf("setstate HL1     % -16.8e \n", YS1_HL1(0)/6);
	printf("setstate degd    % -16.8e \n", YS1_degd(0));
	printf("setstate TC      % -16.8e \n\n", YS1_TC(0)/2.5);


	//printf("SW initial ------------------ >s=% -16.8e \n", YS1_Soil4(0,0));
	printf("HW  initial ------------------ >s=% -16.8e \n", YS1_SW(0,0));
	printf("STW1 initial ------------------ >s=% -16.8e \n", YS1_STW1(0,0));
	printf("STW2 initial ------------------ >s=% -16.8e \n", YS1_STW2(0,0));
	printf("STW3 initial ------------------ >s=% -16.8e \n", YS1_STW3(0,0));


        
	printf("HW final ------------------ >s=% -16.8e \n", YS2_ETR4(0,NT));

	ofstream fichier("initSw", ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert
	ofstream fichier_2("finalSW", ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert
	ofstream fichier_3("ALPHA", ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert
	ofstream fichier_4("ALPHA2", ios::app);

	ofstream fichier_5("SW", ios::app);
	ofstream fichier_6("STW1", ios::app);
	ofstream fichier_7("STW2", ios::app);
	ofstream fichier_8("STW3", ios::app);
	//ofstream fichier_9("./script/bornes.i", ios::out | ios::trunc);
	
 
        if(fichier && fichier_2 && fichier_3 && fichier_4)
        {     
		if(isnan(YS1_STW1(0,0))||isnan(YS1_STW2(0,0))||isnan(YS1_STW3(0,0))||isnan(YS1_Q1(0,0))||isnan(YS1_Q2(0,0))||isnan(YS1_Q3(0,0))||isnan(YS1_SW(0,0))||isnan(YS1_SW(0,0))){
			fichier << "init  0.0073 0.0786  32.8  0  0.005  0.0364  67.552  67.552"<<endl; 
		}else{
               				 fichier << "init  "<<YS1_STW1(0,0)<<"  " << YS1_STW2(0,0) <<"  "<< YS1_STW3(0,0)<<"  "<< YS1_Q1(0,0)<<"  "<< YS1_Q2(0,0) <<"  " << YS1_Q3(0,0) << "  "<< YS1_SW(0,0)<< "  "<<YS1_SW(0,0)<<endl; 
		}

		if(isnan(YS1_STW1(0,NT_1))||isnan(YS1_STW2(0,NT_1))||isnan(YS1_STW3(0,NT_1))||isnan(YS1_Q1(0,NT_1))||isnan(YS1_Q2(0,NT_1))||isnan(YS1_Q3(0,NT_1))||isnan(YS1_SW(0,NT_1))||isnan(YS1_SW(0,NT_1))){
			fichier_2 << "init  0.0073 0.0786  32.8  0  0.005  0.0364  67.552  67.552"<<endl; 
		}else{
		fichier_2 << "init  "<<YS1_STW1(0,NT_1)<<"  " << YS1_STW2(0,NT_1) <<"  "<< YS1_STW3(0,NT_1)<<"  "<< YS1_Q1(0,NT_1)<<"  "<< YS1_Q2(0,NT_1) <<"  " << YS1_Q3(0,NT_1) << "  "<< YS1_SW(0,NT_1)<< "  "<<YS1_SW(0,NT_1)<<endl; 
		}
		
		fichier_3 <<"setstate ALPHA    "<<YS1_ALPHA(0)<<endl;
		fichier_4 <<YS1_ALPHA(0)<<endl;
		
			fichier_5 <<YS1_SW(0,0)<<endl;
		fichier_6 <<YS1_STW1(0,0)<<endl;
		fichier_7 <<YS1_STW2(0,0)<<endl;
		fichier_8 <<YS1_STW3(0,0)<<endl;

		 	 printf("*************** ------------------ >s=% -16.8e \n", YS1_ALPHA(0));
	                printf("*************** ------------------ >s=% -16.8e \n", YS1_SW(0,0));
			printf("*************** ------------------ >s=% -16.8e \n", YS1_STW1(0,0));
			printf("***************------------------ >s=% -16.8e \n", YS1_STW2(0,0));
			printf("*************** ------------------ >s=% -16.8e \n", YS1_STW3(0,0));
 
                fichier.close();
		fichier_2.close();
		fichier_3.close();
		fichier_4.close();
		fichier_5.close();
		fichier_6.close();
		fichier_7.close();
		fichier_8.close();
		//fichier_9.close();
        }
        else
                cerr << "Impossible d'ouvrir le fichier !" << endl;
 
        
	
}


void load_in(char *file){



}

void init(int argc, char *argv[]){

	YS1_STW1 (0,0) = atof(argv[1]);
	YS1_STW2 (0,0) = atof(argv[2]);
	YS1_STW3  (0,0) = atof(argv[3]);
	YS1_Q1 (0,0) = atof(argv[4]);
	YS1_Q2 (0,0) = atof(argv[5]);
	YS1_Q3  (0,0) = atof(argv[6]);	
	YS1_SW (0,0)=atof(argv[7]);	
	YS1_Soil4(0,0)=atof(argv[8]);
 
}

//_____________________________________________________________________________
// LES AUTRES (appelable depuis n'importe quel module et par l'interpréteur
//_____________________________________________________________________________
/*void xprint_xinf()
	{
	  int j;
	  for (j=0;j<YNBMODUL;j++)
	    {
	      if (GY_itarget[j]>-1)
	        {
	          printf("Module %s(%d) : min=%f, max=%f\n",YTabMod[j].Name,GY_itarget[j],Y3xinf[GY_itarget[j]*YTabMod[j].axi],Y3xsup[GY_itarget[j]*YTabMod[j].axi]);
	        }
	    }
	 
	}
*/
