#ifndef TASK_H
#define TASK_H

#include <map>

#include <QList>
#include <QString>
#include <QtDebug>
#include <QMetaType>

typedef int TaskId;
Q_DECLARE_METATYPE( TaskId )

/** A task is a category under which events are filed.
    It has a unique identifier and a name. */
class Task {
public:
    Task();
    /** Convenience constructor. */
    Task( TaskId id, const QString& name, TaskId parent = 0, bool subscribed = false );

    bool isValid() const;

    bool operator == ( const Task& other ) const;

    TaskId id() const ;

    void setId( TaskId id );

    QString name() const;

    void setName( const QString& name );

    TaskId parent() const;

    void setParent( TaskId parent );

    bool subscribed() const;

    void setSubscribed( bool value );

    void dump() const;

private:
    int m_id;
    int m_parent;
    QString m_name;
    bool m_subscribed;
};

/** A task list is a list of tasks that belong together.
    Example: All tasks for one user. */
typedef QList<Task> TaskList;
typedef QList<TaskId> TaskIdList;
Q_DECLARE_METATYPE( TaskIdList )

void dumpTaskList( const TaskList& tasks );

#endif