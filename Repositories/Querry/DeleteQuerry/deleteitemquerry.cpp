#include "deleteitemquerry.h"

DeleteItemQuerry::DeleteItemQuerry()
{
    nameTable = "item";
}

bool DeleteItemQuerry::Delete(int id)
{
    return DeleteQuerry::Delete(id,nameTable);
}
