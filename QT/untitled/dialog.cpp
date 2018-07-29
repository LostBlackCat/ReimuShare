#include "dialog.h"
#include "ui_dialog.h"
#include<QGridLayout>
const static double PI=3.14159;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    //Another try
    label1=new QLabel("&Calculator",this);
    //label1->setText(tr("显示对应圆的面积"));
    lineEdit=new QLineEdit(this);
    label2 =new QLabel(this);
    button =new QPushButton(this);
    button->setText((tr("显示对应圆的面积")));
    label1->setBuddy(lineEdit);
    connect(lineEdit,SIGNAL(textChanged(QString)),button,SLOT(click()));
    connect(button,SIGNAL(clicked(bool)),lineEdit,SIGNAL(textChanged(QString)));
    QGridLayout *mainLayout=new QGridLayout(this);

    //Another try;
    mainLayout->addWidget(label1,0,0);
    mainLayout->addWidget(lineEdit,0,1);
    mainLayout->addWidget(label2,1,0);
    mainLayout->addWidget(button,1,1);
    connect(button,SIGNAL(clicked()),this,SLOT(showArea()));

    init();
    connect(ui->treeWidget,SIGNAL(it))
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_CountBtn_clicked()
{
    bool ok;
    QString tempStr;
    QString valueStr=ui->radiusLineEdit->text();
    int valueInt=valueStr.toInt(&ok);
    double area=valueInt*valueInt*PI;
    //Caluclating circle's area;
    ui->areaLabel_2->setText(tempStr.setNum(area));
}

void Dialog::on_radiusLineEdit_textChanged(const QString &arg1)
{
  bool ok;
  QString tempStr;
  QString valueStr=ui->radiusLineEdit->text();
  int valueInt=valueStr.toInt(&ok);
  double area=valueInt*valueInt*PI;
  //Caluclating circle's area;
  ui->areaLabel_2->setText(tempStr.setNum(area));
}

//Another try
void Dialog::showArea()
{
  bool ok;
  QString tempStr;
  QString valueStr=lineEdit->text();
  int valueInt=valueStr.toInt(&ok);
  double area=valueInt*valueInt*PI;
  //Caluclating circle's area;
  label2->setText(tempStr.setNum(area));
}
