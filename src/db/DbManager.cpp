#include "src/db/DbManager.h"

DbManager::DbManager()
{

}

DbManager &DbManager::getInstance()
{
    static DbManager instance;
    return instance;
}
