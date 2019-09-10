#include "cartao.cpp"
#include <gtest/gtest.h>

// compile: g++ -Wall -g -pthread -o teste_usuario teste_usuario.cpp -lgtest_main -lgtest -lpthread

int main(int argc, char **argv)
{

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(CadastroCartao, TesteNumeroCartaoLuhn)
{
    Cartao cartao("6637410737643907", "333", "10/22"); // Numero valido para algoritmo de luhn
    ASSERT_EQ(true, cartao.numeroValido("6637410737643907"));
    ASSERT_EQ("6637410737643907", cartao.getNumero());

    Cartao cartao2("3223876379348459", "123", "10/22");
    ASSERT_EQ(true, cartao2.codigoValido(cartao2.getCodigo()));
}

TEST(CadastroCartao, TesteCodigoCartao)
{
    Cartao cartao("3223876379348459", "012", "10/22");
    ASSERT_EQ(true, cartao.codigoValido(cartao.getCodigo()));

    Cartao cartao2("3223876379348459", "999", "10/22");
    ASSERT_EQ(true, cartao2.codigoValido(cartao2.getCodigo()));

    Cartao cartao3("3223876379348459", "421", "10/22");
    ASSERT_EQ(true, cartao3.codigoValido(cartao3.getCodigo()));
}

TEST(CadastroCartao, TesteValidadeCartao)
{
    Cartao cartao("3223876379348459", "012", "09/01");
    ASSERT_EQ(true, cartao.dataValida(cartao.getData()));

    Cartao cartao2("3223876379348459", "999", "10/10");
    ASSERT_EQ(true, cartao2.dataValida(cartao2.getData()));

    Cartao cartao3("3223876379348459", "421", "11/22");
    ASSERT_EQ(true, cartao3.dataValida(cartao3.getData()));
}

TEST(Exception, ExcecaoNumeroCartao)
{

    EXPECT_THROW(
        {
            try
            {
                Cartao cartao("06374107376439", "333", "10/22"); // Numero invalido: != de 16 caracteres
            }
            catch (invalid_argument e)
            {
                EXPECT_STREQ("Número de cartão de crédito inválido. Formato XXXXXXXXXXXXXXXX onde X é dígito (0 – 9). Número inválido segundo o algoritmo de Luhn", e.what());
                throw;
            }
        },
        invalid_argument);

    EXPECT_THROW(
        {
            try
            {
                Cartao cartao("1242121212111121", "333", "10/22"); // Numero invalido: algoritmo de luhn
            }
            catch (invalid_argument e)
            {
                EXPECT_STREQ("Número de cartão de crédito inválido. Formato XXXXXXXXXXXXXXXX onde X é dígito (0 – 9). Número inválido segundo o algoritmo de Luhn", e.what());
                throw;
            }
        },
        invalid_argument);
    EXPECT_THROW(
        {
            try
            {
                Cartao cartao("1242a21212111121", "333", "10/22"); // Numero invalido: possui letras
            }
            catch (invalid_argument e)
            {
                EXPECT_STREQ("Número de cartão de crédito inválido. Formato XXXXXXXXXXXXXXXX onde X é dígito (0 – 9). Número inválido segundo o algoritmo de Luhn", e.what());
                throw;
            }
        },
        invalid_argument);
}

TEST(Exception, ExcecaoCodigoCartao)
{

    EXPECT_THROW(
        {
            try
            {
                Cartao cartao("3223876379348459", "1214", "10/22"); // Codigo invalido: != de 3 caracteres
            }
            catch (invalid_argument e)
            {
                EXPECT_STREQ("Certifique-se de que seja um código de segurança válido (Formato XXX onde X é dígito (0 a 9)).", e.what());
                throw;
            }
        },
        invalid_argument);
    EXPECT_THROW(
        {
            try
            {
                Cartao cartao("3223876379348459", "A14", "10/22"); // Codigo invalido: Letras
            }
            catch (invalid_argument e)
            {
                EXPECT_STREQ("Certifique-se de que seja um código de segurança válido (Formato XXX onde X é dígito (0 a 9)).", e.what());
                throw;
            }
        },
        invalid_argument);
}

TEST(Exception, ExcecaoValidadeCartao)
{

    EXPECT_THROW(
        {
            try
            {
                Cartao cartao("3223876379348459", "121", "15/22"); // Data invalida: mes > 12 || < 1
            }
            catch (invalid_argument e)
            {
                EXPECT_STREQ("Formato inválido, certifique-se que a data se encontra no seguinte formato: MM/AA", e.what());
                throw;
            }
        },
        invalid_argument);

    EXPECT_THROW(
        {
            try
            {
                Cartao cartao("3223876379348459", "121", "15/200"); // Data invalida: ano diferente de AA
            }
            catch (invalid_argument e)
            {
                EXPECT_STREQ("Formato inválido, certifique-se que a data se encontra no seguinte formato: MM/AA", e.what());
                throw;
            }
        },
        invalid_argument);
    EXPECT_THROW(
        {
            try
            {
                Cartao cartao("3223876379348459", "121", "15 22"); // Data invalida: formatação
            }
            catch (invalid_argument e)
            {
                EXPECT_STREQ("Formato inválido, certifique-se que a data se encontra no seguinte formato: MM/AA", e.what());
                throw;
            }
        },
        invalid_argument);
}