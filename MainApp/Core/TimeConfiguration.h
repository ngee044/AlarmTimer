#pragma once

#include <QString>


namespace MainCore
{
	class TimeConfiguration
	{
	public:
		TimeConfiguration();
		TimeConfiguration(const QString& config_path);
		~TimeConfiguration();

		QString target_time() const { return target_time_; }
		void target_time(const QString& time) { target_time_ = time; }
		
		bool load(const QString& config_path);
		bool save();

	private:
		QString config_path_;

		QString target_time_;
		QString version_;
		QString name_;

	};
}