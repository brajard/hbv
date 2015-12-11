#==========================================================
#            fichier de D'INSTRUCTIONS HBV.i
#nb PAS DE TAB, un retour chariot en fin de fichier
#==========================================================
echo on

#==========================================================
# 1) INITIALISATION DU MODELE

setstate ALPHA    1.485  
setstate BE       2.16  
setstate CEF      0.121  
setstate FC      157.347 
setstate K1       9.419e-10  
setstate K2       7.244e-03  
setstate K3       4.519e-08  
setstate PER1     2.871e-02  
setstate PER2     1.422e-03  
setstate PWP      15.735  
setstate AUFT     0.344  
setstate HL1      2.005  
setstate degd     0.083  
setstate TC      -0.301  

 

loadstate PE 1 i 0 A 1   /usr/home/nylod/Desktop/HBV/peHoraireCalage5ans D
loadstate TT 1 i 0 A 1    /usr/home/nylod/Desktop/HBV/ttHoraireCalage5ans D
loadstate TM 1 i 0 A 1    /usr/home/nylod/Desktop/HBV/tmHoraireCalage5ans D
loadstate ETPM 1 i 0 A 1  /usr/home/nylod/Desktop/HBV/etpmHoraireCalage5ans D

init  54.4026  14.3084  40.7731  0.896  0.0873  0.0468  15.0221  15.0221

#init  54.4026  14.3084  40.7731  0.8960   0.0873  0.0468  0.0468  105.3607   105.3607
#init  1.6769  4.6452  39.9643  6.7650e-04  0.0283  0.0458  92.6844  92.6844

#init  29.7267  35.2529  32.8  0.2555  0.2303  0.0364  117.507  117.507
#init  35.107  35.2529  32.8  0.2555  0.2303  0.0364  117.4953 117.4953
#init 7.42 0.219 32.8 0.13217 0.0234 0  114   114  # STW1 STW2 STW3 Q1 Q2 Q3 HW SW  
#init 13.14524401427151 2.26e-6 5.03e-7 5.78e-6 4.79e-6 9.00e-4  7.40531082e+01   7.40531082e+01  # STW1 STW2 STW3 Q1 Q2 Q3 HW SW 
#init -2.92344165e+00 1.62706490e+01 -1.33228865e+01 0.132249214217718 0.0234 0  2.13516769e+02   2.13516769e+02  # STW1 STW2 STW3 Q1 Q2 Q3 HW SW  

set_modeltime   0

FORWARD

savestate QS    1 i  1% A 0  /usr/home/nylod/Desktop/HBV/SAVE_YAO/qtot.dat	
load_inst /usr/home/nylod/Desktop/HBV/script/save.i

#loadobs   QS 1 i 0 A 1  /usr/home/nylod/Desktop/HBV/debitHoraireCalage5ans D
#loadobs   SW 1 i 0 A 1 ./donnesArdeche/data/sw D
#outoobs QTOT 1 800


##load_inst /usr/home/nylod/Desktop/HBV/script/sensiblite.i


#preparation de l'assimilation 
##cost lms 0.5

#instruction liées à m1qn3

#print_cost ON
##setm_impres   5
##setm_io       6
##setm_mode     1
##set_nbiter  200
##setm_nsim   200
##setm_dxmin    1.0e-20
##setm_epsg     1.0e-20
##setm_ddf1     100

#load_inst ./script/borne_Inf_Sup.i
#load_inst /usr/home/nylod/Desktop/HBV/script/borne_Inf_Sup.i
#load_inst ./script/bornes.i

setstate ALPHA    1.485  
setstate BE       2.16  
setstate CEF      0.121  
setstate FC      157.347 
setstate K1       9.419e-10  
setstate K2       7.244e-03  
setstate K3       4.519e-08  
setstate PER1     2.871e-02  
setstate PER2     1.422e-03  
setstate PWP      15.735  
setstate AUFT     0.344  
setstate HL1      2.005  
setstate degd     0.083  
setstate TC      -0.301   
 
  
 # 
init  54.4026  14.3084  40.7731  0.896  0.0873  0.0468  15.0221  15.0221


xdisplay
run									
xdisplay





# ====> sauvegarde de la trajectoire calculée (pour voir)




