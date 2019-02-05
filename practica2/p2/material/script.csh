#!/bin/csh
@ inicio = 1
@ fin = 10000
@ vmax = 30
@ incremento = 5

@ i = $inicio
echo > tiempos.dat
while ( $i <= $fin )
echo Ejecución tam = $i
echo `./pivote $i $vmax` >> tiempos.dat 
@ i += $incremento
end
