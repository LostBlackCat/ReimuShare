#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QTreeWidget>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    void init();
    void updateParentItem(QTreeWidgetItem* item);

private slots:
  void on_CountBtn_clicked();

  void on_radiusLineEdit_textChanged(const QString &arg1);

  //Try another
  void showArea();
    void treeItemChanged(QTreeWidgetItem *Item,int column);
private:
    Ui::Dialog *ui;
    //Another try;
    QLabel *label1,*label2;
    QLineEdit *lineEdit;
    QPushButton *button;
};

#endif // DIALOG_H
