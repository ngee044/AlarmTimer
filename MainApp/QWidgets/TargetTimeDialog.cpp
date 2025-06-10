#include "TargetTimeDialog.h"
#include "ui_TargetTimeDialog.h"


TargetTimeDialog::TargetTimeDialog(QWidget *parent)
	: QDialog(parent),
	ui(new Ui::TargetTimeDialog)
{
	ui->setupUi(this);

	initialize();
	connected();
}

TargetTimeDialog::~TargetTimeDialog()
{
	delete ui;
}

void TargetTimeDialog::initialize()
{
	ui->HourBox->setRange(0, 99);
	ui->MinBox->setRange(0, 59);
	ui->SecBox->setRange(0, 59);
}

void TargetTimeDialog::connected()
{
	connect(ui->AcceptButton, &QPushButton::clicked, this, [this]() {
		int hours = ui->HourBox->value();
		int minutes = ui->MinBox->value();
		int seconds = ui->SecBox->value();
		
		target_time_ = QTime(hours, minutes, seconds).toString("hh : mm : ss");
		
		accept();
	});

	connect(ui->CloseButton, &QPushButton::clicked, this, &TargetTimeDialog::reject);
	connect(ui->ResetButton, &QPushButton::clicked, this, [this]() {
		ui->HourBox->setValue(0);
		ui->MinBox->setValue(0);
		ui->SecBox->setValue(0);

		target_time_ = "00 : 00 : 00";
	});
}

