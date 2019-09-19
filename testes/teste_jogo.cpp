#include "../jogo.cpp"
#include <gtest/gtest.h>

// compile: g++ -Wall -g -pthread -o teste_jogo teste_jogo.cpp -lgtest_main -lgtest -lpthread

int main(int argc, char **argv)
{

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(CadastroJogo, CadastroValido)
{
    Jogo jogo("123", "Flamengo x Vasco", "Rio de Janeiro", "RJ", 1);
    // Teste para o código:
    ASSERT_EQ("123", jogo.getCodigo());
    ASSERT_EQ(true, jogo.codigoValido(jogo.getCodigo()));

    // Teste para o nome do jogo:
    ASSERT_EQ("Flamengo x Vasco", jogo.getNome());
    ASSERT_EQ(true, jogo.nomeECidadeValido(jogo.getNome()));

    // Teste para o nome da cidade:
    ASSERT_EQ("Rio de Janeiro", jogo.getCidade());
    ASSERT_EQ(true, jogo.nomeECidadeValido(jogo.getCidade()));

    // Teste para o estado:
    ASSERT_EQ("RJ", jogo.getEstado());
    ASSERT_EQ(true, jogo.estadoValido(jogo.getEstado()));

    // Teste para tipo:
    ASSERT_EQ(1, jogo.getTipo());
    ASSERT_EQ(true, jogo.tipoValido(jogo.getTipo()));
    ASSERT_EQ("LOCAL", jogo.getTipoDoJogo());
}

TEST(Exception, CodigoInvalido)
{
    EXPECT_THROW({
        try
        {
            Jogo jogo("A14", "Flamengo x Vasco", "Rio de Janeiro", "RJ", 1); // Letras não sao permitidas
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Código de jogo inválido, certifique-se que seja um número XXX onde X está entre 0-9", e.what());
            throw;
        }
    },
                 invalid_argument);
    EXPECT_THROW({
        try
        {
            Jogo jogo("1114", "Flamengo x Vasco", "Rio de Janeiro", "RJ", 1); // Tamanho != 3
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Código de jogo inválido, certifique-se que seja um número XXX onde X está entre 0-9", e.what());
            throw;
        }
    },
                 invalid_argument);
}
TEST(Exception, NomeInvalido)
{
    EXPECT_THROW({
        try
        {
            Jogo jogo("114", "Flamengo  x Vasco", "Rio de Janeiro", "RJ", 1); // 2 espaços seguidos
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Nome de jogo inválido, certifique-se de que não há espaços múltiplos, caractéres especiais ou números.", e.what());
            throw;
        }
    },
                 invalid_argument);
    EXPECT_THROW({
        try
        {
            Jogo jogo("114", "Flamengo - Vasco", "Rio de Janeiro", "RJ", 1); // Caractér especial
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Nome de jogo inválido, certifique-se de que não há espaços múltiplos, caractéres especiais ou números.", e.what());
            throw;
        }
    },
                 invalid_argument);
    EXPECT_THROW({
        try
        {
            Jogo jogo("114", "Flamengo +*", "Rio de Janeiro", "RJ", 1); // Caractér especial
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Nome de jogo inválido, certifique-se de que não há espaços múltiplos, caractéres especiais ou números.", e.what());
            throw;
        }
    },
                 invalid_argument);
}

TEST(Exception, CidadeInvalida)
{
    EXPECT_THROW({
        try
        {
            Jogo jogo("114", "Flamengo x Vasco", "Rio  de Janeiro", "RJ", 1); // 2 espaços seguidos
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Cidade inválida, certifique-se de que não há espaços múltiplos, caractéres especiais ou números.", e.what());
            throw;
        }
    },
                 invalid_argument);
    EXPECT_THROW({
        try
        {
            Jogo jogo("114", "Flamengo x Vasco", "Rio () de Janeiro", "RJ", 1); // Caractér especial
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Cidade inválida, certifique-se de que não há espaços múltiplos, caractéres especiais ou números.", e.what());
            throw;
        }
    },
                 invalid_argument);
    EXPECT_THROW({
        try
        {
            Jogo jogo("114", "Flamengo x Vasco", "Rio de /Janeiro", "RJ", 1); // Caractér especial
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Cidade inválida, certifique-se de que não há espaços múltiplos, caractéres especiais ou números.", e.what());
            throw;
        }
    },
                 invalid_argument);
}
TEST(Exception, EstadoInvalido)
{
    EXPECT_THROW({
        try
        {
            Jogo jogo("114", "Flamengo x Vasco", "Rio de Janeiro", "AO", 1); // Estado != das da lista.
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Estado Inválido", e.what());
            throw;
        }
    },
                 invalid_argument);
    EXPECT_THROW({
        try
        {
            Jogo jogo("114", "Flamengo x Vasco", "Rio de Janeiro", "1O", 1); // Estado != das da lista.
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Estado Inválido", e.what());
            throw;
        }
    },
                 invalid_argument);
    EXPECT_THROW({
        try
        {
            Jogo jogo("114", "Flamengo x Vasco", "Rio de Janeiro", "RI", 1); // Estado != das da lista.
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Estado Inválido", e.what());
            throw;
        }
    },
                 invalid_argument);
}

TEST(Exception, TipoInvalido)
{
    EXPECT_THROW({
        try
        {
            Jogo jogo("114", "Flamengo x Vasco", "Rio de Janeiro", "RJ", 0); // tipo < 1.
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Tipo inválido de jogo.", e.what());
            throw;
        }
    },
                 invalid_argument);
    EXPECT_THROW({
        try
        {
            Jogo jogo("114", "Flamengo x Vasco", "Rio de Janeiro", "RJ", 5); // tipo > 5.
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Tipo inválido de jogo.", e.what());
            throw;
        }
    },
                 invalid_argument);
}
