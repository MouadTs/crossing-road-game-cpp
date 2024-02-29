#include "retrydialog.h"
#include <QStyle>
#include <QLabel>
#include <QFont>

RetryDialog::RetryDialog(QWidget *parent) : QDialog(parent) {
    layout = new QVBoxLayout(this);

    // Increase size
    setFixedSize(300, 200);

    // Set background color
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window, Qt::cyan);  // Use QPalette::Window instead of QPalette::Background
    setAutoFillBackground(true);
    setPalette(palette);

    // Add QLabel with the message
    QLabel *messageLabel = new QLabel("Ooopps , You lost !!", this);
    messageLabel->setAlignment(Qt::AlignCenter);
    messageLabel->setStyleSheet("font-size: 26px; color: black;"); // Adjust font size and color as needed
    messageLabel->setFont(QFont("Impact", 18));

    retryButton = new QPushButton("Quit", this);
    quitButton = new QPushButton("Try again", this);

    // Apply a style to buttons (you can customize this)
    retryButton->setStyleSheet("background-color: red; color: white;");
    quitButton->setStyleSheet("background-color: green; color: white;");

    connect(retryButton, SIGNAL(clicked()), this, SLOT(retryClicked()));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(quitClicked()));

    layout->addWidget(messageLabel);
    layout->addWidget(retryButton);
    layout->addWidget(quitButton);

    setLayout(layout);
}

RetryDialog::~RetryDialog() {}

void RetryDialog::retryClicked() {
    accept();
}

void RetryDialog::quitClicked() {
    reject();
}
