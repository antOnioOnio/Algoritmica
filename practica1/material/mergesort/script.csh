#!/bin/csh
@ inicio = 100
@ fin = 100000
@ incremento = 100
@ i = $inicio
echo > tiempos.dat
while ( $i <= $fin )
echo Ejecución tam = $i
echo `./merge $i` >> tiempos.dat 
@ i += $incremento
end

