#ifndef DB_DBMANAGER_H
#define DB_DBMANAGER_H

class DbManager
{
public:
    static DbManager& getInstance();

private:
    DbManager();
};

#endif
