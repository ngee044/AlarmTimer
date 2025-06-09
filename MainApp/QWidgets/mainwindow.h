#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QLabel>
#include <QMediaPlayer>   // 추가
#include <QUrl>
#include <QDir>

#include "TargetTimeDialog.h"

#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }  
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

	void initialize();
	void connected();

public slots:
	void slot_start_timer();
	void slot_start();
	void slot_stop_reset();
	void slot_lap();
	void slot_set_timer();

protected:
	void update_display();
	void check_stopwatch();

private:
	Ui::MainWindow *ui;

	bool started_;
	
	QTimer* qtimer_;
	QString current_time_;
	QString target_time_;

	int elapsed_seconds_;
	int lap_count_;
	std::vector<QLabel*> lap_labels_;
	TargetTimeDialog* target_time_dialog_;
	QString alarm_sound_path_;

	QMediaPlayer* media_player_;
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
	QAudioOutput  *audio_out_;
#endif
	bool sound_played_;
};

#endif
