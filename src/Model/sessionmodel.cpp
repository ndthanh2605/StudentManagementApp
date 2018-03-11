#include "sessionmodel.h"
#include <QDebug>

SessionModel::SessionModel(QObject *parent) : QObject(parent)
{

}

void SessionModel::clearData()
{
    qDeleteAll(m_sessions);
    m_sessions.clear();
}

Session *SessionModel::getSession(const QString &id)
{
    return m_sessions.value(id);
}

QList<Session *> SessionModel::getListSessions() const
{
    return m_sessions.values();
}

void SessionModel::setListSessions(const QList<Session *> &sessions)
{
    clearData();
    for (int i = 0; i < sessions.size(); ++i) {
        qDebug() << "add session" << sessions.at(i)->id();
        m_sessions.insert(sessions.at(i)->id(), sessions.at(i));
    }
}
