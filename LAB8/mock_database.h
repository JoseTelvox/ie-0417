// mock_database.h
#ifndef MOCK_DATABASE_H
#define MOCK_DATABASE_H

#include <gmock/gmock.h>
#include "database.h"

class MockDatabase : public Database {
public:
    MOCK_METHOD(bool, userExists, (const std::string& username), (override));
    MOCK_METHOD(std::string, getPassword, (const std::string& username), (override));
    MOCK_METHOD(void, addUser, (const std::string& username, const std::string& password), (override));
};

#endif // MOCK_DATABASE_H
