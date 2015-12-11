#==========================================================
# 	       fichier de DESCRIPTION HBV.d
#
#       RESPECTER L'ORDRE DE DECLARATION DES DIRECTIVES
#==========================================================
//DEFVAL pour definir des trucs ----------------------DEFVAL
defval NT 43854  //Nombre de pas de temps
defval NT_1 2 //Les conditions initiales avant la mise à jour pour la prévision

//NAME ---------------------------------------------HAT_NAME
hat_name "HBV.h"

//OPTION ---------------------------------------------OPTION
option  O_GRADTEST
option  O_M1QN3 M2QN1
option O_REAL double
option  O_VARINCR

//TRAJECTOIRES ------(en secondes)----------------------TRAJ
#traj  nom  type upt  offt dt stept
traj  Tpar   M   0         1
traj  Tm     M   1         NT			 

 
//ESPACES ---------------------------------------------SPACE
#space  nom  type  SZX SZY  Traj
space  Sm     M   1       Tm
space  Spar   M   1       Tpar

//MODULES -------------------------------------------MODULES
//******************************** Paramètres
modul TC   space Spar noward output 1  	
modul degd space Spar noward output 1   
modul HL1  space Spar noward output 1  	
modul AUFT space Spar noward output 1  	

modul FC   space Spar  noward output 1 	target
modul BE   space Spar  noward output 1	
modul CEF  space Spar  noward output 1  
modul PWP  space Spar  noward output 1  

modul K1   space Spar  noward output 1  
modul K2   space Spar  noward output 1	
modul K3   space Spar  noward output 1	

modul ALPHA space Spar noward output 1   


modul PER1  space Spar noward output 1   
modul PER2  space Spar noward output 1	 

//********************************fin de la déclaration des paramètres du Modèl

//********************************déclaration des Entrées
modul PE    space Sm noward output 1 tempo	
modul TT    space Sm noward output 1 tempo
modul TM    space Sm noward output 1 tempo
modul ETPM  space Sm noward output 1 tempo

//********************************fin déclaration des Entrées


//*******************************déclaration des modules avec le nombre d'entrée et de sortie de chaque modul

modul Snow    space Sm input 5 output 2 tempo

//modul AUFTHL1 space Sm input 3 output 2 tempo
modul AUFTHL11  space Sm input 2 output 1 tempo
modul AUFTHL12  space Sm input 3 output 2 tempo  

//modul Soil 	space Sm input 4 output 2 tempo
modul Soil1     space Sm input 4 output 1 tempo    
modul Soil2     space Sm input 3 output 1 tempo
modul Soil3     space Sm input 2 output 1 tempo
modul Soil4     space Sm input 3 output 2 tempo	 	

modul ETP 	space Sm input 4 output 1 tempo

//modul ETR	space Sm input 3 output 2 tempo	
modul ETR1      space Sm input 2 output 2 tempo
modul ETR2      space Sm input 3 output 1 tempo
modul ETR3      space Sm input 2 output 1 tempo
modul ETR4      space Sm input 3 output 2 tempo  

//modul R1	space Sm input 5 output 3 tempo	
modul R11       space Sm input 2 output 1 tempo
modul R12       space Sm input 3 output 1 tempo
modul R13       space Sm input 2 output 1 tempo
modul R14       space Sm input 4 output 2 tempo  
modul R15       space Sm input 2 output 2 tempo  


//modul R2   	space Sm input 4 output 3 tempo
modul R21       space Sm input 3 output 2 tempo  
modul R22       space Sm input 2 output 1 tempo
modul R23       space Sm input 2 output 2 tempo  

modul R3 	space Sm input 3 output 2 tempo  
modul QTOT      space Sm input 4 output 1 tempo  
modul MAXBAS    space Sm input 4 output 4 tempo

modul Q1        space Sm input 1 output 1 tempo    
modul Q2        space Sm input 1 output 1 tempo    
modul Q3        space Sm input 1 output 1 tempo    
modul STW1        space Sm input 1 output 1 tempo               //ce qu'on veut contrôler
modul STW2        space Sm input 1 output 1 tempo   
modul STW3        space Sm input 1 output 1 tempo   

modul SW        space Sm input 1 output 1 tempo    

modul QS        space Sm input 1 output 1 tempo  cout                //ce qu'on assimile

//*******************************déclaration des modules 

//********************************CONNECTIONS ENTRE LES MODULES (GRAPHE MODULAIRE) ---------------------------------CTIN-M
//ctin PEMOD 1  from PEMOD 1     i     t-1
//ctin PEMOD 2  from PE    1     i     t

ctin Snow  1  from PE    1     i     t
ctin Snow  2  from TT    1     i     t
ctin Snow  3  from TC    1     i
ctin Snow  4  from degd  1     i
ctin Snow  5  from Snow  2     i     t-1

//ctin AUFTHL1  1  from Snow  1   i    t
//ctin AUFTHL1  2  from HL1   1   i
//ctin AUFTHL1  3  from AUFT  1   i

ctin AUFTHL11   1  from Snow        1   i    t
ctin AUFTHL11   2  from HL1         1   i

ctin AUFTHL12   1  from AUFTHL11    1   i  t
ctin AUFTHL12   2  from Snow        1   i  t
ctin AUFTHL12   3  from AUFT        1   i


ctin Soil1  1  from  AUFTHL12 1     i     t 
ctin Soil1  2  from  SW       1     i     t-1
ctin Soil1  3  from  FC       1     i
ctin Soil1  4  from  BE       1     i

ctin Soil2  1  from  Soil1    1     i     t 
ctin Soil2  2  from  AUFTHL12 1     i     t
ctin Soil2  3  from  SW       1     i     t-1

ctin Soil3  1  from  Soil2    1     i     t
ctin Soil3  2  from  FC       1     i

ctin Soil4  1  from  Soil3    1     i     t
ctin Soil4  2  from  Soil1    1     i     t
ctin Soil4  3  from  Soil2    1     i     t

 
ctin ETP   1   from  TT       1     i     t
ctin ETP   2   from  TM       1     i     t
ctin ETP   3   from  ETPM     1     i     t
ctin ETP   4   from  CEF      1     i

//ctin ETR   1  from ETP    1     i     t
//ctin ETR   2  from Soil4  1     i     t
//ctin ETR   3  from PWP    1     i

ctin ETR1  1   from Soil4     1     i     t
ctin ETR1  2   from PWP       1     i

ctin ETR2  1   from ETR1      1     i     t
ctin ETR2  2   from ETP       1     i     t
ctin ETR2  3   from Soil4     1     i     t

ctin ETR3  1   from ETR2      1     i     t
ctin ETR3  2   from Soil4     1     i     t

ctin ETR4  1   from ETR3      1     i     t
ctin ETR4  2   from ETR2      1     i     t
ctin ETR4  3   from Soil4     1     i     t

ctin SW    1   from ETR4      2     i     t

//ctin R1    1   from R1        1     i     t-1
//ctin R1    2   from Soil4     2     i     t
//ctin R1    3   from K1        1     i
//ctin R1    4   from ALPHA     1     i 
//ctin R1    5   from PER1      1     i     
ctin   STW1  1  from  R15       1     i     t

ctin   R11   1  from  STW1      1     i     t-1
ctin   R11   2  from  Soil4     2     i     t

ctin   R12   1  from  R11       1     i     t
ctin   R12   2  from  K1        1     i
ctin   R12   3  from  ALPHA     1     i

ctin   R13   1  from  R11       1     i     t
ctin   R13   2  from  R12       1     i     t

ctin   R14   1  from  R13       1     i     t
ctin   R14   2  from  R12       1     i     t
ctin   R14   3  from  STW1      1     i     t-1
ctin   R14   4  from  Soil4     2     i     t

ctin   Q1    1  from  R14       2     i     t

ctin   R15   1  from  R14       1     i     t
ctin   R15   2  from  PER1      1     i


//ctin R2    1   from R2        1     i     t-1
//ctin R2    2   from R15       2     i     t
//ctin R2    3   from K2        1     i
//ctin R2    4   from PER2      1     i
ctin  STW2  1   from   R23      1     i     t

ctin  R21   1   from   STW2     1     i     t-1
ctin  R21   2   from   R15      2     i     t
ctin  R21   3   from   K2       1     i

ctin  Q2    1   from   R21      2     i     t

ctin  R22   1   from   R21      1     i     t
ctin  R22   2   from   Q2       1     i     t

ctin  R23   1   from   R22      1     i     t
ctin  R23   2   from   PER2     1     i

ctin  Q3    1   from R3         2     i     t
ctin  STW3  1   from R3         1     i     t
 
ctin  R3    1   from STW3       1     i     t-1
ctin  R3    2   from R23        2     i     t
ctin  R3    3   from K3         1     i

ctin  QTOT  1   from Q1         1     i     t
ctin  QTOT  2   from Q2         1     i     t
ctin  QTOT  3   from Q3         1     i     t
ctin  QTOT  4   from AUFTHL12   2     i     t

ctin  MAXBAS  1  from  QTOT     1     i     t
ctin  MAXBAS  2  from  MAXBAS   2     i     t-1
ctin  MAXBAS  3  from  MAXBAS   3     i     t-1
ctin  MAXBAS  4  from  MAXBAS   4     i     t-1




ctin QS      1  from  MAXBAS  1     i     t

//ORDER -----------------------------------------------ORDER
order modinspace Sm
      order YA1  
	//PEMOD
	Snow
	AUFTHL11
	AUFTHL12
	Soil1
	Soil2
	Soil3
	Soil4	 
	ETP 
	ETR1
	ETR2
	ETR3
	ETR4
	SW		
	R11
	R12
	R13
	R14
	Q1
	R15
	STW1		
	R21
	Q2
	R22
	R23
	STW2 
	R3
	Q3
	STW3 
	QTOT
	MAXBAS
	QS	
      forder
forder
//-----
order spaceintraj Tm
      Sm
forder

//USER FUNCTIONS (fonctions déclarées dans le .h)---------------------------------------UFCT
insert_fct     xdisplay
insert_fct arg init

//FIN ================================================== END
