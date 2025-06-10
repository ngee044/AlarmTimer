#include "TimeConfiguration.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

namespace MainCore
{
    TimeConfiguration::TimeConfiguration()
    {
		
    }

    TimeConfiguration::TimeConfiguration(const QString& config_path)
		: config_path_(config_path),
		version_("1.0"),
		name_("AlarmApp"),
		target_time_("00 : 00 : 00")
	{
		load(config_path);
	}

	TimeConfiguration::~TimeConfiguration()
	{
	}

    bool TimeConfiguration::load(const QString& config_path)
    {
		config_path_ = config_path;
		QFile file(config_path_);
		if (!file.open(QIODevice::ReadOnly)) 
		{
			qDebug() << "Could not open configuration file for reading:" << config_path_;
			return false;
		}

		auto doc = QJsonDocument::fromJson(file.readAll());
		if (doc.isNull() || !doc.isObject())
		{
			qDebug() << "Invalid JSON format in configuration file:" << config_path_;
			return false;
		}

		const QJsonObject json_obj = doc.object();
		target_time_ = json_obj.value("target_time").toString();
		version_ = json_obj.value("version").toString();
		name_ = json_obj.value("name").toString();

		return true;
    }

    bool TimeConfiguration::save()
    {
		QJsonObject json_obj;
		json_obj["target_time"] = target_time_;
		json_obj["version"] = version_;
		json_obj["name"] = name_;

		QFile file(config_path_);
		if (!file.open(QIODevice::WriteOnly))
		{
			qDebug() << "Could not open configuration file for writing:" << config_path_;
			return false;
		}

		QJsonDocument doc(json_obj);
		if (file.write(doc.toJson(QJsonDocument::Indented)) == -1)
		{
			qDebug() << "Failed to write to configuration file:" << config_path_;
			return false;
		}

		file.close();
		return true;		
    }
}