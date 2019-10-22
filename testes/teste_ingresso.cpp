#include "../modulos/dominios/ingresso.cpp"
#include <gtest/gtest.h>

// compile: g++ -Wall -g -pthread -o teste_ingresso teste_ingresso.cpp -lgtest_main -lgtest -lpthread

int main(int argc, char **argv)
{

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(CadastroIngresso, CodigoValido)
{
    Ingresso ingresso("01234");
    ASSERT_EQ("01234", ingresso.getCodigo());
    ASSERT_EQ(true, ingresso.codigoValido(ingresso.getCodigo()));

    Ingresso ingresso2("11229");
    ASSERT_EQ("11229", ingresso2.getCodigo());
    ASSERT_EQ(true, ingresso2.codigoValido(ingresso2.getCodigo()));
}

TEST(Exception, CodigoInvalidoLetras)

{
    EXPECT_THROW({
        try
        {
            Ingresso ingresso("A1234"); // Letras não sao permitidas
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Certifique-se de que seja um código válido (Formato XXXXX onde X é dígito (0 – 9)).", e.what());
            throw;
        }
    },
                 invalid_argument);
}

TEST(Exception, CodigoInvalidoTamanho)
{

    EXPECT_THROW({
        try
        {
            Ingresso ingresso("111234"); // Tamanho do codigo != 5
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Certifique-se de que seja um código válido (Formato XXXXX onde X é dígito (0 – 9)).", e.what());
            throw;
        }
    },
                 invalid_argument);

    EXPECT_THROW({
        try
        {
            Ingresso ingresso("1234"); // Tamanho do codigo != 5
        }
        catch (invalid_argument e)
        {
            EXPECT_STREQ("Certifique-se de que seja um código válido (Formato XXXXX onde X é dígito (0 – 9)).", e.what());
            throw;
        }
    },
                 invalid_argument);
}