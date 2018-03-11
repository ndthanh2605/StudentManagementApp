#ifndef SESSION_H
#define SESSION_H

#include <QDate>
#include "jsonentity.h"

class Session : public JsonEntity
{
public:
    Session();

    virtual void readJson(const QJsonObject &obj);
    virtual void writeJson(QJsonObject &obj);

public:
    QString id() const;
    void setId(const QString &id);

    QString className() const;
    void setClassName(const QString &className);

    QDate startDate() const;
    void setStartDate(const QDate &startDate);

    QDate endDate() const;
    void setEndDate(const QDate &endDate);

    QStringList students() const;
    void setStudents(const QStringList &students);

    QString filterData() const;
    void setFilterData(const QString &filterData);

    long fee() const;
    void setFee(long fee);

    long startTime() const;
    void setStartTime(long startTime);

private:
    QString m_id;
    QString m_className;
    QDate   m_startDate;
    QDate   m_endDate;
    long    m_startTime;
    long    m_fee;
    QStringList m_students;
    QString m_filterData;

};

#endif // SESSION_H
