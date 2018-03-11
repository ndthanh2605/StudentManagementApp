#include "student.h"

Student::Student()
{

}

void Student::readJson(const QJsonObject &obj)
{
    m_id = obj["_id"].toString();
    m_surMiddleName = obj["sur_middle_name"].toString();
    m_firstName = obj["first_name"].toString();
    m_fullName = obj["full_name"].toString();
    m_className = obj["class"].toString();
    m_school = obj["school"].toString();
    m_phone = obj["phone"].toString();
    m_referral = obj["referral"].toString();
    m_parentName = obj["parent_name"].toString();
    m_startDate = QDate::fromString(obj["start_date"].toString(), "yyyy-MM-dd");
    m_totalMoney = obj["total_money"].toString().toLongLong();
    m_note = obj["note"].toString();
    m_filterData = obj["filter_data"].toString();
}

void Student::writeJson(QJsonObject &obj)
{
    obj["_id"] = m_id;
    obj["sur_middle_name"] = m_surMiddleName;
    obj["first_name"] = m_firstName;
    obj["full_name"] = m_fullName;
    obj["class"] = m_className;
    obj["school"] = m_school;
    obj["phone"] = m_phone;
    obj["referral"] = m_referral;
    obj["parent_name"] = m_parentName;
    obj["start_date"] = m_startDate.toString("yyyy-MM-dd");
    obj["total_money"] = QString::number(m_totalMoney);
    obj["note"] = m_note;
    obj["filter_data"] = m_filterData;
}

QString Student::surMiddleName() const
{
    return m_surMiddleName;
}

void Student::setSurMiddleName(const QString &surMiddleName)
{
    m_surMiddleName = surMiddleName;
}

QString Student::firstName() const
{
    return m_firstName;
}

void Student::setFirstName(const QString &firstName)
{
    m_firstName = firstName;
}

QString Student::fullName() const
{
    return m_fullName;
}

void Student::setFullName(const QString &fullName)
{
    m_fullName = fullName;
}

QString Student::school() const
{
    return m_school;
}

void Student::setSchool(const QString &school)
{
    m_school = school;
}

QString Student::phone() const
{
    return m_phone;
}

void Student::setPhone(const QString &phone)
{
    m_phone = phone;
}

QString Student::referral() const
{
    return m_referral;
}

void Student::setReferral(const QString &referral)
{
    m_referral = referral;
}

QString Student::parentName() const
{
    return m_parentName;
}

void Student::setParentName(const QString &parentName)
{
    m_parentName = parentName;
}

QDate Student::startDate() const
{
    return m_startDate;
}

void Student::setStartDate(const QDate &startDate)
{
    m_startDate = startDate;
}

long long Student::totalMoney() const
{
    return m_totalMoney;
}

void Student::setTotalMoney(long long totalMoney)
{
    m_totalMoney = totalMoney;
}

QString Student::note() const
{
    return m_note;
}

void Student::setNote(const QString &note)
{
    m_note = note;
}

QString Student::filterData() const
{
    return m_filterData;
}

void Student::setFilterData(const QString &filterData)
{
    m_filterData = filterData;
}

QString Student::className() const
{
    return m_className;
}

void Student::setClassName(const QString &className)
{
    m_className = className;
}

QString Student::id() const
{
    return m_id;
}

void Student::setId(const QString &id)
{
    m_id = id;
}
