// test_authentication.cpp
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "authentication.h"
#include "mock_database.h"

using ::testing::Return;

// Prueba para el inicio de sesión exitoso
TEST(AuthenticationTest, LoginSuccess) {
    MockDatabase db;
    Authentication auth(&db);

    EXPECT_CALL(db, userExists("Alice"))
        .WillOnce(Return(true));
    EXPECT_CALL(db, getPassword("Alice"))
        .WillOnce(Return("password"));

    EXPECT_TRUE(auth.login("Alice", "password"));
}

// Prueba para el inicio de sesión fallido
TEST(AuthenticationTest, LoginFailure) {
    MockDatabase db;
    Authentication auth(&db);

    EXPECT_CALL(db, userExists("Alice"))
        .WillOnce(Return(true));
    EXPECT_CALL(db, getPassword("Alice"))
        .WillOnce(Return("password"));

    EXPECT_FALSE(auth.login("Alice", "wrongpassword"));
    EXPECT_CALL(db, userExists("Bob"))
        .WillOnce(Return(false));
    EXPECT_FALSE(auth.login("Bob", "password"));
}

// Prueba para el registro de un nuevo usuario
TEST(AuthenticationTest, RegisterUser) {
    MockDatabase db;
    Authentication auth(&db);

    EXPECT_CALL(db, userExists("Charlie"))
        .WillOnce(Return(false));
    EXPECT_CALL(db, addUser("Charlie", "password"))
        .Times(1);

    auth.registerUser("Charlie", "password");
}

// Función principal para ejecutar los tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
