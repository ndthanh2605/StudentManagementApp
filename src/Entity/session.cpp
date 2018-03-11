#include "session.h"
#include <QJsonArray>

Session::Session()
{

}

void Session::readJson(const QJsonObject &obj)
{
    m_id = obj["_id"].toString();
    m_className = obj["class_name"].toString();
    m_startDate = QDate::fromString(obj["start_date"].toString(), "yyyy-MM-dd");
    m_endDate = QDate::fromString(obj["end_date"].toString(), "yyyy-MM-dd");
    m_startTime = obj["start_time"].toString().toLong();
    m_fee = obj["fee"].toString().toLong();
//    m_students = obj["students"].toString().split(";");
    m_students.clear();
    QJsonArray arr = obj["students"].toArray();
    for (int i = 0; i < arr.size(); ++i) {
        m_students.append(arr.at(i).toString());
    }
    m_filterData = obj["filter_data"].toString();
}

void Session::writeJson(QJsonObject &obj)
{
    obj["_id"] = m_id;
    obj["class_name"] = m_className;
    obj["start_date"] = m_startDate.toString("yyyy-MM-dd");
    obj["end_date"] = m_endDate.toString("yyyy-MM-dd");
    obj["start_time"] = QString::number(m_startTime);
    obj["fee"] = QString::number(m_fee);
//    obj["students"] = m_students.join(";");
    QJsonArray arr;
    foreach (QString stId, m_students) {
        arr.append(stId);
    }
    obj["students"] = arr;
    obj["filter_data"] = m_filterData;
}

QString Session::id() const
{
    return m_id;
}

void Session::setId(const QString &id)
{
    m_id = id;
}

QString Session::className() const
{
    return m_className;
}

void Session::setClassName(const QString &className)
{
    m_className = className;
}

QDate Session::startDate() const
{
    return m_startDate;
}

void Session::setStartDate(const QDate &startDate)
{
    m_startDate = startDate;
}

QDate Session::endDate() const
{
    return m_endDate;
}

void Session::setEndDate(const QDate &endDate)
{
    m_endDate = endDate;
}

QStringList Session::students() const
{
    return m_students;
}

void Session::setStudents(const QStringList &students)
{
    m_students = students;
}

QString Session::filterData() const
{
    return m_filterData;
}

void Session::setFilterData(const QString &filterData)
{
    m_filterData = filterData;
}

long Session::fee() const
{
    return m_fee;
}

void Session::setFee(long fee)
{
    m_fee = fee;
}

long Session::startTime() const
{
    return m_startTime;
}

void Session::setStartTime(long startTime)
{
    m_startTime = startTime;
}
