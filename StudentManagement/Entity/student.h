#ifndef STUDENT_H
#define STUDENT_H

#include <QDate>
#include "jsonentity.h"

class Student : public JsonEntity
{
public:
    Student();

    virtual void readJson(const QJsonObject &obj);
    virtual void writeJson(QJsonObject &obj);

public:
    QString surMiddleName() const;
    void setSurMiddleName(const QString &surMiddleName);

    QString firstName() const;
    void setFirstName(const QString &firstName);

    QString fullName() const;
    void setFullName(const QString &fullName);

    QString school() const;
    void setSchool(const QString &school);

    QString phone() const;
    void setPhone(const QString &phone);

    QString referral() const;
    void setReferral(const QString &referral);

    QString parentName() const;
    void setParentName(const QString &parentName);

    QDate startDate() const;
    void setStartDate(const QDate &startDate);

    long long totalMoney() const;
    void setTotalMoney(long long totalMoney);

    QString note() const;
    void setNote(const QString &note);

    QString filterData() const;
    void setFilterData(const QString &filterData);

    QString className() const;
    void setClassName(const QString &className);

    QString id() const;
    void setId(const QString &id);

private:
    QString m_id = "";
    QString m_surMiddleName;
    QString m_firstName;
    QString m_fullName;
    QString m_className;
    QString m_school;
    QString m_phone;
    QString m_referral;
    QString m_parentName;
    QDate   m_startDate;
    long long m_totalMoney;
    QString m_note;
    QString m_filterData;

};

#endif // STUDENT_H
