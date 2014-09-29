#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settingshelper.h"
#include <QSettings>
#include <QMessageBox>
/*
 * http://qt-project.org/wiki/Threads_Events_QObjects
 * http://mayaposch.wordpress.com/2011/11/01/how-to-really-truly-use-qthreads-the-full-explanation/
 * http://habrahabr.ru/post/150274/
 */



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create instances
    myValueDialog = new SingleValueDialog(this);
    mySettingsDialog = new SettingsDialog(this);
    serialPort = new QSerialPort(this);
    serialStatusLabel = new QLabel(this);
    ui->statusBar->addWidget(serialStatusLabel);
    worker = new SerialWorker();

    // Setup signals
    //connect(ui->actionConnect, SIGNAL(triggered()), this, SLOT(openSerialPort()));
    //connect(ui->actionDisconnect, SIGNAL(triggered()), this, SLOT(closeSerialPort()));
    connect (ui->actionSettings, SIGNAL(triggered()), mySettingsDialog, SLOT(exec()));

    connect(ui->setVoltageBtn, SIGNAL(clicked()), this, SLOT(on_SetVoltageCommand()));
    connect(ui->setCurrentBtn, SIGNAL(clicked()), this, SLOT(on_SetCurrentCommand()));


    // Sync value cache
    memset(&vcache, 0, sizeof(vcache));
    updateVset(vcache.vset);
    updateVmea(vcache.vmea);
    updateCset(vcache.cset);
    updateCmea(vcache.cmea);

    // Default widgets state
    ui->actionDisconnect->setEnabled(false);
    serialStatusLabel->setText("Disconnected");

    // Make sure all settings are valid
    if (SettingsHelper::validateSettings() == false)
    {
        // Show messagebox!
        QMessageBox::information(this, "Information", "Some setting values are missing or corrupted. Defaults are loaded.", QMessageBox::Ok);
    }

    // Start second thread
    worker->start(QThread::IdlePriority);
}

MainWindow::~MainWindow()
{
    appSettings.sync();
    delete ui;
}




//-------------------------------------------------------//
/// @brief Updates measured voltage
/// @param[in] value - voltage [mV]
/// @note Also updates value cache
/// @return none
//-------------------------------------------------------//
void MainWindow::updateVmea(int value)
{
    QString str;
    str.sprintf("%1.2fV", (double)value/1000);
    ui->label_vmea->setText(str);
    vcache.vmea = value;
}

//-------------------------------------------------------//
/// @brief Updates measured current
/// @param[in] value - current [mA]
/// @note Also updates value cache
/// @return none
//-------------------------------------------------------//
void MainWindow::updateCmea(int value)
{
    QString str;
    str.sprintf("%1.2fA", (double)value/1000);
    ui->label_cmea->setText(str);
    vcache.cmea = value;
}

//-------------------------------------------------------//
/// @brief Updates voltage setting
/// @param[in] value - voltage [mV]
/// @note Also updates value cache
/// @return none
//-------------------------------------------------------//
void MainWindow::updateVset(int value)
{
    QString str;
    str.sprintf("%1.2fV", (double)value/1000);
    ui->label_vset->setText(str);
    vcache.vset = value;
}

//-------------------------------------------------------//
/// @brief Updates current setting
/// @param[in] value - current [mA]
/// @note Also updates value cache
/// @return none
//-------------------------------------------------------//
void MainWindow::updateCset(int value)
{
    QString str;
    str.sprintf("%1.2fA", (double)value/1000);
    ui->label_cset->setText(str);
    vcache.cset = value;
}



void MainWindow::on_SetVoltageCommand(void)
{
    myValueDialog->SetText("Set voltage", "New value:", "V");
    myValueDialog->SetMaxMinValues(0, 20000);
    myValueDialog->SetValue(vcache.vset);
    myValueDialog->exec();  // modal
    if (myValueDialog->result() == QDialog::Accepted)
    {
        // Temporary
        updateVset(myValueDialog->GetValue());
        updateVmea(vcache.vset);
    }
}

void MainWindow::on_SetCurrentCommand(void)
{
    myValueDialog->SetText("Set current", "New value:", "A");
    myValueDialog->SetMaxMinValues(0, 40000);
    myValueDialog->SetValue(vcache.cset);
    myValueDialog->exec();  // modal
    if (myValueDialog->result() == QDialog::Accepted)
    {
        // Temporary
        updateCset(myValueDialog->GetValue());
        updateCmea(vcache.cset);
    }
}

