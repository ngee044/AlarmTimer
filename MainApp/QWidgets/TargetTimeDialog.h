#pragma once
#include <QDialog>
#include <QTime>

namespace Ui { class TargetTimeDialog; }


class TargetTimeDialog : public QDialog
{
	Q_OBJECT
public:
	explicit TargetTimeDialog(QWidget *parent = nullptr);
	~TargetTimeDialog();

	QString target_time() const { return target_time_; }

protected:
	void initialize();
	void connected();

private:
	Ui::TargetTimeDialog *ui;
	QString target_time_;
};
