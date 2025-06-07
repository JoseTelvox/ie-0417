// database.h
#ifndef DATABASE_H
#define DATABASE_H

#include <string>

class Database {
public:
    virtual ~Database() = default;
    virtual bool userExists(const std::string& username) = 0;
    virtual std::string getPassword(const std::string& username) = 0;
    virtual void addUser(const std::string& username, const std::string& password) = 0;
};

#endif // DATABASE_H
