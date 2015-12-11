#setstate  TC 2
# fonction de cout!!
#testof 0.01 10.0 10.0 10 0
testof 0.01 10.0 10.0 10 1
#testdf 1 1 1 10 r 0.001 0.001
#testlt  0.1  10.0  10.0 10 
#testad 0.001

#setstate FC     160

#sampleof ALPHA   0 6 0.01           BE  2.93644428e+00  2.93644428e+00   0.01          ./sensibilite/ALPHA.dat
#sampleof BE     0 6 0.01            ALPHA  1.48498774e+00   1.48498774e+00    0.01            ./sensibilite/BE.dat
#sampleof CEF    0 0.5 0.001         ALPHA  1.48498774e+00   1.48498774e+00    0.01          ./sensibilite/CEF.dat
#sampleof FC     10 500 0.1          ALPHA  1.48498774e+00   1.48498774e+00    0.01     ./sensibilite/FC.dat
#sampleof K1     0 0.1 0.001         FC  1.573622e+02  1.573622e+02   0.1          ./sensibilite/K1.dat
#sampleof K2     0.00000001 10e-3   0.00001  FC  1.573622e+02  1.573622e+02   0.1          ./sensibilite/K2.dat

#sampleof K3     0 0.1 0.001             FC  1.573622e+02  1.573622e+02   0.1    ./sensibilite/K3.dat
#sampleof PER1   0 0.1 0.001            FC  1.573622e+02  1.573622e+02  0.1  ./sensibilite/PER1.dat
#sampleof PER2   0 0.1 0.001            FC  1.573622e+02  1.573622e+02   0.1    ./sensibilite/PER2.dat
#sampleof PWP    10 500 0.1                     FC  1.573622e+02  1.573622e+02   0.1    ./sensibilite/PWP.dat

#sampleof AUFT   0 100 1   FC  1.573622e+02  1.573622e+02   0.1    ./sensibilite/AUFT.dat
#sampleof HL1    0 100 1    FC  1.573622e+02  1.573622e+02   0.1    ./sensibilite/HL1.dat
#sampleof degd   0 0.417 0.01   FC  1.573622e+02  1.573622e+02   0.1    ./sensibilite/degd.dat
#sampleof TC    -1.5 2.5 0.01   FC  1.573622e+02  1.573622e+02   0.1    ./sensibilite/TC.dat

#init 0.9232 0.1398   0    0.000688   1.398e-5   0    25.4   	0   # STW1 STW2 STW3 Q1 Q2 Q3 HW SW  
