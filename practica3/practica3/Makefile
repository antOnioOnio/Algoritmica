SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c -std=c++11


all: $(BIN)/cifras	$(BIN)/sumaV	$(BIN)/sumaD	

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

# ************ Compilación de módulos ************
$(BIN)/cifras: $(OBJ)/cifras.o
	$(CXX) -o $(BIN)/cifras  $(OBJ)/cifras.o

$(OBJ)/cifras.o: $(SRC)/cifras.cpp  
	$(CXX) $(CPPFLAGS) $(SRC)/cifras.cpp -o $(OBJ)/cifras.o

$(BIN)/sumaV: $(OBJ)/sumaV.o
	$(CXX) -o $(BIN)/sumaV $(OBJ)/sumaV.o

$(OBJ)/sumaV.o: $(SRC)/sumaV.cpp  
	$(CXX) $(CPPFLAGS) $(SRC)/sumaV.cpp -o $(OBJ)/sumaV.o

$(BIN)/sumaD: $(OBJ)/sumaD.o
	$(CXX) -o $(BIN)/sumaD $(OBJ)/sumaD.o

$(OBJ)/sumaD.o: $(SRC)/sumaD.cpp  
	$(CXX) $(CPPFLAGS) $(SRC)/sumaD.cpp -o $(OBJ)/sumaD.o


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
