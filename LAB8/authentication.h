// authentication.h
#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <string>
#include "database.h"

class Authentication {
public:
    Authentication(Database* db) : db_(db) {}

    bool login(const std::string& username, const std::string& password) {
        if (db_->userExists(username)) {
            return db_->getPassword(username) == password;
        }
        return false;
    }

    void registerUser(const std::string& username, const std::string& password) {
        if (!db_->userExists(username)) {
            db_->addUser(username, password);
        }
    }

private:
    Database* db_;
};

#endif // AUTHENTICATION_H
