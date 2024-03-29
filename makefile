# TODO: MUDAR NOME DOS TESTES DE DOMINIO DE "DOMINIO" => "TESTEDOMINIO"


#MYSQL SERVER:
MYSQL_CONCPP_DIR = /usr/include/
CPPFLAGS = -I $(MYSQL_CONCPP_DIR)/include -L $(MYSQL_CONCPP_DIR)/lib64

CC = g++
LIBS = -lmysqlcppconn8 -Wall -g -lgtest_main -lgtest -lpthread -pthread
Usuario = teste_usuario testes/teste_usuario.cpp
Partida = teste_partida testes/teste_partida.cpp
Cartao =  teste_cartao testes/teste_cartao.cpp
Ingresso = teste_ingresso testes/teste_ingresso.cpp
Jogo = teste_jogo testes/teste_jogo.cpp
Main = main main.cpp
Menu = modulos/apresentacao/menu.cpp
UsuarioRepository = modulos/servicos/usuarioService.cpp
AutenticacaoRepository = modulos/servicos/autenticacaoService.cpp
Singleton = modulos/servicos/singleton.cpp


main:
	$(CC) -c $(Menu)
	$(CC) -c $(Singleton)
	$(CC) -c $(UsuarioRepository)
	$(CC) -c $(AutenticacaoRepository)
	$(CC) -o $(Main) $(LIBS) menu.o usuarioService.o autenticacaoService.o singleton.o
	./main
testeUsuario:
	${CC} -o  $(Usuario) ${LIBS}
	./teste_usuario

testePartida:
	${CC} -o $(Partida) ${LIBS}
	./teste_partida

testeCartao:
	${CC} -o $(Cartao) ${LIBS}
	./teste_cartao

testeIngresso:
	$(CC) -o $(Ingresso) $(LIBS)
	./teste_ingresso

testeJogo:
	$(CC) -o $(Jogo) $(LIBS)
	./teste_jogo

clean:
	rm teste_ingresso teste_usuario teste_partida teste_jogo teste_cartao main menu
	clear
