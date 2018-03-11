#ifndef SESSIONMODEL_H
#define SESSIONMODEL_H

#include <QObject>
#include "Entity/session.h"

class SessionModel : public QObject
{
    Q_OBJECT
public:
    explicit SessionModel(QObject *parent = nullptr);

    void clearData();

    Session *getSession(const QString &id);

    QList<Session *> getListSessions() const;
    void setListSessions(const QList<Session *> &sessions);

signals:

public slots:

private:
    QHash<QString, Session *> m_sessions;

};

#endif // SESSIONMODEL_H
