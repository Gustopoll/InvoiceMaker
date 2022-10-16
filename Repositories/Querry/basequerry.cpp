#include "basequerry.h"

BaseQuerry::BaseQuerry()
{

}

QString BaseQuerry::GetLastError()
{
    return lastError;
}

int BaseQuerry::GetLastStatusCode()
{
    return statusCode;
}

bool BaseQuerry::SetErrorMSG(QString msg)
{
    lastError = msg;
    statusCode = -1;
    if (lastError == " ")
        return true;
    return false;
}

bool BaseQuerry::SetErrorMSG(QSqlError e)
{
    lastError = e.text();
    if (e.type() == QSqlError::NoError)
    {
        statusCode = 0;
        return true;
    }
    statusCode = -1;
    return false;
}
