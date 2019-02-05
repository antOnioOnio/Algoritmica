SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all:  $(BIN)/prueba_APermutacion $(BIN)/njob_nworker

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
$(BIN)/njob_nworker: $(OBJ)/njob_nworker.o  $(OBJ)/Apermutacion.o
	$(CXX) -o $(BIN)/njob_nworker $(OBJ)/njob_nworker.o $(OBJ)/Apermutacion.o


$(OBJ)/njob_nworker.o: $(SRC)/njob_nworker.cpp $(INC)/Apermutacion.h
	$(CXX) $(CPPFLAGS) $(SRC)/njob_nworker.cpp -o $(OBJ)/njob_nworker.o	

	
$(BIN)/prueba_APermutacion: $(OBJ)/Apermutacion.o $(OBJ)/prueba_APermutacion.o
	$(CXX) -o $(BIN)/prueba_Apermutacion  $(OBJ)/prueba_APermutacion.o $(OBJ)/Apermutacion.o

$(OBJ)/prueba_APermutacion.o: $(SRC)/prueba_APermutacion.cpp $(INC)/Apermutacion.h
	$(CXX) $(CPPFLAGS) $(SRC)/prueba_APermutacion.cpp -o $(OBJ)/prueba_APermutacion.o	
$(OBJ)/Apermutacion.o: $(SRC)/Apermutacion.cpp $(INC)/Apermutacion.h
	$(CXX) $(CPPFLAGS) $(SRC)/Apermutacion.cpp -o $(OBJ)/Apermutacion.o

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
