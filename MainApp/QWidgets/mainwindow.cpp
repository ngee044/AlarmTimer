#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <TimeSave.h>

#include <QTime>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent),
	elapsed_seconds_(0),
	current_time_("00:00:00"),
	target_time_("00:00:00"),
	started_(false),
	lap_count_(0),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	initialize();
	connected();
}

MainWindow::~MainWindow()
{
	// TODO
	// Save time data if needed
	// TimeSave time_save; // Example usage, if needed

	delete ui;
}

void MainWindow::initialize()
{
	qtimer_ = new QTimer(this);

	lap_labels_.reserve(10); // Reserve space for 10 laps
	
	lap_labels_.push_back(ui->label_list0);
	lap_labels_.push_back(ui->label_list1);
	lap_labels_.push_back(ui->label_list2);
	lap_labels_.push_back(ui->label_list3);
	lap_labels_.push_back(ui->label_list4);
	lap_labels_.push_back(ui->label_list5);
	lap_labels_.push_back(ui->label_list6);
	lap_labels_.push_back(ui->label_list7);
	lap_labels_.push_back(ui->label_list8);
	lap_labels_.push_back(ui->label_list9);
	

	// TODO
	// TimeSave
}

void MainWindow::connected()
{
	if (qtimer_ == nullptr) 
	{
		qtimer_ = new QTimer(this);
	}

	connect(qtimer_, &QTimer::timeout, this, &MainWindow::slot_start_timer);
	qtimer_->setInterval(1000); 
	qtimer_->start();

	connect(ui->StartButton, &QPushButton::clicked, this, &MainWindow::slot_start);
	connect(ui->StopResetButton, &QPushButton::clicked, this, &MainWindow::slot_stop_reset);
	connect(ui->LapButton, &QPushButton::clicked, this, &MainWindow::slot_lap);
	connect(ui->SetTimerButton, &QPushButton::clicked, this, &MainWindow::slot_set_timer);
}

void MainWindow::slot_start()
{
	started_ = true;   
}

void MainWindow::slot_stop_reset()
{
	if (started_)
	{
		started_ = false;
	}
	else
	{
		elapsed_seconds_ = 0;
		current_time_ = "00 : 00 : 00";
		target_time_ = "00 : 00 : 00";

		update_display();
	}
}

void MainWindow::slot_lap()
{
	if (!started_)
	{
		return;
	}

	lap_labels_[lap_count_ % 10]->setText(current_time_);
	++lap_count_;
}

void MainWindow::slot_set_timer()
{
	if (target_time_dialog_ == nullptr)
	{
		target_time_dialog_ = new TargetTimeDialog(this);
		connect(target_time_dialog_, &TargetTimeDialog::accepted, this, [this]() {
			target_time_ = target_time_dialog_->target_time();
			ui->TargetTime->setText(target_time_);
		});
	}

	target_time_dialog_->show();
	if (target_time_dialog_->exec() == QDialog::Accepted)
	{
		target_time_ = target_time_dialog_->target_time();
		ui->TargetTime->setText(target_time_);
	}
}

void MainWindow::update_display()
{
	current_time_ = QTime(0,0).addSecs(elapsed_seconds_).toString("hh : mm : ss");
	ui->CurrentTime->setText(current_time_);
}

void MainWindow::check_stopwatch()
{
	if (target_time_ == "00 : 00 : 00")
	{
		// No target time set, do nothing
		return;
	}

	if (current_time_ == target_time_)
	{
		// Stopwatch reached the target time
		// TODO
		// For example, you can show a sound
		started_ = false;
	}
	else if (QTime::fromString(current_time_, "hh : mm : ss") > QTime::fromString(target_time_, "hh : mm : ss"))
	{
		// Stopwatch exceeded the target time
		// TODO
		// For example, you can show a sound
		started_ = false;
	}
}

void MainWindow::slot_start_timer()
{
	QString current_local_time = QTime::currentTime().toString("hh : mm : ss");
	ui->CurrentLocalTime->setText("Time: [" + current_local_time + "]");

	if (!started_)
	{
		return;
	}

	++elapsed_seconds_;
	update_display();
	check_stopwatch();
}
