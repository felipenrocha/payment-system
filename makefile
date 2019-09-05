CC = g++
LIBS = -Wall -g -lgtest_main -lgtest -lpthread -pthread

testeUsuario:
	${CC} -o teste_usuario teste_usuario.cpp ${LIBS}
	./teste_usuario

teste_partida:
	${CC} -o teste_partida teste_partida.cpp ${LIBS}
	./teste_partida
