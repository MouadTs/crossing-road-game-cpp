#ifndef RETRYDIALOG_H
#define RETRYDIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>

class RetryDialog : public QDialog {
    Q_OBJECT

public:
    RetryDialog(QWidget *parent = nullptr);
    ~RetryDialog();

    enum Result {
        Retry,
        Quit
    };

private slots:
    void retryClicked();
    void quitClicked();

private:
    QVBoxLayout *layout;
    QPushButton *retryButton;
    QPushButton *quitButton;
};

#endif // RETRYDIALOG_H
