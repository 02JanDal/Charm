#ifndef SQLSTORAGE_H
#define SQLSTORAGE_H

#include <QString>

#include "StorageInterface.h"

class QSqlDatabase;
class QSqlQuery;
class QSqlRecord;

class SqlStorage : public StorageInterface
{
public:
    SqlStorage();
    ~SqlStorage();

    void stateChanged( State previous );

    int makeEventId();

    virtual QSqlDatabase& database() = 0;

    // installation id handling
    Installation createInstallation( const QString& name );
    Installation getInstallation( int installationId );
    bool modifyInstallation( const Installation& );
    bool deleteInstallation( const Installation& );

    // implement user database functions:
    User getUser ( int userid );
    User makeUser( const QString& name );
    bool modifyUser ( const User& user );
    bool deleteUser ( const User& user );

    // implement task database functions:
    TaskList getAllTasks();
    bool addTask ( const Task& task );
    Task getTask( int taskid );
    bool modifyTask( const Task& task );
    bool deleteTask( const Task& task );

    // implement event database functions:
    EventList getAllEvents();
    Event makeEvent();
    Event getEvent( int eventid );
    bool modifyEvent( const Event& event );
    bool deleteEvent( const Event& event );

    // implement subscription management functions:
    bool addSubscription( User, Task );
    bool deleteSubscription( User, Task );

    // implement metadata management functions:
    bool setMetaData( const QString&,  const QString& );
    QString getMetaData( const QString& );

protected:
    bool verifyDatabase();
    bool createDatabase();

private:
    //  a debug helper that populates the database with canned values:
    void populateDatabase();

    // run the query and process possible errors
    bool runQuery( QSqlQuery& );

    Event makeEventFromRecord( const QSqlRecord& );
};

#endif