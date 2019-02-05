#!/bin/csh
@ inicio = 1
@ fin = 10
@ incremento = 1
@ i = $inicio
echo > tiempos.dat
while ( $i <= $fin )
echo Ejecución tam = $i
echo `./pruebapermutacion $i` >> tiempos.dat 
@ i += $incremento
end

